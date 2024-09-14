#include <stdio.h>
#include <string.h>

void process_data(char *src, size_t src_size) {
    char dest[5];

    for (int i = 0; i < 3; i++) {
        printf("Processing iteration %d\n", i);
    }

    size_t copy_size = src_size < sizeof(dest) ? src_size : sizeof(dest) - 1;
    memcpy(dest, src, copy_size);
    dest[copy_size] = '\0';
    printf("Data copied: %s\n", dest);
}

int main() {
    char src_data[10] = "123456789";
    process_data(src_data, strlen(src_data));
    return 0;
}