#include <stdio.h>
#include <string.h>

void process_data(char *src) {
    char dest[5];
    memcpy(dest, src, strlen(src));
    printf("Data copied: %s\n", dest);
}

int main() {
    char src_data[10] = "123456789";

    if (strlen(src_data) < 5) {
        process_data(src_data);
    } else {
        printf("Source data too large for buffer\n");
    }

    return 0;
}