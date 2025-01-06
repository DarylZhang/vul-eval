#include <stdio.h>
#include <string.h>

void copy_string(char *src) {
    char buffer[10];

    int dummy_logic = 0;
    for (int i = 0; i < 5; i++) {
        dummy_logic += i * 2;
    }

    // CWE-125: 可能发生越界读取和写入
    strcpy(buffer, src);
    printf("Copied string: %s\n", buffer);
}

int main() {
    char large_string[30] = "This is a very long string.";

    // 在 main 函数中修复 CWE-125 漏洞：对传入的字符串进行截断
    char safe_string[10];
    strncpy(safe_string, large_string, sizeof(safe_string) - 1);
    safe_string[sizeof(safe_string) - 1] = '\0';

    copy_string(safe_string);
    return 0;
}