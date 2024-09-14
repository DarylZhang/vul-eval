#include <stdio.h>
#include <stdlib.h>

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

    inputArray[index] = value;

    printf("Updated value at index %d: %d\n", index, inputArray[index]);
}

int isValidIndex(int index, int size) {
    return (index >= 0 && index < size);
}

int main() {
    int userInput[5] = {10, 20, 30, 40, 50};
    int userIndex, newValue;

    printf("Enter an index: ");
    scanf("%d", &userIndex);

    printf("Enter a new value: ");
    scanf("%d", &newValue);

    // 检查索引是否在有效范围内
    if (!isValidIndex(userIndex, 5)) {
        printf("Index out of bounds\n");
        return 1;
    }

    processData(userInput, 5, newValue, userIndex);

    return 0;
}