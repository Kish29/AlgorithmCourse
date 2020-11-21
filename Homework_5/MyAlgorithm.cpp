//
// Created by asus on 2020/11/20.
//

#include "MyAlgorithm.h"

void printAllPalindrome(const string &str) {
    int len = str.length();
    int k = 1, i;
    /* 从长度2到整个字符串长度 */
    for (; k < len; k++) {
        for (i = 0; i < len - k; ++i) {
            isPalindrome(str, i, i + k);
        }
    }
}

void isPalindrome(const string &str, int i, int j) {
    int m = i, n = j;
    while (str[i] == str[j]) {
        i++, j--;
        if (i > j)
            break;
    }
    if (i < j) return;
    string p_str = str.substr(m, n - m + 1);
    std::cout << p_str << '\n';
}

void printConsistentFactors(int n) {
    ll sum;
    int max_edge = (int) sqrt(n) + 1;
    // x <= 2 ^ 31
    // x介于12!~13!
    int len = 12;
    for (; len >= 1; len--) {
        for (int j = 2; j <= max_edge; ++j) {
            int k = j;
            sum = 1;
            while (k - j <= len - 1) {
                sum *= k;
                k++;
                if (sum > n)
                    break;
            }
            if (n % sum == 0) {
                printf("%d\n%d", len, j++);
                for (; j < k; ++j) {
                    printf("*%d", j);
                }
                return;
            }
        }
    }
    printf("1\n%d", n);
}
