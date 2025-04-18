import os


def helper_function_A(a, b):
    result = a * b
    if result > 10:
        return another_dummy_function(result)
    return dummy_logic_1(result)


def dummy_logic_1(x):
    return x + 10


def another_dummy_function(y):
    value = dummy_logic_2(y) - 3
    return value


def dummy_logic_2(z):
    return z * 2


def complex_function_with_path(file_path, some_value, additional_data):
    dummy_result = helper_function_A(some_value, additional_data)

    processed_data = dummy_result % 3
    if processed_data == 0:
        final_step = dummy_logic_3(file_path)
    else:
        final_step = dummy_logic_4(file_path, dummy_result)

    return final_step


def dummy_logic_3(p):
    return len(p) + 10


def dummy_logic_4(p, q):
    if q > 20:
        return len(p) * 2
    else:
        return len(p) - 5


def actual_fixed_function(user_input_file):
    base_directory = "/app/data/"

    normalized_path = os.path.normpath(os.path.join(base_directory, user_input_file))
    if not normalized_path.startswith(base_directory):
        return "Invalid file path"

    full_path = normalized_path
    if os.path.exists(full_path):
        with open(full_path, 'r') as file:
            content = file.read()
        return content
    return "File not found"


def main():
    file_input = "../etc/passwd"
    value_to_process = 7
    extra_data = 12

    dummy_output = complex_function_with_path(file_input, value_to_process, extra_data)
    result = actual_fixed_function(file_input)

    print(result)


if __name__ == "__main__":
    main()