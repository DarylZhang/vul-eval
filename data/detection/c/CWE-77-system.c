#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_command(const char *command) {
    printf("Executing command: %s\n", command);
    // CWE-77
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char buffer[128];
    strncpy(buffer, argv[1], sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    execute_command(buffer);

    return 0;
}