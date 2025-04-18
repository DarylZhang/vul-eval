#include <iostream>
#include <cstring>

int dummyOperation(int a) {
    return a * 2 + 1;
}

void dummyComplexOperation(const char* str) {
    for (int i = 0; i < strlen(str); ++i) {
        std::cout << dummyOperation(i) << std::endl;
    }
}

void copyString(char* dest, const char* src, size_t destSize) {
    dummyComplexOperation(src);

    strncpy(dest, src, destSize);
    dest[destSize - 1] = '\0';

    std::cout << "Copied string: " << dest << std::endl;
}

int main() {
    char destination[10];
    const char* source = "This is a very long string that will overflow";

    copyString(destination, source, sizeof(destination));

    return 0;
}