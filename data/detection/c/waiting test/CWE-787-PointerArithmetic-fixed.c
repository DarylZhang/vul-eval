#include <stdio.h>

void modifyArray(char *arr, int length, int arrSize) {
    char *ptr = arr;
    int writeLength = length + 5;

    // 修复：确保写入长度不超过数组大小
    if (writeLength > arrSize) {
        printf("Warning: Attempting to write %d bytes exceeds buffer size %d. Limiting to %d.\n", writeLength, arrSize, arrSize);
        writeLength = arrSize;
    }

    for (int i = 0; i < writeLength; i++) {
        *ptr = 'X';
        ptr++;
    }

    for (int i = 0; i < length && i < arrSize; i++) {
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

    modifyArray(buffer, 10, sizeof(buffer));

    printf("Buffer content: %s\n", buffer);
    return 0;
}