//
// Created by asus on 2020/11/16.
//

#include "Solution.h"

int springs[max_n];

int main() {
/*
    std::string str;
    std::cin >> str;
    printf("%d", Solution::findMinBasicStr(str));
*/
    int len;
    scanf("%d", &len);
    for (int i = 0; i < len; ++i) {
        scanf("%d", &springs[i]);
    }
    printf("%d", Solution::findMaxTraverseTime(springs, len));
    return 0;
}

