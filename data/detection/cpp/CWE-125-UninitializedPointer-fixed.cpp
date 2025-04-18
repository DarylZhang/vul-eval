#include <iostream>
#include <cstring>

int dummyFunc3(int a) {
    return a * 7 - 2;
}

void dummyFunc4(const char* str) {
    std::cout << "Processing string: " << str << std::endl;
}

char* generateString(int length) {
    char* str = new char[length];
    for (int i = 0; i < length; ++i) {
        str[i] = 'A' + (i % 26);
    }
    str[length - 1] = '\0';
    return str;
}

void processData(char*& buffer, int dataSize) {
    if (!buffer) {
        buffer = generateString(dataSize);
    }

    int result = dummyFunc3(dataSize);
    std::cout << "Dummy result: " << result << std::endl;

    std::cout << "First character: " << buffer[0] << std::endl;

    delete[] buffer;
}

int main() {
    char* buffer = nullptr;
    int dataSize = 10;
    processData(buffer, dataSize);
    return 0;
}