#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Binary search within a single row
    bool SearchInRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;  // recalc each iteration
            if (matrix[row][mid] == target) {
                return true;
            } else if (target < matrix[row][mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return false;
    }
   
    // Binary search across rows
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int sR = 0, eR = m - 1;
        
        while (sR <= eR) {
            int midR = sR + (eR - sR) / 2;  // must be inside loop
            
            if (target >= matrix[midR][0] && target <= matrix[midR][n - 1]) {
                return SearchInRow(matrix, target, midR);
            } else if (target < matrix[midR][0]) {
                eR = midR - 1;
            } else {
                sR = midR + 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    cout << boolalpha; // print true/false instead of 1/0
    cout << sol.searchMatrix(matrix, 3) << endl;   // true
    cout << sol.searchMatrix(matrix, 13) << endl;  // false

    return 0;
}