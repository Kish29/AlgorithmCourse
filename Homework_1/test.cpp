#include "Solution.h"
#include "iostream"

int array[max_n];

int main() {
/*
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }
    printf("%d", Solution::findMaxContinuousIntegers(array, 5));
*/
    std::string str;
    std::cin >> str;
    printf("%d", Solution::findMaxMatchBrackets(str));
}
