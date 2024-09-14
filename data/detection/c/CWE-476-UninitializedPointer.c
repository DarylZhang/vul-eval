#include <stdio.h>

void processData(int* data) {
    for (int i = 0; i < 10; i++) {
        printf("Processing index %d\n", i);
    }
}

void dummyFunctionA(int* input) {
    for (int i = 0; i < 5; i++) {
        *input += i;
    }
}

int main() {
    int* ptr;
    int dummy = 42;

    dummyFunctionA(&dummy);

    // CWE-476
    processData(ptr);

    printf("Main function ends.\n");
    return 0;
}