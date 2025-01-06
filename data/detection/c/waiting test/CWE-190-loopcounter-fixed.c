#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool safeAddUnsigned(unsigned int a, unsigned int b, unsigned int *result);

int computeSum(unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i <= n; i++) {

        // 修复 CWE-190 漏洞：在相加前检查是否会溢出
        if (!safeAddUnsigned(sum, i, &sum)) {
            printf("Error: Integer overflow detected during summation.\n");
            return sum;
        }

        if (i % 3 == 0) {
            if (sum < 5) {
                printf("Error: Underflow detected during subtraction.\n");
                return sum;
            }
            sum -= 5;
        } else {
            if (!safeAddUnsigned(sum, 2, &sum)) {
                printf("Error: Integer overflow detected during addition.\n");
                return sum;
            }
        }
    }
    return sum;
}

bool safeAddUnsigned(unsigned int a, unsigned int b, unsigned int *result) {
    if (a > UINT_MAX - b) {
        // 检测到溢出
        return false;
    }
    *result = a + b;
    return true;
}

int main() {
    unsigned int n = UINT_MAX;

    // 为了避免循环次数过多，限制 n 的值
    if (n > 1000000) {
        n = 1000000; // 设置一个合理的上限
    }

    printf("Sum: %u\n", computeSum(n));
    return 0;
}