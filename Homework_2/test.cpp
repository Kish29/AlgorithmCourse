//
// Created by asus on 2020/11/14.
//

#include "Solution.h"

int array[max_n];

int main() {
    int loop;
    scanf("%d", &loop);
    for (int i = 0; i < loop; ++i) {
        scanf("%d", &array[i]);
    }
    Solution::findTwoPrimes(loop, array);
    return 0;
}
