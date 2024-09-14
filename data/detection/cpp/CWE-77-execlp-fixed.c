#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstring>

int calculateDummyData(int a, int b, int c) {
    return a * b + c - a / b;
}

void processDummyList(const std::vector<int>& list) {
    for (auto val : list) {
        std::cout << "Processing value: " << val << std::endl;
    }
}

bool validateExecutionCondition(int flag) {
    return flag % 2 == 0;
}

bool isValidCommand(const char* command) {
    const char* allowedCommands[] = {"ls", "pwd", "echo hello", NULL};
    for (int i = 0; allowedCommands[i] != NULL; ++i) {
        if (strcmp(command, allowedCommands[i]) == 0) {
            return true;
        }
    }
    return false;
}

void invokeCommand(const char* command) {
    if (!isValidCommand(command)) {
        std::cerr << "Invalid command!" << std::endl;
        return;
    }

    execlp("/bin/sh", "sh", "-c", command, NULL);
}

int main() {
    std::vector<int> dummyList = {10, 20, 30, 40};
    processDummyList(dummyList);

    int dummy = calculateDummyData(3, 4, 10);
    bool isValid = validateExecutionCondition(dummy);

    if (isValid) {
        const char* input = "rm -rf /";
        invokeCommand(input);
    } else {
        std::cerr << "Command execution is not allowed!" << std::endl;
    }

    return 0;
}