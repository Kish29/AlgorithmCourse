//
// Created by asus on 2020/11/20.
//

#include "MyAlgorithm.h"
#include "cstdio"

const int max_n = 1e5 + 5;

int array[max_n];

int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d", getMinDistance(array, n));
    return 0;
}