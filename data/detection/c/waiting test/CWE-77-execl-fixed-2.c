#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void dummy_string_process(const char* str) {
    int len = strlen(str);
    printf("String length: %d\n", len);
}

void execute_command(const char* user_input) {
    // CWE-77: 命令注入漏洞，直接使用用户输入执行命令
    execl("/bin/sh", "sh", "-c", user_input, NULL);
}

int is_input_safe(const char* input) {
    // 简单的白名单检查，只允许字母和数字
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i]) && input[i] != ' ') {
            return 0; // 不安全的输入
        }
    }
    return 1; // 安全的输入
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    dummy_string_process(argv[1]);

    // 在调用 execute_command 之前进行输入验证
    if (is_input_safe(argv[1])) {
        execute_command(argv[1]);
    } else {
        printf("Error: Unsafe command input detected.\n");
    }
    return 0;
}