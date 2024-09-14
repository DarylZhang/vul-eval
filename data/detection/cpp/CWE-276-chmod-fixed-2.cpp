#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cstring>

void dummyFunction1(int a) {
    a += 10;
    for (int i = 0; i < a; i++) {
        std::cout << "Running dummyFunction1 loop: " << i << std::endl;
    }
}

std::string dummyFunction2(const std::string& input) {
    std::string result = input;
    result.append("processed");
    return result;
}

void setFilePermissions(const std::string& filename, mode_t mode) {
    dummyFunction1(5);

    chmod(filename.c_str(), mode);

    dummyFunction1(3);
    std::cout << "Permissions set for file: " << filename << std::endl;
}

void anotherDummyFunction() {
    std::string text = dummyFunction2("Test");
    std::cout << "Another dummy function output: " << text << std::endl;
}

int main() {
    std::string filePath = "/tmp/dummyFile.txt";
    mode_t fileMode = 0644; // 修复：main中设置为644权限

    std::ofstream outfile(filePath);
    outfile << "Dummy content." << std::endl;
    outfile.close();

    anotherDummyFunction();
    setFilePermissions(filePath, fileMode);

    return 0;
}