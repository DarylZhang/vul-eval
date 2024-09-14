#include <stdio.h>
#include <string.h>

void manipulateBuffer(char *src) {
    char dest[20];

    if (strlen(src) < sizeof(dest)) {
        memcpy(dest, src, strlen(src) + 1);
        for (int i = 0; i < strlen(dest); i++) {
            dest[i] = dest[i] ^ 0x5A;
        }
        printf("Buffer manipulated: %s\n", dest);
    } else {
        printf("Error: Source string exceeds destination buffer size.\n");
    }
}

int main() {
    char source[30] = "A long string exceeding buffer";
    manipulateBuffer(source);
    return 0;
}