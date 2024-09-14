#include <iostream>
#include <cstring>

void dummyProcess2(const char* input) {
    for (int i = 0; i < strlen(input); i++) {
        std::cout << input[i];
    }
    std::cout << std::endl;
}

void complexLogic2() {
    dummyProcess2("Executing complex logic 2");
    int dummyVar = 0;
    for (int i = 0; i < 20; i++) {
        dummyVar += i;
    }
}

void function1(char* dest, const char* src, int size) {
    complexLogic2();

    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0';

    complexLogic2();
}

int main() {
    char dest[10];
    const char* src = "This is a very long string";
    complexLogic2();

    function1(dest, src, sizeof(dest));
    std::cout << "Destination: " << dest << std::endl;
    return 0;
}