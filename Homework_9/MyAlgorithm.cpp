//
// Created by 87569 on 2020/12/2.
//

#include "MyAlgorithm.h"


int f[100];

/*
 * left[i] = left[i-1] + up[i-1]
 * right[i] = right[i-1] + up[i-1]
 * up[i] = left[i-1] + right[i-1] + up[i-1]
 * ->> up[i] = f[i-1]
 * f[i] = left[i] + right[i] + up[i]
 *      = left[i-1] + up[i-1] + right[i-1] + up[i-1] + f[i-1]
 *      = f[i-1] + f[i-2] + f[i-1]
 *      = 2*f[i-1] + f[i-2]
 *
 * */

int matrixThrough(int n) {
    f[1] = 3, f[2] = 7;
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i - 2] + 2 * f[i - 1];
    }
    return f[n];
}


const int dp_len = 50;

bool dp[dp_len][dp_len];

/*
 * dp[i][j]表示std字符串前i位和check字符串前j位是否匹配
 * */

void wildCardMatch(const char *std, const char *check) {
    if (std == nullptr || check == nullptr) {
        printf("not matched");
        return;
    }
    int std_len = strlen(std), check_len = strlen(check);
    /* 置初值 false */
    memset(dp, false, dp_len * dp_len * sizeof(bool));
    dp[0][0] = true;
    /* 检查连续*字符串 */
    for (int i = 1; std[i - 1] == '*'; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; std[i - 1]; ++i) {
        /* 保证进入循环的std和check均不是'\0'*/
        for (int j = 1; check[j - 1]; ++j) {
            switch (std[i - 1]) {
                case '?':
                    dp[i][j] = dp[i - 1][j - 1];
                    break;
                case '*':
                    dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
                    break;
                default:
                    /* 注意 i-1 和 j-1 */
                    dp[i][j] = dp[i - 1][j - 1] && (std[i - 1] == check[j - 1]);
            }
        }
    }
    printf("%s", dp[std_len][check_len] ? "matched" : "not matched");
}


int dp_lis_sum[1003];

int maxSumOfLIS(int *nums, int len) {
    if (len == 1)
        return nums[0];
    if (len == 2)
        return nums[0] + nums[1];
    /* 数组初始化值为 0 */
    int tmp;
    for (int i = 0; i < len; ++i) {
        dp_lis_sum[i] = nums[i];
    }
    int res = dp_lis_sum[0];
    for (int i = 1; i < len; ++i) {
        /* 查找以前的元素 */
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                tmp = dp_lis_sum[j] + nums[i];
                dp_lis_sum[i] = tmp > dp_lis_sum[i] ? tmp : dp_lis_sum[i];
            }
        }
        if (res < dp_lis_sum[i])
            res = dp_lis_sum[i];
    }
    return res;
}
