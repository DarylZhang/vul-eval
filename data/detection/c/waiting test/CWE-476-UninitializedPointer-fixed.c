#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dummyFunctionB(char* buffer) {
    if (buffer == NULL) {
        printf("Error: buffer is NULL. Cannot modify.\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        buffer[i] = 'A' + i;
    }
}

void modifyData(char* data) {
    if (data == NULL) {
        printf("Error: data is NULL. Cannot modify.\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        data[i] = 'X';
    }
}

int main() {
    char* str = NULL;

    char writableBuffer[] = "dummy buffer";
    dummyFunctionB(writableBuffer);

    modifyData(str);

    printf("Dummy logic completed.\n");
    return 0;
}