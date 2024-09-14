#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *allowed_commands[] = {"ls", "pwd", "whoami", NULL};

int is_command_allowed(const char *command) {
    for (int i = 0; allowed_commands[i] != NULL; i++) {
        if (strcmp(command, allowed_commands[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void execute_command(const char *command) {
    if (is_command_allowed(command)) {
        printf("Executing safe command: %s\n", command);
        system(command);
    } else {
        printf("Command rejected: %s\n", command);
    }
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