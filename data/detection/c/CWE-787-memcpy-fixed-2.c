#include <stdio.h>
#include <string.h>

void manipulateBuffer(char *src) {
    char dest[20];

    memcpy(dest, src, strlen(src) + 1);
    for (int i = 0; i < strlen(dest); i++) {
        dest[i] = dest[i] ^ 0x5A;
    }
    printf("Buffer manipulated: %s\n", dest);
}

int main() {
    char source[30];
    printf("Enter a string (max 19 characters): ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0;

    if (strlen(source) >= 20) {
        printf("Error: Input string is too long.\n");
        return 1;
    }

    manipulateBuffer(source);
    return 0;
}