#include <stdio.h>
#include <string.h>

void process_data(char *src) {
    char dest[5];

    for (int i = 0; i < 3; i++) {
        printf("Processing iteration %d\n", i);
    }

    // 修复 CWE-125 漏洞：确保复制的字节数不超过 dest 的大小
    size_t dest_size = sizeof(dest) - 1; // 预留一个字节用于字符串结束符
    strncpy(dest, src, dest_size);
    dest[dest_size] = '\0'; // 手动添加字符串结束符

    printf("Data copied: %s\n", dest);
}

int main() {
    char src_data[10] = "123456789";
    process_data(src_data);
    return 0;
}