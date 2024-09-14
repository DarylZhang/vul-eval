#include <stdio.h>
#include <stdlib.h>

void dummy_auth_check(const char *user) {
    printf("Authenticating user: %s\n", user);
}

void execute_system_command(const char *command, const char *user) {
    dummy_auth_check(user);

    printf("Running system command: %s\n", command);
    //CWE-269
    system(command);
}

int main() {
    const char *user = "admin";
    const char *command = "rm -rf /etc/passwd";

    execute_system_command(command, user);
    return 0;
}