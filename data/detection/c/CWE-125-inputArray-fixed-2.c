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

    int value = inputArray[index];
    printf("Selected value: %d\n", value);

    printf("Sum of data array: %d\n", sum);
    printf("Max of input array: %d\n", max);
}

int isValidIndex(int index, int size) {
    return (index >= 0 && index < size);
}

int main() {
    int userInput[5] = {10, 20, 30, 40, 50};
    int userIndex;

    printf("Enter an index: ");
    scanf("%d", &userIndex);

    // 检查索引是否在有效范围内
    if (!isValidIndex(userIndex, 5)) {
        printf("Index out of bounds\n");
        return 1;
    }

    processData(userInput, 5, userIndex);

    return 0;
}