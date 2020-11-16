//
// Created by asus on 2020/11/16.
//

#ifndef ALGORITHMCOURSE_SOLUTION_H
#define ALGORITHMCOURSE_SOLUTION_H

#include "string"

const int max_n = 1e5 + 5;

class Solution {
public:
    /* 最小元字符串问题 */
    static int findMinBasicStr(const std::string &str);

    static bool isMirrorEqualTo(const std::string &str1, const std::string &str2);

    /* 动态规划问题 */
    static int findMaxTraverseTime(const int *array, int len);

};


#endif //ALGORITHMCOURSE_SOLUTION_H
