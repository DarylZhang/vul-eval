#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

int calculateDummyValue(int x, int y) {
    return x * y + std::pow(x, 2);
}

bool validateUserInput(const char* input) {
    const char* allowedCommands[] = {"echo hello", "ls", NULL};
    for (int i = 0; allowedCommands[i] != NULL; ++i) {
        if (strcmp(input, allowedCommands[i]) == 0) {
            return true;
        }
    }
    return false;
}

void dummyLogic(int z) {
    for (int i = 0; i < z; ++i) {
        std::cout << "Dummy value: " << i << std::endl;
    }
}

void executeShellCommand(const char* cmd) {
    char buffer[128];

    if (!validateUserInput(cmd)) {
        std::cerr << "Invalid command input!" << std::endl;
        return;
    }

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
    strcpy(command, "echo hello");

    dummyLogic(dummyResult);
    executeShellCommand(command);

    return 0;
}