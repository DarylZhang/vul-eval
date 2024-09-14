#include <stdio.h>

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
    char buffer[10];
    char* str = buffer;

    dummyFunctionB("dummy buffer");

    modifyData(str);

    printf("Dummy logic completed.\n");
    return 0;
}