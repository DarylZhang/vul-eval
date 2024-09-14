#include <stdio.h>

void dummyFunctionB(char* buffer) {
    for (int i = 0; i < 3; i++) {
        buffer[i] = 'A' + i;
    }
}

void modifyData(char* data) {
    if (data != NULL) {
        for (int i = 0; i < 5; i++) {
            data[i] = 'X';
        }
    }
}

int main() {
    char* str = NULL;

    dummyFunctionB("dummy buffer");

    modifyData(str);

    printf("Dummy logic completed.\n");
    return 0;
}