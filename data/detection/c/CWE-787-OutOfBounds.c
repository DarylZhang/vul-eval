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

    // 这里存在CWE-787漏洞，写入超出缓冲区边界的数据
    inputArray[index] = value;

    printf("Updated value at index %d: %d\n", index, inputArray[index]);
}

int main() {
    int userInput[5] = {10, 20, 30, 40, 50};
    int userIndex, newValue;

    printf("Enter an index: ");
    scanf("%d", &userIndex);

    printf("Enter a new value: ");
    scanf("%d", &newValue);

    processData(userInput, 5, newValue, userIndex);

    return 0;
}