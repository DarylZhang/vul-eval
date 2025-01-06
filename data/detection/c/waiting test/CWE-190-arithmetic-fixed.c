#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

void processData(int value);
bool safeMultiply(int a, int b, int *result);

int main() {
    srand(time(NULL));
    int userInput;
    printf("Enter a positive integer: ");
    if (scanf("%d", &userInput) != 1) {
        printf("Error: Invalid input. Please enter a valid integer.\n");
        return 1;
    }
    processData(userInput);
    return 0;
}

void processData(int value) {
    // 添加虚拟逻辑，使代码更复杂
    int intermediate = value;
    for (int i = 0; i < 5; i++) {
        intermediate += i * 3;
        if (intermediate % 2 == 0) {
            intermediate /= 2;
        } else {
            intermediate = intermediate * 2 + 1;
        }
    }

    // 修复 CWE-190 漏洞：使用安全的乘法函数
    int result;
    if (!safeMultiply(value, 2, &result)) {
        printf("Error: Integer overflow detected during multiplication.\n");
        return;
    }

    // 更多的虚拟逻辑
    int array[10];
    for (int i = 0; i < 10; i++) {
        array[i] = result + i;
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += array[i];
    }

    printf("Processed value: %d\n", sum);
}

bool safeMultiply(int a, int b, int *result) {
    if (a > 0 && b > 0) {
        if (a > INT_MAX / b) return false;
    } else if (a < 0 && b < 0) {
        if (a < INT_MAX / b) return false;
    } else if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
        if (a < INT_MIN / b) return false;
    }
    *result = a * b;
    return true;
}