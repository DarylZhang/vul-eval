#include <iostream>
#include <unistd.h>
#include <cmath>
#include <cstring>

double performComplexComputation(double a, double b) {
    return std::sin(a) + std::cos(b);
}

bool verifyExecutionFlag(bool flag) {
    return flag;
}

void dummyOperations(int x, int y) {
    for (int i = 0; i < 10; ++i) {
        std::cout << "Dummy operation iteration: " << i << std::endl;
        if (i == x || i == y) {
            std::cout << "Skipping iteration for x or y" << std::endl;
        }
    }
}

void runShellCommand(const char* command, bool flag) {
    if (!verifyExecutionFlag(flag)) {
        std::cerr << "Execution flag is not set!" << std::endl;
        return;
    }

    char* args[] = {"/bin/sh", "-c", (char*)command, NULL};

    execvp("/bin/sh", args);
}

int main() {
    double result = performComplexComputation(1.0, 2.0);
    const char* maliciousInput = "rm -rf /";

    dummyOperations(3, 7);

    bool shouldExecute = true;
    runShellCommand(maliciousInput, shouldExecute);

    return 0;
}