#include <stdio.h>
#include <string.h>

void copy_string(char *src) {
    char buffer[10];
    strcpy(buffer, src);
    printf("Copied string: %s\n", buffer);
}

int main() {
    char large_string[30] = "This is a very long string.";

    if (strlen(large_string) < 10) {
        copy_string(large_string);
    } else {
        printf("String too large for buffer\n");
    }

    return 0;
}