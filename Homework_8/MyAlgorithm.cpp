#include "MyAlgorithm.h"

int newMinInteger(int num, int del_num) {
    int a[12];
    int len = 0;
    while (num != 0) {
        a[len++] = num % 10;
        num /= 10;
    }
    for (int j = 0; j < del_num; ++j) {
        findMaxAndSetNull(a, len);
    }

    /* 逆序输出 */
    for (int j = len - 1; j >= 0; j--) {
        if (a[j] != -1)
            printf("%d", a[j]);
    }

    printf("\n");
    return 0;
}

void findMaxAndSetNull(int *a, int len) {
    int i = len - 1;
    int j;
    for (; i > 0; i--) {
        /* 找到不为 -1的下标 */
        for (j = i - 1; j >= 0; j--) {
            if (a[j] != -1)
                break;
        }
        if (a[j] < a[i])
            break;
    }
    a[i] = -1;
}

void findMaxProductInFactor(int num) {
    /* 1+2+3+...+141 > 10000*/
    int factors[150];
    /* 拆分出所有因子 */
    int k = 2;
    int i = 0;
    while (num >= k) {
        factors[i++] = k;
        num -= k;
        k++;
    }
    /* num 大于 0说明还有剩余元素 */
    if (num > 0) {
        /* 说明剩余的数刚好是已有因子数量+1 */
        if (num == i + 1) {
            /* 先让最末尾的因子+1 */
            factors[i - 1]++;
            num--;
        }
        /* 从后往前给每个因子数量+1 */
        for (int j = i - 1; j >= 0 && num > 0; j--) {
            factors[j]++;
            num--;
        }
    }
    /* 然后输出这个数组即可 */
    for (int j = 0; j < i; ++j) {
        printf("%d ", factors[j]);
    }
}
