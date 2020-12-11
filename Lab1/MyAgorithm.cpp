//
// Created by 87569 on 2020/12/9.
//

#include <cstdint>
#include "MyAgorithm.h"

int dp[max_n][max_n];  // 表示前j个数字用掉i各分隔号的最大值最小的数

int getDiceNum(int n) {
    /* 初始化dp数据*/
    return 0;
}

int minDivide(int *nums, int len, int n) {
    if (nums == nullptr)
        return -1;
    if (len == 1)
        return nums[0];
    if (len == 2)
        return nums[0] + nums[1];
    /*初始化数组*/
    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j <= len; ++j) {
            dp[i][j] = INT32_MIN;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= len; ++i) {
        dp[i][0] = dp[i - 1][0] + nums[i - 1];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= len; ++j) {
            for (int k = 0; k < j; ++k) {
                printf("dp[%d][%d] -> %d\n", k, j, dp[j][0] - dp[k + 1][0]);
                dp[j][i] = max(dp[j - 1][i], dp[j][0] - dp[k][0]);
                printf("dp[%d][%d] -> %d\n\n", j, i, dp[j][i]);
            }
        }
    }
    return dp[len][n - 1];
}

int max(int lo, int hi) {
    return lo > hi ? lo : hi;
}
