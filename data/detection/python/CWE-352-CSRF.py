import random

def complex_func1(a, b):
    result = a + b
    for i in range(random.randint(1, 10)):
        result *= i
    return result

def complex_func2(x):
    temp = 1
    for i in range(x):
        temp *= i + 1
    return temp

def handle_request(user_token, action_data):
    auth_result = authenticate_user(user_token)
    if auth_result:
        perform_action(action_data)
    else:
        raise Exception("Authentication failed!")

def authenticate_user(token):
    return token == "valid_token"

def perform_action(data):
    if data == "update_profile":
        update_profile()
    elif data == "delete_account":
        delete_account()

def update_profile():
    print("Profile updated")

def delete_account():
    print("Account deleted")

def dummy_func1(x, y, z):
    return complex_func1(x, y) + complex_func2(z)

def main():
    token = "valid_token"
    action = "delete_account"

    dummy_result = dummy_func1(10, 20, 30)
    print(f"Dummy calculation result: {dummy_result}")

    handle_request(token, action)

if __name__ == "__main__":
    main()