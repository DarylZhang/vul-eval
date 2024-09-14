#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

    //CWE-269
    execl("/bin/sh", "sh", "-c", cmd, NULL);
}

int main() {
    int flag = 1;
    const char *command = "ls -la";

    execute_command(command, flag);
    return 0;
}