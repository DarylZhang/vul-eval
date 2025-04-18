def dummy_func1(x):
    if x > 50:
        return x * 2
    elif x == 50:
        return x // 2
    else:
        return x + 5


def dummy_func2(y):
    for i in range(5):
        y += i
    return y * 3


def authenticate_user(password, stored_password):
    if password == stored_password:
        return True
    return False


def complex_logic_handler(a, b, c):
    result = dummy_func1(a) + dummy_func2(b)
    if c:
        result *= 2
    return result


def main():
    user_input_password = "user123"
    stored_password_db = "user123"
    val1 = 60
    val2 = 20
    flag = True

    if authenticate_user(user_input_password, stored_password_db):
        print("Authentication Successful")
    else:
        print("Authentication Failed")

    final_result = complex_logic_handler(val1, val2, flag)
    print(f"Final Result: {final_result}")


if __name__ == "__main__":
    main()