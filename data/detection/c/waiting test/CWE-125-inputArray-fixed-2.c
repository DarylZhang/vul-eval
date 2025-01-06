#include <stdio.h>
#include <stdlib.h>

int calculateSum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int findMax(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void processData(int *inputArray, int inputSize, int index) {
    int data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100;
    }

    int sum = calculateSum(data, 10);
    int max = findMax(inputArray, inputSize);

    // CWE-125: 可能发生越界读取
    int value = inputArray[index];

    printf("Selected value: %d\n", value);
    printf("Sum of data array: %d\n", sum);
    printf("Max of input array: %d\n", max);
}

int main() {
    int userInput[5] = {10, 20, 30, 40, 50};
    int userIndex;

    printf("Enter an index: ");
    if (scanf("%d", &userIndex) != 1) { // 检查 scanf 返回值
        printf("Error: Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // 在 main 函数中修复 CWE-125 漏洞：添加索引边界检查
    if (userIndex >= 0 && userIndex < 5) {
        processData(userInput, 5, userIndex);
    } else {
        printf("Error: Index out of bounds.\n");
    }

    return 0;
}