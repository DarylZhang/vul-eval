import glob
import os
import subprocess
import sys
import time
import json
import csv

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
        '--language=' + 'c-cpp', '--source-root', source_directory, '--overwrite'
    ]

    if language == 'csharp' or language == 'java':
        command.extend(['--build-mode=none'])
    elif language == 'c' or language == 'cpp':
        command.extend(['--command=make'])

    print(f"Running command: {' '.join(command)}")

    try:
        subprocess.run(command, check=True, text=True, capture_output=True)

        print('Database creation successful')
        # clean_compiled_files(source_directory, language)

    except subprocess.CalledProcessError as e:
        print(f"Error creating database for {language}: {e.stderr}")
        sys.exit(1)

def finalize_codeql_database(codeql_binary_path, database_directory, language):
    command = [codeql_binary_path, 'database', 'finalize', database_directory]

    print(f"Running command: {' '.join(command)}")

    try:
        subprocess.run(command, check=True, text=True, capture_output=True)
        print('Database finalized successfully')

    except subprocess.CalledProcessError as e:
        print(f"Error finalizing database for {language}: {e.stderr}")
        sys.exit(1)

def run_codeql_suite(codeql_binary_path, codeql_repo_path, database_directory, language, output_file):

    if language in ['c', 'cpp']:
        # suite_path = os.path.join(codeql_repo_path, 'cpp', 'ql', 'src', 'codeql-suites', 'cpp-security-extended.qls')
        suite_path = os.path.join('/Users/darylzhang/Documents/workspaces/phd/codeql/cpp/ql/src/Likely Bugs', 'RedundantNullCheckSimple.ql')
    else:
        suite_path = os.path.join(codeql_repo_path, language, 'ql', 'src', 'codeql-suites', f'{language}-security-extended.qls')

    command = [
        codeql_binary_path, 'database', 'analyze', database_directory, suite_path,
        '--format=sarif-latest', '--output', output_file

    ]

    print(f"Running analyze command: {' '.join(command)}")

    try:
        subprocess.run(command, check=True, text=True, capture_output=True)
        return f'Query suite execution successful for {language}'
    except subprocess.CalledProcessError as e:
        print(f"Error running query suite for {language}: {e.stderr}")
        sys.exit(1)

# def clean_compiled_files(source_directory, language):
#     try:
#         os.chdir(source_directory)
#
#         if language == 'c' or language == 'cpp':  # C and C++
#             subprocess.run(['make', 'clean'], check=True)
#             print("Cleaned up C/C++ compiled files using make clean.")
#
#         elif language == 'csharp':  # C#
#             compiled_files = glob.glob('*.exe') + glob.glob('*.dll')
#             for file in compiled_files:
#                 os.remove(file)
#                 print(f"Deleted file: {file}")
#
#         elif language == 'java':  # Java
#             compiled_files = glob.glob('**/*.class', recursive=True)
#             for file in compiled_files:
#                 os.remove(file)
#                 print(f"Deleted file: {file}")
#
#         # codeql_detected_folder = os.path.join(source_directory, '_codeql_detected_source_root')
#         # if os.path.exists(codeql_detected_folder):
#         #     subprocess.run(['rm', '-rf', codeql_detected_folder], check=True)
#         #     print(f"Deleted CodeQL detected source root folder: {codeql_detected_folder}")
#
#         # Delete all other compiled files
#         other_files = glob.glob('*')
#         for file in other_files:
#             if os.path.isfile(file) and not file.endswith('.c') and not file.endswith('.c') and not file.endswith(
#                     '.cs') and not file.endswith('.java') and not file.endswith('Makefile'):
#                 os.remove(file)
#                 print(f"Deleted file: {file}")
#
#     except Exception as e:
#         print(f"Error cleaning up compiled files for {language}: {e}")

