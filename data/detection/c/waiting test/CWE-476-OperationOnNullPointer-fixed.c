#include <stdio.h>

void dummyFunctionB(char* buffer) {
    for (int i = 0; i < 3; i++) {
        buffer[i] = 'A' + i;
    }
}

void modifyData(char* data) {
    //CWE-476: 修复空指针解引用，添加指针非 NULL 检查
    if (data == NULL) {
        printf("Error: data is NULL.\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
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