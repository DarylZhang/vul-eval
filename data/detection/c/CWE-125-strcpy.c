#include <stdio.h>
#include <string.h>

void copy_string(char *src) {
    char buffer[10];

    int dummy_logic = 0;
    for (int i = 0; i < 5; i++) {
        dummy_logic += i * 2;
    }

    //CWE-125
    strcpy(buffer, src);
    printf("Copied string: %s\n", buffer);
}

int main() {
    char large_string[30] = "This is a very long string.";
    copy_string(large_string);
    return 0;
}