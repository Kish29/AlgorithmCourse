//
// Created by 87569 on 2020/12/9.
//

#include "MyAgorithm.h"

int nums[max_n];


bool check(int *nums, int len, int x, int m) {
    long long sum = 0;
    int cnt = 1;
    for (int i = 0; i < len; i++) {
        if (sum + nums[i] > x) {
            cnt++;
            sum = nums[i];
        } else {
            sum += nums[i];
        }
    }
    return cnt <= m;
}

int splitArray(int *a, int length, int num) {
    long long lo = 0, hi = 0;
    for (int i = 0; i < length; i++) {
        hi += a[i];
        if (lo < a[i]) {
            lo = a[i];
        }
    }
    while (lo < hi) {
        long long mid = (lo + hi) >> 1;
        if (check(a, length, mid, num)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {

    int n;
    int split_num;
    scanf("%d%d", &n, &split_num);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    printf("%d", splitArray(nums, n, split_num));
}
