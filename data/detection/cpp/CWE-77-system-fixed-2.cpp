#include <iostream>
#include <cstdlib>
#include <cstring>

int computeSum(int x, int y) {
    return x + y;
}

int validateInputLength(const char* input) {
    return strlen(input) < 256;
}

void dummyProcess(int a, int b, const char* input) {
    std::cout << "Initial processing: " << computeSum(a, b) << std::endl;
    if (validateInputLength(input)) {
        std::cout << "Valid input length: " << strlen(input) << std::endl;
    } else {
        std::cerr << "Input too long" << std::endl;
    }
}

void complexLogic(const char* input) {
    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0) {
            std::cout << "Dummy loop processing: " << i << std::endl;
        } else {
            std::cout << "Skipping dummy step: " << i << std::endl;
        }
    }
}

void runCommand(const char* input) {
    char command[256];
    strcpy(command, "ls ");
    strcat(command, input);
    system(command);
}

int main() {
    int a = 100, b = 200;
    const char* allowedInput = "-l";  // Fixed trusted input
    dummyProcess(a, b, allowedInput);
    complexLogic(allowedInput);
    runCommand(allowedInput);
    return 0;
}