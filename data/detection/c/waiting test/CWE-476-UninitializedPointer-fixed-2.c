#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dummyFunctionB(char* buffer) {
    for (int i = 0; i < 3; i++) {
        buffer[i] = 'A' + i;
    }
}

void modifyData(char* data) {
    for (int i = 0; i < 5; i++) {
        data[i] = 'X';
    }
}

int main() {
    char* str = NULL;

    char writableBuffer[] = "dummy buffer";
    dummyFunctionB(writableBuffer);

    // 修复：确保 `str` 在使用前已正确分配内存
    str = (char*)malloc(10 * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    strcpy(str, "Hello");

    modifyData(str);

    free(str);
    str = NULL;

    printf("Dummy logic completed.\n");
    return 0;
}