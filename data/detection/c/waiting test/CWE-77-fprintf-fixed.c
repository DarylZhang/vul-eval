#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dummy_multiply(int a, int b) {
    return a * b;
}

void execute_command(const char* user_input) {
    // 在函数中直接进行输入验证，使用简单的白名单策略
    const char* allowed_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,!?-_";
    size_t input_length = strlen(user_input);

    for (size_t i = 0; i < input_length; i++) {
        if (strchr(allowed_chars, user_input[i]) == NULL) {
            printf("Error: Unsafe input detected.\n");
            return;
        }
    }

    FILE *fp = fopen("script.sh", "w");
    if (fp == NULL) {
        printf("Failed to create script\n");
        return;
    }

    // 修复 CWE-77 漏洞：仅在输入验证通过后才使用用户输入
    fprintf(fp, "echo \"%s\"\n", user_input);
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

    execute_command(argv[1]);
    return 0;
}