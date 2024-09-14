#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *allowed_commands[] = {"ls", "pwd", "whoami", NULL};

void execute_command(const char *command) {
    printf("Executing safe command: %s\n", command);
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    int is_valid_command = 0;
    for (int i = 0; allowed_commands[i] != NULL; i++) {
        if (strcmp(argv[1], allowed_commands[i]) == 0) {
            is_valid_command = 1;
            break;
        }
    }

    if (!is_valid_command) {
        printf("Command rejected: %s\n", argv[1]);
        return 1;
    }

    execute_command(argv[1]);

    return 0;
}