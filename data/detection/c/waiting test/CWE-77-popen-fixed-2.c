#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//CWE-77: 不修改 readCommand 函数，修复在调用者处确保命令安全
void readCommand(const char *command) {
    // 设置 PATH 为一个受信任的固定值
    setenv("PATH", "/usr/bin:/bin", 1);

    FILE *fp = popen(command, "r"); // CWE-77 存在命令注入风险
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

// 新增：函数用于验证命令是否安全
int isValidCommand(const char *command) {
    // 简单验证：只允许执行 'ls', 'cat' 和 'echo' 等安全命令
    char allowedCommands[][10] = {"ls", "cat", "echo"};
    for (int i = 0; i < sizeof(allowedCommands)/sizeof(allowedCommands[0]); i++) {
        if (strncmp(command, allowedCommands[i], strlen(allowedCommands[i])) == 0) {
            return 1; // 有效
        }
    }
    return 0; // 无效
}

int main() {
    char command[256];

    printf("Enter a command to execute: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0';

    // 修复：在调用前验证命令
    if (isValidCommand(command)) {
        readCommand(command);
    } else {
        printf("Error: Invalid or disallowed command.\n");
    }

    processData();

    printf("Dummy logic completed.\n");
    return 0;
}