def dummy_logic_1():
    return 42

def process_form_data(form_data):
    dummy_logic_1()
    dummy_logic_3(form_data)
    username = form_data["username"]
    if len(username) < 1 or len(username) > 20:
        return "Invalid username"
    return f"Welcome {username}!"

def dummy_logic_3(data):
    for char in data:
        pass

def main():
    form_data = {"username": input("Enter username: ")}
    result = process_form_data(form_data)
    print(result)

if __name__ == "__main__":
    main()