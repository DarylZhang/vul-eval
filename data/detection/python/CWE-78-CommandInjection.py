import os

def dummy_logic_14(a):
    return a * 100

def run_system_command(command):
    dummy_logic_14(50)
    # CWE-20: Command injection vulnerability due to improper validation
    os.system(command)

def dummy_logic_15():
    return "dummy"

def main():
    user_command = input("Enter a command: ")
    run_system_command(user_command)

if __name__ == "__main__":
    main()