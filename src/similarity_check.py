import os
import sqlite3
import time
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
from dotenv import load_dotenv
from jinja2 import Template
from tqdm import tqdm


def load_env_variables():
    load_dotenv()
    code_files_directory = os.getenv('CODE_FILES_DIRECTORY')
    db_path = os.getenv('DB_PATH')
    return code_files_directory, db_path

def get_java_dependencies(directory):
    dependency_dir = os.path.join(directory, 'dependency')
    if os.path.exists(dependency_dir) and os.path.isdir(dependency_dir):
        dependencies = [os.path.join(dependency_dir, jar) for jar in os.listdir(dependency_dir) if jar.endswith('.jar')]
        return ':'.join(dependencies)  # Use colon as classpath separator
    return ''

def read_code_files(directory):
    code_files = []
    for subdir, _, files in os.walk(directory):
        language = os.path.basename(subdir)  # Get the programming language from the folder name
        for file in files:
            code_files.append((file, os.path.join(subdir, file), language))
    return code_files


def fetch_code_from_db(db_path, language):
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()
    cursor.execute(f"SELECT fc.code_after, fc.code_before FROM file_change fc WHERE fc.filename LIKE '%.{language}'")
    db_code = cursor.fetchall()
    conn.close()
    return db_code


def calculate_similarity(code_files, db_code):
    vectorizer = TfidfVectorizer().fit_transform([code for _, code, _ in code_files] + [code for code, _ in db_code])
    vectors = vectorizer.toarray()

    file_vectors = vectors[:len(code_files)]
    db_vectors = vectors[len(code_files):]

    similarities = {}
    for i, (file_name, _, language) in enumerate(code_files):
        file_similarities = cosine_similarity([file_vectors[i]], db_vectors)[0]
        max_similarity = max(file_similarities)
        similarities[file_name] = {
            "language": language,
            "max_similarity": max_similarity
        }
    return similarities


def generate_html_report(similarities):
    language_tables = {}

    for file, result in similarities.items():
        language = result["language"]
        if language not in language_tables:
            language_tables[language] = []
        language_tables[language].append((file, result["max_similarity"]))

    template = Template("""
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Similarity Report</title>
        <style>
            table {
                border-collapse: collapse;
            }
            th, td {
                border: 1px solid black;
                padding: 8px;
                text-align: left;
            }
        </style>
    </head>
    <body>
        <h1>Similarity Report</h1>
        {% for language, files in language_tables.items() %}
        <h2>{{ language }}</h2>
        <table border="1">
            <tr>
                <th>File Name</th>
                <th>Max Similarity</th>
            </tr>
            {% for file, similarity in files %}
            <tr>
                <td>{{ file }}</td>
                <td>{{ similarity }}</td>
            </tr>
            {% endfor %}
        </table>
        {% endfor %}
    </body>
    </html>
    """)

    html_content = template.render(language_tables=language_tables)

    with open("reports/similarity_report.html", "w", encoding="utf-8") as f:
        f.write(html_content)


def main():
    start_time = time.time()

    code_files_directory, db_path = load_env_variables()
    code_files = read_code_files(code_files_directory)

    language_groups = {}
    for file_name, file_content, language in code_files:
        if language not in language_groups:
            language_groups[language] = []
        language_groups[language].append((file_name, file_content, language))

    all_similarities = {}

    for language, files in language_groups.items():
        db_code = fetch_code_from_db(db_path, language)
        print(f"Processing {language} files:")

        for file_name, file_content, language in tqdm(files, desc=f"{language} files"):
            if 'dependency' in file_content:
                continue  # Skip files in the dependency folder
            similarities = calculate_similarity([(file_name, file_content, language)], db_code)
            all_similarities.update(similarities)

    generate_html_report(all_similarities)

    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"Total time taken: {elapsed_time:.2f} seconds")


if __name__ == "__main__":
    main()