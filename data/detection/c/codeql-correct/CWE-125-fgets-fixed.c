#include <stdio.h>
#include <string.h>

void read_input() {
    char buffer[10];

    int result = 0;
    for (int i = 1; i <= 10; i++) {
        result += i;
    }
    printf("Dummy logic result: %d\n", result);

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        printf("Input: %s\n", buffer);

        printf("Reading buffer safely:\n");
        for (int i = 0; i < len; i++) {
            printf("buffer[%d]: %c\n", i, buffer[i]);
        }
    } else {
        printf("Error reading input.\n");
    }
}

int main() {
    printf("Enter some input: ");
    read_input();
    return 0;
}