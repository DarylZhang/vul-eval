#include <stdio.h>
#include <string.h>

void modifyArray(char *arr, int length) {
    char *ptr = arr;

    // 假设调用者已确保不会写入超过数组大小
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

    int requestedLength = 10;
    int bufferSize = sizeof(buffer);

    // 修复：在调用前确保不会超过 buffer 的大小
    if (requestedLength + 5 > bufferSize) {
        printf("Error: Requested write length %d exceeds buffer size %d. Adjusting length.\n", requestedLength + 5, bufferSize);
        requestedLength = bufferSize - 5; // 调整 length 以防止越界
    }

    modifyArray(buffer, requestedLength);

    printf("Buffer content: %s\n", buffer);
    return 0;
}