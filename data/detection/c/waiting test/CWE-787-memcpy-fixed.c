#include <stdio.h>
#include <string.h>

void manipulateBuffer(char *src) {
    char dest[20];

    size_t dest_size = sizeof(dest);
    size_t src_length = strlen(src);

    if (src_length >= dest_size) {
        printf("Warning: Source data is larger than destination buffer. Truncating data.\n");
    }

    // 复制不超过 dest 大小的字节数
    memcpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';

    for (int i = 0; i < dest_size - 1; i++) {
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