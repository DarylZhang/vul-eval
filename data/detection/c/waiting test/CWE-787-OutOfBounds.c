#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calculateAverage(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

void processData(int *inputArray, int inputSize, int value, int index) {
    int data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100;
    }

    double average = calculateAverage(data, 10);
    printf("Average of data array: %.2f\n", average);

    //CWE-787: 未检查 `index` 的有效性，可能导致越界写入
    inputArray[index] = value;

    printf("Updated value at index %d: %d\n", index, inputArray[index]);
}

int main() {
    int userInput[5] = {10, 20, 30, 40, 50};
    int userIndex, newValue;

    printf("Enter an index: ");
    if (scanf("%d", &userIndex) != 1) { // 检查 scanf 返回值
        printf("Error: Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    printf("Enter a new value: ");
    if (scanf("%d", &newValue) != 1) { // 检查 scanf 返回值
        printf("Error: Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    processData(userInput, 5, newValue, userIndex);

    return 0;
}