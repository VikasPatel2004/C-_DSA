#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Check if it's safe to place a queen at board[row][col]
    bool isSafe(vector<string> &board, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    // Recursive backtracking function to place queens
    void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';         // Place queen
                nQueen(board, row + 1, n, ans); // Recurse
                board[row][col] = '.';         // Backtrack
            }
        }
    }

    // Main function to solve N-Queens
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); // Initialize empty board
        vector<vector<string>> ans;
        nQueen(board, 0, n, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "\nTotal solutions: " << solutions.size() << "\n\n";
    for (const auto &board : solutions) {
        for (const string &row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}