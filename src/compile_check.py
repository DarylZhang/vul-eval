import os
import subprocess
import time
from tqdm import tqdm
from dotenv import load_dotenv
from jinja2 import Template

def load_env_variables():
    load_dotenv()
    code_files_directory = os.getenv('CODE_FILES_DIRECTORY')
    return code_files_directory

def read_code_files(directory):
    code_files = []
    print(os.getcwd())
    for subdir, _, files in os.walk(directory):
        language = os.path.basename(subdir)  # Get the programming language from the folder name
        for file in files:
            code_files.append((file, os.path.join(subdir, file), language))
    return code_files

def get_java_dependencies(directory):
    dependency_dir = os.path.join(directory, 'dependency')
    if os.path.exists(dependency_dir) and os.path.isdir(dependency_dir):
        dependencies = [os.path.join(dependency_dir, jar) for jar in os.listdir(dependency_dir) if jar.endswith('.jar')]
        return ':'.join(dependencies)  # Use colon as classpath separator
    return ''

def compile_code(file_path, language):
    try:
        if language == 'c':
            output_file = file_path + '.out'
            subprocess.run(['gcc', file_path, '-o', output_file], check=True, text=True, capture_output=True)
        elif language == 'cpp':
            output_file = file_path + '.out'
            subprocess.run(['g++', file_path, '-o', output_file, '-std=c++11'], check=True, text=True, capture_output=True)
        elif language == 'csharp':
            output_file = os.path.splitext(file_path)[0] + '.exe'
            subprocess.run(['/Library/Frameworks/Mono.framework/Versions/Current/Commands/mcs', file_path], check=True, text=True, capture_output=True)
        elif language == 'java':
            output_file = os.path.splitext(file_path)[0] + '.class'
            java_classpath = get_java_dependencies(os.path.dirname(file_path))
            if java_classpath:
                subprocess.run(['javac', '-cp', java_classpath, file_path], check=True, text=True, capture_output=True)
            else:
                subprocess.run(['javac', file_path], check=True, text=True, capture_output=True)
        else:
            return 'Not a compilable language'
        return 'Success'
    except subprocess.CalledProcessError as e:
        return f"Error: {e.stderr}"


def clean_up_compiled_files(directory, language):
    for subdir, _, files in os.walk(directory):
        for file in files:
            if (language == 'c' or language == 'cpp') and file.endswith('.out'):
                os.remove(os.path.join(subdir, file))
            elif language == 'csharp' and file.endswith('.exe'):
                os.remove(os.path.join(subdir, file))
            elif language == 'java' and file.endswith('.class'):
                os.remove(os.path.join(subdir, file))


def generate_html_report(compilation_results):
    language_tables = {}

    for file, result in compilation_results.items():
        language = result["language"]
        if language not in language_tables:
            language_tables[language] = []
        language_tables[language].append((file, result["status"]))

    template = Template("""
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Compilation Report</title>
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
        <h1>Compilation Report</h1>
        {% for language, files in language_tables.items() %}
        <h2>{{ language }}</h2>
        <table border="1">
            <tr>
                <th>File Name</th>
                <th>Compilation Status</th>
            </tr>
            {% for file, status in files %}
            <tr>
                <td>{{ file }}</td>
                <td>{{ status }}</td>
            </tr>
            {% endfor %}
        </table>
        {% endfor %}
    </body>
    </html>
    """)

    html_content = template.render(language_tables=language_tables)

    with open("reports/compilation_report.html", "w", encoding="utf-8") as f:
        f.write(html_content)


def main():
    start_time = time.time()

    code_files_directory = load_env_variables()
    code_files = read_code_files(code_files_directory)

    language_groups = {}
    for file_name, file_path, language in code_files:
        if language not in language_groups:
            language_groups[language] = []
        language_groups[language].append((file_name, file_path, language))

    compilation_results = {}

    for language, files in language_groups.items():
        print(f"Processing {language} files:")

        for file_name, file_path, language in tqdm(files, desc=f"{language} files"):
            status = compile_code(file_path, language)
            compilation_results[file_name] = {
                "language": language,
                "status": status
            }

        # Clean up compiled files after processing each language
        clean_up_compiled_files(code_files_directory, language)

    generate_html_report(compilation_results)

    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"Total time taken: {elapsed_time:.2f} seconds")


if __name__ == "__main__":
    main()