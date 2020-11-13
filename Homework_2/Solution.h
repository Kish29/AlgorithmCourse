//
// Created by asus on 2020/11/14.
//

#ifndef ALGORITHMCOURSE_SOLUTION_H
#define ALGORITHMCOURSE_SOLUTION_H

#include "cstdio"
#include "vector"
#include <malloc.h>
#include <cstring>

using std::vector;

const int max_n = 1000006;

class Solution {

public:
    static int pw(int x, int y, int p);

    static void findTwoPrimes(int loop, const int *a);

    static int allPrimesInN(int n);

    /* 非常高效的求n以内的素数*/
    static void initPrimes();

    /* 比上一个求素数还要高效 */
    static int allPrimesInNEfficient(int n);
};


#endif //ALGORITHMCOURSE_SOLUTION_H