def extract_cwe_id(tags):
    """
    Extract CWE-ID from tags.
    """
    for tag in tags:
        if tag.startswith('external/cwe/cwe-'):
            return tag.split('-')[-1]
    return 'No CWE-ID available'


def process_json_file(json_file_path):
    # Load SARIF file
    with open(json_file_path, 'r') as file:
        sarif_data = json.load(file)

    # Dictionary to hold CWEs per file
    file_cwe_map = {}

    # Process each run in the SARIF file
    for run in sarif_data.get('runs', []):
        rules = {
            rule['id']: {
                'description': rule.get('shortDescription', {}).get('text', 'No description available'),
                'cwe': extract_cwe_id(rule.get('properties', {}).get('tags', []))
            } for rule in run.get('tool', {}).get('driver', {}).get('rules', [])
        }

        for result in run.get('results', []):
            rule_id = result.get('ruleId')
            message = result.get('message', {}).get('text', 'No message available')

            if result.get('locations'):
                location = result['locations'][0]
                uri = location['physicalLocation']['artifactLocation'].get('uri')
                region = location['physicalLocation'].get('region', {})
                start_line = region.get('startLine')
                start_column = region.get('startColumn')
                end_column = region.get('endColumn')

                location_str = f'line {start_line}, column {start_column}-{end_column}'

                # Get CWE-ID from the rules information
                cwe_id = rules[rule_id]['cwe']

                if uri not in file_cwe_map:
                    file_cwe_map[uri] = {'cwes': set(), 'messages': [], 'rule_ids': set(), 'locations': []}

                file_cwe_map[uri]['cwes'].add('CWE-' + cwe_id)  # Add the CWE-ID to the set for that file
                file_cwe_map[uri]['messages'].append(message)
                file_cwe_map[uri]['rule_ids'].add(rule_id)
                file_cwe_map[uri]['locations'].append(location_str)

    # Prepare the data to be returned
    summarized_data = []

    for filename, data in file_cwe_map.items():
        summarized_data.append({
            'filename': filename,
            'CWE': ', '.join(data['cwes']),
            'no of vul': len(data['cwes']),
            'rule': ', '.join(data['rule_ids']),
            'message': ' '.join(data['messages']),
            'locations': '; '.join(data['locations'])
        })

    return summarized_data

def main():
    # Load environment variables
    code_files_directory, codeql_binary_path, codeql_repo_path = load_env_variables()

    # Create the codeql-database folder if it doesn't exist
    # os.makedirs('codeql-database', exist_ok=True)

    # Supported languages
    supported_languages = {
        'c': 'c'
        # 'cpp': 'cpp'
        # 'csharp': 'csharp',
        # 'java': 'java'
        # 'python': 'python'
    }

    for folder_name, language in supported_languages.items():
        source_directory = os.path.join(code_files_directory, folder_name)
        if os.path.exists(source_directory):
            print(f"Processing {language} files in {folder_name} folder...")



            # Define the database directory for this language
            database_directory = os.path.join('codeql/codeql-database', folder_name)

            rm_command = ['rm', '-rf', database_directory]
            subprocess.run(rm_command, check=True, capture_output=True)

            os.makedirs(database_directory, exist_ok=True)

            # Create the CodeQL database
            result_db_creation = create_codeql_database(codeql_binary_path, source_directory, database_directory, language)
            print(result_db_creation)

            # Run database finalize
            # result_db_finalization = finalize_codeql_database(codeql_binary_path, database_directory, language)
            # print(result_db_finalization)

            # Define the output SARIF file within the respective database directory
            output_file = os.path.join(database_directory, f'{folder_name}-codeql-results.sarif')
            os.makedirs(os.path.dirname(output_file), exist_ok=True)

            # Run the CodeQL query suite
            result_query_execution = run_codeql_suite(codeql_binary_path, codeql_repo_path, database_directory,
                                                      language, output_file)
            print(result_query_execution)

            process_json_file(output_file)

if __name__ == "__main__":
    main()
