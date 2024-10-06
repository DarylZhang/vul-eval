import glob
import os
import subprocess
import time

from dotenv import load_dotenv
from tqdm import tqdm


def load_env_variables():
    load_dotenv()
    code_files_directory = os.getenv('CODE_FILES_DIRECTORY')
    codeql_binary_path = os.getenv('CODEQL_BINARY_PATH', 'codeql')
    codeql_repo_path = os.getenv('CODEQL_REPO_PATH')
    return code_files_directory, codeql_binary_path, codeql_repo_path


def create_codeql_database(codeql_binary_path, source_directory, database_directory, language):
    command = [
        codeql_binary_path, 'database', 'create', database_directory,
        '--language=' + language, '--source-root', source_directory, '--overwrite'
    ]

    print(f"Running command: {' '.join(command)}")

    try:
        # with tqdm(total=100, desc="Creating CodeQL database",
        #           bar_format="{l_bar}{bar} [ time left: {remaining} ]", dynamic_ncols=True, leave=True) as pbar:
        #     process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        #     while True:
        #         output = process.stdout.readline()
        #         if output == '' and process.poll() is not None:
        #             break
        #         if output:
        #             print(output.strip())
        #
        #         pbar.update(10)
        #
        #         time.sleep(1)
        #
        #     pbar.update(100 - pbar.n)
        #
        # return_code = process.poll()
        # if return_code != 0:
        #     raise subprocess.CalledProcessError(return_code, command)

        subprocess.run(command, check=True, text=True, capture_output=True)

        print('Database creation successful')
        # clean_compiled_files(source_directory, language)

    except subprocess.CalledProcessError as e:
        return f"Error creating database for {language}: {e.stderr}"

def finalize_codeql_database(codeql_binary_path, database_directory, language):
    command = [codeql_binary_path, 'database', 'finalize', database_directory]

    print(f"Running command: {' '.join(command)}")

    try:
        subprocess.run(command, check=True, text=True, capture_output=True)
        print('Database finalized successfully')

    except subprocess.CalledProcessError as e:
        return f"Error finalizing database for {language}: {e.stderr}"

def run_codeql_suite(codeql_binary_path, codeql_repo_path, database_directory, language, output_file):
    # 为 C 和 C++ 语言指定同一个路径
    if language in ['c', 'cpp']:
        suite_path = os.path.join(codeql_repo_path, 'cpp', 'ql', 'src', 'codeql-suites', 'cpp-security-extended.qls')
    else:
        suite_path = os.path.join(codeql_repo_path, language, 'ql', 'src', 'codeql-suites', f'{language}-security-extended.qls')

    # if language in ['c', 'c']:
    #     suite_path = os.path.join('../codeql-suites', language, 'security-extended.qls')
    # else:
    #     suite_path = os.path.join('../codeql-suites', language, 'security-extended.qls')

    # suite_path = os.path.join('codeql-suites', language, 'security-extended.qls')

    command = [
        codeql_binary_path, 'database', 'analyze', database_directory, suite_path,
        '--format=sarif-latest', '--output', output_file

    ]

    print(f"Running analyze command: {' '.join(command)}")

    try:
        subprocess.run(command, check=True, text=True, capture_output=True)
        return f'Query suite execution successful for {language}'
    except subprocess.CalledProcessError as e:
        return f"Error running query suite for {language}: {e.stderr}"

def clean_compiled_files(source_directory, language):
    try:
        os.chdir(source_directory)

        if language == 'c':  # C and C++
            subprocess.run(['make', 'clean'], check=True)
            print("Cleaned up C/C++ compiled files using make clean.")

        elif language == 'csharp':  # C#
            compiled_files = glob.glob('*.exe') + glob.glob('*.dll')
            for file in compiled_files:
                os.remove(file)
                print(f"Deleted file: {file}")

        elif language == 'java':  # Java
            compiled_files = glob.glob('**/*.class', recursive=True)
            for file in compiled_files:
                os.remove(file)
                print(f"Deleted file: {file}")

        # codeql_detected_folder = os.path.join(source_directory, '_codeql_detected_source_root')
        # if os.path.exists(codeql_detected_folder):
        #     subprocess.run(['rm', '-rf', codeql_detected_folder], check=True)
        #     print(f"Deleted CodeQL detected source root folder: {codeql_detected_folder}")

        # Delete all other compiled files
        other_files = glob.glob('*')
        for file in other_files:
            if os.path.isfile(file) and not file.endswith('.c') and not file.endswith('.c') and not file.endswith(
                    '.cs') and not file.endswith('.java') and not file.endswith('Makefile'):
                os.remove(file)
                print(f"Deleted file: {file}")

    except Exception as e:
        print(f"Error cleaning up compiled files for {language}: {e}")

def main():
    # Load environment variables
    code_files_directory, codeql_binary_path, codeql_repo_path = load_env_variables()

    # Create the codeql-database folder if it doesn't exist
    os.makedirs('codeql-database', exist_ok=True)

    # Supported languages
    supported_languages = {
        'c': 'c'
        # 'cpp': 'cpp',
        # 'csharp': 'csharp',
        # 'java': 'java',
        # 'python': 'python'
    }

    for folder_name, language in supported_languages.items():
        source_directory = os.path.join(code_files_directory, folder_name)
        if os.path.exists(source_directory):
            print(f"Processing {language} files in {folder_name} folder...")

            # Define the database directory for this language
            database_directory = os.path.join('codeql-database', folder_name)
            os.makedirs(database_directory, exist_ok=True)

            # Create the CodeQL database
            result_db_creation = create_codeql_database(codeql_binary_path, source_directory, database_directory, language)
            print(result_db_creation)

            # Run database finalize
            result_db_finalization = finalize_codeql_database(codeql_binary_path, database_directory, language)
            print(result_db_finalization)

            # Define the output SARIF file within the respective database directory
            output_file = os.path.join(database_directory, f'{folder_name}-codeql-results.sarif')
            os.makedirs(os.path.dirname(output_file), exist_ok=True)

            # Run the CodeQL query suite
            result_query_execution = run_codeql_suite(codeql_binary_path, codeql_repo_path, database_directory,
                                                      language, output_file)
            print(result_query_execution)


if __name__ == "__main__":
    main()
