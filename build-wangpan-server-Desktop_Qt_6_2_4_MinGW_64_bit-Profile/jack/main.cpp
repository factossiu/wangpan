#include <iostream>
#include <vector>

using namespace std;

// 打印棋盘
void printBoard(const vector<int>& board) {
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// 检查是否可以在第row行第col列放置皇后
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// 递归解决皇后问题
void solveNQueens(vector<int>& board, int row) {
    int N = board.size();
    if (row == N) {
        printBoard(board);  // 打印解
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1);
            board[row] = -1; // 回溯
        }
    }
}

int main() {
    int N;
    cout << "请输入N（棋盘大小）：";
    cin >> N;

    vector<int> board(N, -1); // 初始化棋盘
    solveNQueens(board, 0);

    return 0;
}
