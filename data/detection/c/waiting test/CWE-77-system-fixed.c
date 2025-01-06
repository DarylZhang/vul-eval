#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_command(const char *command) {
    // 修复 CWE-77 漏洞：只允许执行 "ls" 命令
    if (strcmp(command, "ls") != 0) {
        printf("Error: Only 'ls' command is allowed.\n");
        return;
    }

    printf("Executing command: %s\n", command);
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