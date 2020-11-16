//
// Created by asus on 2020/11/16.
//

#include "Solution.h"
#include "cstring"

int dp[max_n];

int Solution::findMinBasicStr(const std::string &str) {
    int len = str.length();
    if (len == 1)
        return 1;
    std::string part1 = str.substr(0, len / 2);
    std::string part2 = str.substr(len / 2);
    if (isMirrorEqualTo(part1, part2))
        return findMinBasicStr(part1);
    else return len;
}

bool Solution::isMirrorEqualTo(const std::string &str1, const std::string &str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 != len2)
        return false;
    int i = 0, j = len2 - 1;
    for (; i < len1; i++) {
        if (str1[i] != str2[j - i])
            return false;
    }
    return true;
}

int Solution::findMaxTraverseTime(const int *array, int len) {
    memset(dp, 0, max_n);
    int res = 0;
    for (int i = len - 1; i >= 0; i--) {
        dp[i] = dp[i + array[i]] + 1;
        res = std::max(dp[i], res);
    }
    return res;
}

