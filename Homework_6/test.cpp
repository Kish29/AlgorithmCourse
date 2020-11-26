//
// Created by 87569 on 2020/11/26.
//

#include "MyAlgorithm.h"

char str[100];

int main() {
    scanf("%s", &str);
    int num;
    scanf("%d", &num);
    int min = getMinFee(str, num);
    printf("%d", min);
    return 0;
}
