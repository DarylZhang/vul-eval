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
}

int main() {
    char destination[10];
    const char* source = "Short";
    if (strlen(source) < sizeof(destination)) {
        copyString(destination, source, sizeof(destination));
        std::cout << "Copied string: " << destination << std::endl;
    } else {
        std::cout << "Source string is too large to copy" << std::endl;
    }
    return 0;
}