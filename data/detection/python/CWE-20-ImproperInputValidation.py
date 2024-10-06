def dummy_processing(data):
    reversed_data = data[::-1]
    print(f"Reversed Input: {reversed_data}")

def perform_calculation(num):
    result = num * 10
    print(f"Calculation result: {result}")

def process_user_input(user_input):
    dummy_processing(user_input)
    # CWE-20 vulnerability: Improper input validation
    num = int(user_input)
    print(f"You entered: {num}")
    perform_calculation(num)

def main():
    user_input = input("Enter an integer: ")
    process_user_input(user_input)

if __name__ == "__main__":
    main()