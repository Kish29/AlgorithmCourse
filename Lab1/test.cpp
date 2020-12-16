//
// Created by 87569 on 2020/12/9.
//

#include "MyAgorithm.h"

int nums[max_n];

int main() {
    int len, n;
    scanf("%d%d", &len, &n);
    for (int i = 0; i < len; ++i) {
        scanf("%d", &nums[i]);
    }
    printf("%d", minDivide(nums, len, n));
    return 0;
}
