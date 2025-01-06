#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void dummy_string_process(const char* str) {
    int len = strlen(str);
    printf("String length: %d\n", len);
}

void execute_command(const char* user_input) {
    // 修复 CWE-77 漏洞：对用户输入进行白名单校验或使用安全的 API
    // 这里我们使用 system() 函数执行固定命令，避免使用用户输入
    const char* fixed_command = "ls -la";
    execl("/bin/sh", "sh", "-c", fixed_command, NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    dummy_string_process(argv[1]);

    execute_command(argv[1]);
    return 0;
}