//
// Created by 87569 on 2020/12/9.
//

#include <cstdint>
#include "MyAgorithm.h"

int dp[max_n][max_n];  // 表示前j个数字用掉i各分隔号的最大值最小的数

int getDiceNum(int n) {
    if (n == 1)
        return 1;
    int dice = 0;
    /* 计算摇到1~n-1步的情况*/
    for (int i = 1; i <= n - 1; i++) {
        dice += getDiceNum(n - i);
    }
    /* 一步到位的方法一次 */
    return dice + 1;
}

/* 使用二分查找法，lo左边界max(nums[i])，hi右边界sum(nums) */
int minDivide(const int *nums, int len, int n) {
    long lo = nums[0], hi = 0;
    /* lo取max(nums[i])*/
    for (int i = 0; i < len; ++i) {
        hi += nums[i];
        lo = lo > nums[i] ? lo : nums[i];
    }
    int cnt, tmp, mid; /*cnt是查找过程中分割的子数组数量*/
    while (lo < hi) {
        tmp = 0;
        cnt = 1;
        mid = (lo + hi) / 2;
        for (int i = 0; i < len; ++i) {
            tmp += nums[i];
            /* 查找到的结果满足要求，子数组数量+1，更新tmp */
            if (tmp > mid) {
                tmp = nums[i];
                cnt++;
            }
        }
        if (cnt > n)    // 取的mid偏小，导致更多的子数组满足要求
            lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
