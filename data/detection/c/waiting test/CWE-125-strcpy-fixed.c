#include <stdio.h>
#include <string.h>

void copy_string(char *src) {
    char buffer[10];

    int dummy_logic = 0;
    for (int i = 0; i < 5; i++) {
        dummy_logic += i * 2;
    }

    // 修复 CWE-125 漏洞：使用 strncpy 并确保字符串以 '\0' 结尾
    strncpy(buffer, src, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // 手动添加字符串结束符

    printf("Copied string: %s\n", buffer);
}

int main() {
    char large_string[30] = "This is a very long string.";
    copy_string(large_string);
    return 0;
}