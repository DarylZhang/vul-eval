def dummy_logic_12(a, b):
    return a * b

def process_data(data):
    dummy_logic_12(10, 20)
    if isinstance(data, str):
        print(f"Processing data: {data.upper()}")
    else:
        print("Invalid data type")

def dummy_logic_13():
    return [1, 2, 3]

def main():
    user_input = input("Enter data: ")
    process_data(user_input)

if __name__ == "__main__":
    main()