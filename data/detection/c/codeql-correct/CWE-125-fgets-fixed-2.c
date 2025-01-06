#include <stdio.h>
#include <stdlib.h>

void read_input(char *buffer, size_t buffer_size, size_t read_position) {
    int result = 0;
    for (int i = 1; i <= 10; i++) {
        result += i;
    }
    printf("Dummy logic result: %d\n", result);

    fgets(buffer, buffer_size, stdin);
    printf("Input: %s\n", buffer);

    printf("Reading buffer at position %zu: %c\n", read_position, buffer[read_position]);
}

int main() {
    printf("Enter some input: ");

    size_t buffer_size = 10;
    size_t read_position = 10;

    if (read_position >= buffer_size) {
        printf("Error: Read position %zu exceeds buffer size %zu.\n", read_position, buffer_size);
        return EXIT_FAILURE;
    }

    char buffer[buffer_size];
    read_input(buffer, buffer_size, read_position);

    return 0;
}