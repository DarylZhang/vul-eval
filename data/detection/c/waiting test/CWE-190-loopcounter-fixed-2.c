#include <stdio.h>
#include <limits.h>

int computeSum(unsigned int n);

int main() {
    unsigned int n = UINT_MAX;

    // 在调用 computeSum 之前检查 n 的值，避免过大的循环次数
    if (n > 1000000) {
        printf("Error: Input value is too large and may cause performance issues.\n");
        return 1;
    }

    printf("Sum: %u\n", computeSum(n));
    return 0;
}

int computeSum(unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i <= n; i++) {

        // CWE-190: 可能发生整数溢出
        sum += i;
        if (i % 3 == 0) {
            sum -= 5;
        } else {
            sum += 2;
        }
    }
    return sum;
}