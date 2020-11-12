//
// Created by asus on 2020/11/11.
//

#ifndef ALGORITHMCOURSE_SOLUTION_H
#define ALGORITHMCOURSE_SOLUTION_H

#include "cstdio"
#include "cstring"
#include "stack"
#include "string"

const int max_n = 1000006;

class Solution {

public:

    /* 时间复杂度为 O(n)*/
    static int findMaxContinuousIntegers(const int *a, int len);

    /* 时间复杂度为 O(n)*/
    static int findMaxMatchBrackets(std::string str);
};

#endif //ALGORITHMCOURSE_SOLUTION_H
