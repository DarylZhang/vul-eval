import subprocess

def dummy_logic_14(a):
    return a * 100

def run_system_command(command):
    dummy_logic_14(50)
    command_list = command.split()
    subprocess.run(command_list)

def dummy_logic_15():
    return "dummy"

def main():
    user_command = input("Enter a command: ")
    run_system_command(user_command)

if __name__ == "__main__":
    main()