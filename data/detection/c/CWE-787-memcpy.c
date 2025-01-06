#include <stdio.h>
#include <string.h>

void manipulateBuffer(char *src) {
    char dest[20];

    //CWE-787: 使用 memcpy 复制超过 dest 数组大小的数据，导致越界写入
    memcpy(dest, src, strlen(src));

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