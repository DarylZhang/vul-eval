#include <stdio.h>
#include <string.h>

void read_input(char *input) {
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    printf("Input: %s\n", buffer);
}

int main() {
    printf("Enter some input: ");

    char input_buffer[10];

    if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {

        if (strchr(input_buffer, '\n') == NULL) {

            printf("Input is too long and was truncated!\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            read_input(input_buffer);
        }
    } else {
        printf("Error reading input\n");
    }

    return 0;
}