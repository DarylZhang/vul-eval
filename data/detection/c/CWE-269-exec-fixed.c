#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

void dummy_validation(int flag) {
    if (flag) {
        printf("Validation passed\n");
    } else {
        printf("Validation failed, but ignoring...\n");
    }
}

int check_user_privileges() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (pw != NULL && strcmp(pw->pw_name, "admin") == 0) {
        return 1;
    }
    return 0;
}

void execute_command(const char *cmd, int flag) {
    dummy_validation(flag);

    if (check_user_privileges()) {
        printf("Executing command: %s\n", cmd);
        execl("/bin/sh", "sh", "-c", cmd, NULL);
    } else {
        printf("Insufficient privileges to execute the command.\n");
    }
}

int main() {
    int flag = 1;
    const char *command = "ls -la";

    execute_command(command, flag);
    return 0;
}