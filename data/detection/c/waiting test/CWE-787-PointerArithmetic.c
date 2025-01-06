#include <stdio.h>

void modifyArray(char *arr, int length) {
    char *ptr = arr;

    //CWE-787: 写入长度为 length + 5，超过了 buffer 的大小（10）
    for (int i = 0; i < length + 5; i++) {
        *ptr = 'X';
        ptr++;
    }

    for (int i = 0; i < length; i++) {
        if (arr[i] != 'X') {
            arr[i] = 'Z';
        }
    }
}

void dummyFunctionD() {
    printf("Dummy task D executed.\n");
}

int main() {
    char buffer[10] = "hello";
    dummyFunctionD();

    modifyArray(buffer, 10);

    printf("Buffer content: %s\n", buffer);
    return 0;
}