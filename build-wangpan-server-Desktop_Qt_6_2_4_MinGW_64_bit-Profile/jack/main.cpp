#include <iostream>
#include <vector>

using namespace std;

// ��ӡ����
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

// ����Ƿ�����ڵ�row�е�col�з��ûʺ�
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// �ݹ����ʺ�����
void solveNQueens(vector<int>& board, int row) {
    int N = board.size();
    if (row == N) {
        printBoard(board);  // ��ӡ��
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1);
            board[row] = -1; // ����
        }
    }
}

int main() {
    int N;
    cout << "������N�����̴�С����";
    cin >> N;

    vector<int> board(N, -1); // ��ʼ������
    solveNQueens(board, 0);

    return 0;
}
