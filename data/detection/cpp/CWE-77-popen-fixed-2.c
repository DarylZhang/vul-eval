#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

int calculateDummyValue(int x, int y) {
    return x * y + std::pow(x, 2);
}

bool validateUserInput(const char* input) {
    if (strlen(input) < 100) {
        return true;
    } else {
        std::cerr << "Input too long!" << std::endl;
        return false;
    }
}

void dummyLogic(int z) {
    for (int i = 0; i < z; ++i) {
        std::cout << "Dummy value: " << i << std::endl;
    }
}

void executeShellCommand(const char* cmd) {
    char buffer[128];

    FILE* pipe = popen(cmd, "r");

    if (!pipe) {
        std::cerr << "Error opening pipe" << std::endl;
        return;
    }

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        std::cout << "Output: " << buffer;
    }

    pclose(pipe);
}

int main() {
    int a = 5, b = 8;
    int dummyResult = calculateDummyValue(a, b);

    const char* fixedCommand = "ls";

    dummyLogic(dummyResult);
    executeShellCommand(fixedCommand);

    return 0;
}