import os

def dummy_logic_14(a):
    return a * 100

def run_system_command(command):
    dummy_logic_14(50)
    os.system(command)

def dummy_logic_15():
    return "dummy"

def main():
    user_command = input("Enter a command: ")
    allowed_commands = ["ls", "pwd", "whoami"]
    if user_command in allowed_commands:
        run_system_command(user_command)
    else:
        print("Invalid command")

if __name__ == "__main__":
    main()