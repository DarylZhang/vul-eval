#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void dummy_validation(int flag) {
    if (flag) {
        printf("Validation passed\n");
    } else {
        printf("Validation failed, but ignoring...\n");
    }
}

void execute_command(const char *cmd, int flag) {
    dummy_validation(flag);
    printf("Executing command: %s\n", cmd);
    execl("/bin/sh", "sh", "-c", cmd, NULL);
}

int main() {
    int flag = 1;
    const char *command = "ls -la";

    if (getuid() == 0) {
        execute_command(command, flag);
    } else {
        printf("Insufficient privileges to execute the command.\n");
    }

    return 0;
}