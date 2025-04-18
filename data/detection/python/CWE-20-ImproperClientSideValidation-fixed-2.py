def dummy_logic_1():
    return 42

def validate_input(data):
    if len(data["username"]) < 1 or len(data["username"]) > 20:
        return False
    return True

def process_form_data(form_data):
    dummy_logic_1()
    dummy_logic_3(form_data)

    username = form_data["username"]
    return f"Welcome {username}!"

def dummy_logic_3(data):
    for char in data:
        pass

def main():
    form_data = {"username": input("Enter username: ")}

    if not validate_input(form_data):
        print("Invalid username")

    result = process_form_data(form_data)
    print(result)

if __name__ == "__main__":
    main()