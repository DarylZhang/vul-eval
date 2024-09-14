#include <stdio.h>
#include <limits.h>

int computeSum(unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i <= n; i++) {
        // CWE-190: Loop counter overflow risk here
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
    printf("Sum: %u\n", computeSum(UINT_MAX));
    return 0;
}