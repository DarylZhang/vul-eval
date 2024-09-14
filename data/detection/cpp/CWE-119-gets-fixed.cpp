#include <iostream>

void complex_calculation(int a, int b) {
    for (int i = 0; i < a; i++) {
        std::cout << "Iterating complex calculation: " << i << std::endl;
    }
    std::cout << "Complex result: " << a * b << std::endl;
}

void dummy_computation(int x) {
    for (int i = 0; i < x; ++i) {
        std::cout << "Performing dummy computation: " << i << std::endl;
    }
}

void analyze_input(char* input) {
    dummy_computation(strlen(input));
    std::cout << "Analyzing input data: " << input << std::endl;
}

void read_input(char* buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    analyze_input(buffer);
    complex_calculation(strlen(buffer), 42);
}

int main() {
    char buffer[50];

    std::cout << "Enter input: ";
    read_input(buffer, sizeof(buffer));

    return 0;
}