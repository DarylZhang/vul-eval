#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dummy_multiply(int a, int b) {
    return a * b;
}

void execute_command(const char* user_input) {
    FILE *fp = fopen("script.sh", "w");
    if (fp == NULL) {
        printf("Failed to create script\n");
        return;
    }

    // CWE-77: 命令注入漏洞，直接使用用户输入构建脚本内容
    fprintf(fp, "echo %s\n", user_input);
    fclose(fp);
    system("sh script.sh");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    int product = dummy_multiply(3, 5);
    printf("Dummy multiplication result: %d\n", product);

    // 在 main() 中进行输入验证
    const char* allowed_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,!?-_";
    size_t input_length = strlen(argv[1]);
    int is_safe = 1;

    for (size_t i = 0; i < input_length; i++) {
        if (strchr(allowed_chars, argv[1][i]) == NULL) {
            is_safe = 0;
            break;
        }
    }

    if (!is_safe) {
        printf("Error: Unsafe input detected.\n");
        return 1;
    }

    execute_command(argv[1]);
    return 0;
}