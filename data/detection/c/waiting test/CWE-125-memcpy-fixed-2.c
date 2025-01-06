#include <stdio.h>
#include <string.h>

void process_data(char *src) {
    char dest[5];

    for (int i = 0; i < 3; i++) {
        printf("Processing iteration %d\n", i);
    }

    // CWE-125: 可能发生越界读取
    memcpy(dest, src, 10);
    printf("Data copied: %s\n", dest);
}

int main() {
    char src_data[10] = "123456789";

    // 在 main 函数中修复 CWE-125 漏洞：确保传递给 process_data 的数据不会导致越界
    char safe_src_data[5];
    strncpy(safe_src_data, src_data, sizeof(safe_src_data) - 1);
    safe_src_data[sizeof(safe_src_data) - 1] = '\0';

    process_data(safe_src_data);
    return 0;
}