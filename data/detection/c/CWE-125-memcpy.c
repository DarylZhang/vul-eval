#include <stdio.h>
#include <string.h>

void process_data(char *src) {
    char dest[5];

    for (int i = 0; i < 3; i++) {
        printf("Processing iteration %d\n", i);
    }

    //CWE-125
    memcpy(dest, src, 10);
    printf("Data copied: %s\n", dest);
}

int main() {
    char src_data[10] = "123456789";
    process_data(src_data);
    return 0;
}