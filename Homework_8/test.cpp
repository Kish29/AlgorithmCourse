//
// Created by 87569 on 2020/11/27.
//

#include "MyAlgorithm.h"

int main() {
    int num;
    scanf("%d", &num);
    findMaxProductInFactor(num);
    printf("\n");
    for (int i = 1; i <= 100; ++i) {
        printf("%d-", i);
    }
    return 0;
}

