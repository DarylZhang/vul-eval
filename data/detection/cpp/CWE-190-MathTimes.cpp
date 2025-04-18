#include <iostream>

double someComplexFunction(double a, double b) {
    double result = 0;
    for (int i = 0; i < 50; ++i) {
        result += (a + i * b) * 0.01;
    }
    return result;
}

void dummyProcessor(int p) {
    for (int i = 0; i < p; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int dummyMultiplication(int a, int b) {
    return (a * b) + (a / 2);
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int a = 1000000;
    int b = 3000;

    int product = multiply(a, b);

    std::cout << "Product: " << product << std::endl;

    double result = someComplexFunction(a, b);
    dummyProcessor(10);
    dummyMultiplication(a, b);

    return 0;
}