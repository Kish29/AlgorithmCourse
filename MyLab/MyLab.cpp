//
// Created by 87569 on 2020/12/11.
//

#include "cmath"
#include "cstdio"
#include "sys/time.h"

const float precision = 1e-11;

double newTonRoot(double);

/* x * x - num = 0 */
double newTonRoot(double num) {
    if (num <= 0 || num == 1)
        return num;
    /* 计算x0 */
    /* 取x0 = num / 3 */
    double x0 = num / 3;
    double x1 = x0 - ((x0 * x0 - num) / (2 * x0));
    while (std::abs(x0 - x1) > precision) {
        x0 = x1;
        x1 = x0 - ((x0 * x0 - num) / (2 * x0));
    }
    return x1;
}

#include "ctime"

int main() {
    int num = 3000000;
    timeval start{}, end{};
    gettimeofday(&start, nullptr);
    double res = newTonRoot(num);
    gettimeofday(&end, nullptr);
    long us = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("res->%.20f\nduration time->%ldus", res, us);
    return 0;
}

