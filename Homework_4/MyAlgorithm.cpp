//
// Created by asus on 2020/11/20.
//

#include "MyAlgorithm.h"

int getLeafNum(int n, int k) {
    if ((n + k) % 2 == 0 && n - k > 0)
        return getLeafNum((n + k) / 2, (n - k) / 2);
    else return 1;
}

int getMinDistance(int *array, int len) {
    quickSort(array, 0, len - 1);
    if (len % 2 == 0)
        return array[len / 2 - 1];
    else return array[len / 2];
}

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
