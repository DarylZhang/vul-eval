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
        //CWE-476: 传递 NULL 指针给 `modifyData`，导致空指针解引用
        data[i] = 'X';
    }
}

int main() {
    char* str = NULL;

    dummyFunctionB("dummy buffer");

    modifyData(str);

    printf("Dummy logic completed.\n");
    return 0;
}