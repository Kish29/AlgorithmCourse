//
// Created by 87569 on 2020/12/16.
//

#ifndef ALGORITHMCOURSE_NQUEENS_H
#define ALGORITHMCOURSE_NQUEENS_H

#include "vector"
#include "string"
#include "iostream"
#include "unordered_set"
#include "ctime"

using namespace std;

/* 使用集合回溯方法求解N皇后问题
 * 使用columns、diagonals1、diagonals2记录列、左斜线、右斜线的皇后放置位置
 * 左斜列，行号-列号= 当前遍历的i
 * 右斜列，行号+列号= 当前遍历的i
 * */

/* 返回一个二维数组，分别是第一行的皇后放在0 ~ n-1列的枚举情况 */
vector<vector<string>> NQueens(int N);

void backtrack(vector<vector<string>> &res,
               vector<int> &queens, int N, int row,
               unordered_set<int> &columns,
               unordered_set<int> &diagonals1,
               unordered_set<int> &diagonals2);

/* 生成结果棋谱函数 */
vector<string> generateBoard(vector<int> &queens, int N);

/* 结果打印 */
void resultPrint(vector<vector<string>> &res);


#endif //ALGORITHMCOURSE_NQUEENS_H
