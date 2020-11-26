//
// Created by 87569 on 2020/11/26.
//

#include "MyAlgorithm.h"


int YHTriangle[3000][3000];

int getCombinationNum(int n, int m) {
    YHTriangle[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        YHTriangle[i][0] = 1;
        YHTriangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            YHTriangle[i][j] = (YHTriangle[i - 1][j - 1] + YHTriangle[i - 1][j]) % 1000000007;
        }
    }
    return YHTriangle[n][m];
}

const int max_n = 20;

/* 使用该数组dp[i][j]表示前 i 个数字用掉 j 个 + 号的最小和 */
int dp[max_n][max_n];

int getMinFee(const char *str, int split_num) {
    int len = str_len(str);
    memset(dp, INT8_MAX, sizeof(dp));
    /* 初始化前 i 个数字用掉 0 个 + 号的最小和 */
    for (int i = 1; i <= len; ++i) {
        dp[i][0] = my_atoi(str, 0, i - 1);
    }
    /* 注意，分成m段需要用掉 m - 1个加号 */
    for (int plus_num = 1; plus_num < split_num; ++plus_num) {
        /* 从第1个数字开始找 */
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= i; ++j) {
                /* 前j个数字用掉 i个+号的最小和*/
                /* 注意，i和j从1开始，而我们需要计算后面的 i + 1到i的值
                 * 而my_atoi的下标要求从0 ~ len - 1
                 * 所以 j和i各-1*/
                int tmp = dp[j][plus_num - 1] + my_atoi(str, j, i - 1);
                dp[i][plus_num] = dp[i][plus_num] < tmp ? dp[i][plus_num] : tmp;
            }
        }
    }
    return dp[len][split_num - 1];
}

int my_atoi(const char *str, int lo, int hi) {
    if (str == nullptr)
        return -1;
    int val = 0;
    while (str[lo] != '\0' && lo <= hi) {
        val = val * 10 + str[lo] - 48;
        lo++;
    }
    return val;
}

int str_len(const char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}
