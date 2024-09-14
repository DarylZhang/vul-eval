#include <stdio.h>

void read_input() {
    char buffer[10];

    int result = 0;
    for (int i = 1; i <= 10; i++) {
        result += i;
    }
    printf("Dummy logic result: %d\n", result);

    fgets(buffer, sizeof(buffer), stdin);
    printf("Input: %s\n", buffer);
}

int main() {
    printf("Enter some input: ");
    read_input();
    return 0;
}