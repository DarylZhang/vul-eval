#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void readCommand(const char *command) {
    // 设置 PATH 为一个受信任的固定值
    setenv("PATH", "/usr/bin:/bin", 1);

    // 简单验证：只允许执行 'ls', 'cat' 和 'echo' 等安全命令
    char allowedCommands[][10] = {"ls", "cat", "echo"};
    int allowed = 0;
    for (int i = 0; i < sizeof(allowedCommands)/sizeof(allowedCommands[0]); i++) {
        if (strncmp(command, allowedCommands[i], strlen(allowedCommands[i])) == 0) {
            allowed = 1;
            break;
        }
    }

    if (!allowed) {
        printf("Error: Command not allowed.\n");
        return;
    }

    FILE *fp = popen(command, "r");
    if (fp) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("%s", buffer);
        }
        pclose(fp);
    }
}

void processData() {
    for (int i = 0; i < 5; i++) {
        int num = rand() % 100;
        printf("Processing number: %d\n", num);
    }
}

int main() {
    char command[256];

    printf("Enter a command to execute: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0';

    readCommand(command);
    processData();

    printf("Dummy logic completed.\n");
    return 0;
}