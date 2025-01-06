#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void processData(int value);

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

    // CWE-190: 可能发生整数溢出
    int result = value * 2;

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