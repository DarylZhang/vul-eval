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
    if (index < 0 || index >= inputSize) {
        printf("Error: Index out of bounds\n");
        return;
    }

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

int main() {
    int userInput[5] = {10, 20, 30, 40, 50};
    int userIndex;

    printf("Enter an index: ");
    scanf("%d", &userIndex);

    processData(userInput, 5, userIndex);

    return 0;
}