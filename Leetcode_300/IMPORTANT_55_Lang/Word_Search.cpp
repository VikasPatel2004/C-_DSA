#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (wordSearch(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool wordSearch(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        // Base case: all characters matched
        if (idx == word.size()) return true;

        // Boundary + mismatch check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore 4 directions
        bool found = wordSearch(board, word, i+1, j, idx+1) ||
                     wordSearch(board, word, i-1, j, idx+1) ||
                     wordSearch(board, word, i, j+1, idx+1) ||
                     wordSearch(board, word, i, j-1, idx+1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";

    Solution sol;
    cout << boolalpha << sol.Exist(board, word) << endl; // true
}