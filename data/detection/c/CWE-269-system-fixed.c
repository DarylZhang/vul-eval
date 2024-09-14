#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

void dummy_auth_check(const char *user) {
    printf("Authenticating user: %s\n", user);
}

int check_user_privileges() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (pw != NULL && strcmp(pw->pw_name, "admin") == 0) {
        return 1;
    }
    return 0;
}

void execute_system_command(const char *command, const char *user) {
    dummy_auth_check(user);

    if (check_user_privileges()) {
        printf("Running system command: %s\n", command);
        system(command);
    } else {
        printf("Insufficient privileges to run the command.\n");
    }
}

int main() {
    const char *user = "admin";
    const char *command = "rm -rf /etc/passwd";

    execute_system_command(command, user);
    return 0;
}