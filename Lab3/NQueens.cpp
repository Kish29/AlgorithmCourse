//
// Created by 87569 on 2020/12/16.
//

#include "NQueens.h"

static int res_num = 0;
static int max_bonus = INT32_MIN;

/* 存储给定的数字值 */
int **bonus;

int main() {
    /* 初始化随机数 */
    srand(time(nullptr));
    int N;
    scanf("%d", &N);
    /* 初始化bonus数组 */
    bonus = new int *[N]{};
    printf("Bonus is:\n");
    for (int i = 0; i < N; ++i) {
        bonus[i] = new int[N]{};
        for (int j = 0; j < N; ++j) {
            bonus[i][j] = rand() % N;
            printf("%d-", bonus[i][j]);
        }
        printf("\n");
    }
    auto res = NQueens(N);
    printf("The max bonus is %d\n", max_bonus);
    return 0;
}


vector<vector<string>> NQueens(int N) {
    /* 结果图 */
    auto res = vector<vector<string>>();
    /* 保存能够放置皇后的每一行的列号 */
    auto queens = vector<int>(N, -1);
    /* 存放放置的皇后列标，使用unordered_set存储唯一值 */
    auto columns = unordered_set<int>();
    auto diagonals1 = unordered_set<int>();
    auto diagonals2 = unordered_set<int>();
    backtrack(res, queens, N, 0, columns, diagonals1, diagonals2);
    return res;
}

void backtrack(vector<vector<string>> &res,
               vector<int> &queens, int N, int row,
               unordered_set<int> &columns,
               unordered_set<int> &diagonals1,
               unordered_set<int> &diagonals2) {
    /* 如果查找的范围结束(找到末尾行) */
    if (row == N) {
        /* 生成一个新的正确的棋谱图 */
        auto board = generateBoard(queens, N);
        res.push_back(board);
    } else {
        int diagonal1, diagonal2;
        /* 在当前行，从0行到N列开始查找符合条件的位置 */
        for (int i = 0; i < N; ++i) {
            /* 查找左斜对角线 */
            diagonal1 = row - i;
            /* 查找右斜对角线 */
            diagonal2 = row + i;
            if (columns.find(i) != columns.end() ||
                diagonals1.find(diagonal1) != diagonals1.end() ||
                diagonals2.find(diagonal2) != diagonals2.end()
                    ) {   // 如果当前列或者左斜对角线、右斜对角线有皇后放置，继续查找下一列
                continue;
            }
            /* 进入回溯 */
            queens[row] = i;
            columns.insert(i);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            backtrack(res, queens, N, row + 1, columns, diagonals1, diagonals2);
            diagonals2.erase(diagonal2);
            diagonals1.erase(diagonal1);
            columns.erase(i);
            queens[row] = -1;
        }
    }
}

/* 生成每一个棋谱图 */
vector<string> generateBoard(vector<int> &queens, int N) {
    res_num++;
    auto board = vector<string>();
    int tmp = 0;
    printf("The %d solution\n", res_num);
    for (int i = 0; i < N; ++i) {
        string row = string(N, 'X');
        /* 合适的位置放置皇后*/
        row[queens[i]] = 'Q';
        /* 计算当前最大值 */
        tmp += bonus[i][queens[i]];
        cout << row << endl;
        board.push_back(row);
    }
    /* 更新最大值 */
    max_bonus = max(max_bonus, tmp);
    printf("This method bonus is %d\n/////////////////////////////\n", tmp);
    return board;
}

void resultPrint(vector<vector<string>> &res) {
    for (int i = 0; i < res.size(); ++i) {
        printf("The %d solution\n", i + 1);
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << endl;
        }
        printf("/////////////////////////////\n");
    }
}
