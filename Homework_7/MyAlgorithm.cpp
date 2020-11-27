//
// Created by 87569 on 2020/11/27.
//

#include "MyAlgorithm.h"

const int max_n = 1e5 + 5;

/* 非降序序列 */
int array[max_n];

void findClosestTarget() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &array[i]);
    }

    int target_num;
    int target;
    int i, j, mid;
    scanf("%d", &target_num);
    for (int p = 0; p < target_num; ++p) {
        scanf("%d", &target);
        /* 二分查找 */
        i = 0, j = num - 1;
        /* 相隔一个数，保证mid和i、j不同 */
        while ((j - i) > 1) {
            mid = i + (j - i) / 2;
            if (array[mid] == target)
                i = j = mid;
            else if (target < array[mid])
                j = mid;
            else i = mid;
        }
        if (i == j) printf("%d\n", array[i]);
            /* j指向比target大的，i指向小的
             * 注意等于*/
        else if (target - array[i] <= array[j] - target)
            printf("%d\n", array[i]);
        else printf("%d\n", array[j]);
    }
}

void quick_sort(int *a, int lo, int hi) {
    if (hi <= lo)
        return;
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j - 1);
    quick_sort(a, j + 1, hi);
}

int getMinTickets(int *a, int len) {
    if (a == nullptr)
        return -1;
    if (len <= 1)
        return 1;
    quick_sort(a, 0, len - 1);
    int p = len / 2 - 1, q = len - 1;
    if (p < 0) p = 0;
    int dec = 0;
    while (p != -1) {
        if (a[p] * 2 <= a[q]) {
            dec++;
            q--;
        }
        /* 大数不能浪费 */
        p--;
    }
    return len - dec;
}

int partition(int *a, int lo, int hi) {
    int i = lo, j = hi + 1;
    int v = a[lo];
    while (true) {
        while (a[++i] < v) if (i == hi) break;
        while (a[--j] > v) if (j == lo) break;
        if (i >= j) break;
        swap(a, i, j);
    }
    swap(a, lo, j);
    return j;
}

void swap(int *a, int i, int j) {
    int tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
}
