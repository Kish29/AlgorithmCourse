//
// Created by 87569 on 2020/12/2.
//

#include "MyAlgorithm.h"

int nums[1003];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    printf("%d", maxSumOfLIS(nums, n));
    return 0;
}