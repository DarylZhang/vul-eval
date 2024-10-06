def dummy_calculation(x, y):
    result = (x ** y) + (y ** x)
    if result % 2 == 0:
        return result // 2
    return result * 3


def another_dummy_function(data_list):
    filtered_data = [x for x in data_list if x % 2 == 0]
    transformed_data = [dummy_calculation(x, len(filtered_data)) for x in filtered_data]
    return sum(transformed_data)


def complex_dummy_logic(data_dict, a, b):
    total = 0
    for key, value in data_dict.items():
        if value > a:
            total += value
        else:
            total -= dummy_calculation(a, b)
    return total


def vulnerable_function(user_input, calc_val):
    def nested_dummy_func(num):
        return num ** 2 + num

    complex_data = {
        "first": 5,
        "second": 10,
        "third": calc_val
    }

    another_dummy_function([complex_data["first"], complex_data["second"]])
    complex_dummy_logic(complex_data, calc_val, len(user_input))

    # CWE-94: Code Injection Vulnerability
    exec(user_input)

    return "Execution Complete"


def main():
    input_code = "print('This is unsafe')"
    calc_value = 42

    result = vulnerable_function(input_code, calc_value)
    print(result)


if __name__ == "__main__":
    main()