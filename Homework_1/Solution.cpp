//
// Created by asus on 2020/11/11.
//

#include "Solution.h"

int tmp[max_n];
std::stack<char> left_brackets;

int Solution::findMaxContinuousIntegers(const int *a, int len) {
    if (a == nullptr || len <= 0) {
        printf("Illegal null pointer input!\n");
        return -1;
    }

    /* 用于保存下标 */
    std::memset(tmp, -1, max_n);
    int first = 0, second = 0, max = 0;
    for (int k = 0; k < len; ++k) {
        /* 前面已存在该数 并且在first后面 ，更新first */
        if (tmp[a[k]] != -1 && tmp[a[k]] >= first) {
            /* 大于则更新最大值 */
            if (second - first > max)
                max = second - first;
            /* 移到下一个 */
            first = tmp[a[k]] + 1;
            tmp[a[k]] = k;
        }
        tmp[a[k]] = k;
        second = k;
    }
    /* 最后更新 */
    if (second - first > max)
        max = second - first;
    return max + 1;
}

int Solution::findMaxMatchBrackets(std::string str) {
    if (str.empty())
        return -1;
    char c;
    int i = 0, res = 0;
    while ((c = str[i++]) != '\0') {
        if (c == '(')
            left_brackets.push(c);
        else if (c == ')' && !left_brackets.empty()) {
            left_brackets.pop();
            res++;
        }
    }
    return res;
}
