#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

void dummyMethodA() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "Dummy loop in dummyMethodA: " << i << std::endl;
    }
}

void dummyMethodB() {
    std::cout << "Dummy method B execution" << std::endl;
}

void createFileWithWrongPermissions(const std::string& filename) {
    dummyMethodA();

    // CWE-276: Incorrect Default Permissions
    umask(0000);

    std::ofstream file(filename);
    if (file.is_open()) {
        file << "This is a test file with incorrect permissions." << std::endl;
        file.close();
    }

    dummyMethodB();
}

void anotherDummyMethod() {
    std::cout << "Execution in anotherDummyMethod" << std::endl;
}

int main() {
    std::string filePath = "/tmp/testFile.txt";

    anotherDummyMethod();
    createFileWithWrongPermissions(filePath);

    return 0;
}