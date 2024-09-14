#include <stdio.h>
#include <string.h>

void manipulateBuffer(char *src) {
    char dest[20];

    // CWE-787
    memcpy(dest, src, 25);

    for (int i = 0; i < 20; i++) {
        dest[i] = dest[i] ^ 0x5A;
    }
    printf("Buffer manipulated.\n");
}

void dummyFunctionB() {
    printf("Executing dummy function B\n");
}

int main() {
    char source[30] = "A long string exceeding buffer";
    dummyFunctionB();
    manipulateBuffer(source);
    return 0;
}