#include <iostream>
#include <cstdio>
#include <cmath>

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

    // CWE-77: Untrusted input passed to popen
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

    char command[128];
    strcpy(command, "echo ");
    strcat(command, "hello; rm -rf /");

    if (validateUserInput(command)) {
        dummyLogic(dummyResult);
        executeShellCommand(command);
    }

    return 0;
}