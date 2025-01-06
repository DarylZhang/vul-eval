#include <stdio.h>
#include <string.h>

void manipulateBuffer(char *src) {
    char dest[20];

    // 这里假设 size 已被调用者正确限制
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

    if (strlen(source) < 20) {
        manipulateBuffer(source);
    } else {
        printf("Error: Source data is too large to be processed safely.\n");
    }

    return 0;
}