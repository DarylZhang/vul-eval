def dummy_processing(data):
    reversed_data = data[::-1]
    print(f"Reversed Input: {reversed_data}")

def perform_calculation(num):
    result = num * 10
    print(f"Calculation result: {result}")

def process_user_input(user_input):
    dummy_processing(user_input)
    num = int(user_input)
    print(f"You entered: {num}")
    perform_calculation(num)

def main():
    while True:
        user_input = input("Enter an integer: ")
        if user_input.isdigit() or (user_input.startswith('-') and user_input[1:].isdigit()):
            process_user_input(user_input)
            break
        else:
            print("Invalid input. Please enter a valid integer.")

if __name__ == "__main__":
    main()