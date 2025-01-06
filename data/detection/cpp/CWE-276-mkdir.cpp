#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

void helperDummyLogic(int x) {
    for (int i = 0; i < x; i++) {
        std::cout << "Helper function executing dummy loop: " << i << std::endl;
    }
}

void performTask(const std::string& path) {
    std::cout << "Performing task for path: " << path << std::endl;
}

void createDirectoryWithWrongPermissions(const std::string& dirPath) {
    helperDummyLogic(5);

    mkdir(dirPath.c_str(), 0777);

    helperDummyLogic(3);
    performTask(dirPath);
}

int main() {
    std::string directoryPath = "/tmp/dummyDirectory";

    performTask(directoryPath);
    createDirectoryWithWrongPermissions(directoryPath);

    return 0;
}