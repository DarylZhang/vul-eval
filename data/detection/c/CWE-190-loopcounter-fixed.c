#include <stdio.h>
#include <limits.h>

unsigned int computeSum(unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < n; i++) {
        if (UINT_MAX - sum < i) {
            printf("Potential overflow detected, stopping the computation.\n");
            break;
        }
        sum += i;
        if (i % 3 == 0) {
            sum -= 5;
        } else {
            sum += 2;
        }
    }
    return sum;
}

int main() {
    unsigned int maxVal = UINT_MAX - 1;
    printf("Sum: %u\n", computeSum(maxVal));
    return 0;
}