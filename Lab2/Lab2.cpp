//
// Created by 87569 on 2020/12/11.
//

#include "Lab2.h"


void quickSort(int *array, int lo, int hi) {
    if (hi <= lo)
        return;
    int j = partition(array, lo, hi);
    quickSort(array, lo, j - 1);
    quickSort(array, j + 1, hi);
}

int partition(int *array, int lo, int hi) {
    int i = lo, j = hi + 1;
    int v = array[lo];
    while (true) {
        while (array[++i] < v) if (i == hi) break;
        while (array[--j] > v) if (j == lo) break;
        if (i >= j) break;
        swap(array, i, j);
    }
    swap(array, lo, j);
    return j;
}

void swap(int *array, int lo, int hi) {
    int tmp = array[hi];
    array[hi] = array[lo];
    array[lo] = tmp;
}

int gap[max_n];

int getMinCompressSong() {
    int song_n;
    int disk_size;
    int tmp = 0;
    scanf("%d%d", &song_n, &disk_size);
    int res = song_n;
    int origin_size, after_size;
    for (int i = 0; i < song_n; ++i) {
        scanf("%d%d", &origin_size, &after_size);
        tmp += after_size;
        if (tmp > disk_size)
            return -1;
        gap[i] = origin_size - after_size;
    }

    quickSort(gap, 0, song_n - 1);
    for (int i = 0; i < song_n; ++i) {
        if (tmp + gap[i] <= disk_size) {
            tmp += gap[i];
            res--;
        } else break;
    }
    return res;
}

void getMaxCash() {
    int group_num;
    int box_num;
    scanf("%d", &group_num);
    for (int i = 0; i < group_num; ++i) {
        scanf("%d", &box_num);
        for (int j = 0; j < box_num; ++j) {
            scanf("%d", &gap[j]);
        }
        printf("%d\n", doSearch(gap, 0, box_num - 1));
    }
}

int dp[max_n];

int doSearch(const int *a, int lo, int hi) {
    for (int i = lo; i <= hi; ++i) {
        dp[i] = a[i];
        dp[i] = max(dp[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[hi];
}

int max(int lo, int hi) {
    return lo > hi ? lo : hi;
}


