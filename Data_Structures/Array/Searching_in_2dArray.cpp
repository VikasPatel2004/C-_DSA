class Solution {
public:
    bool searchinrow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == matrix[row][mid]) {
                return true;
            } else if (target > matrix[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, erow = m - 1;

        while (srow <= erow) {
            int midrow = srow + (erow - srow) / 2;

            if (target >= matrix[midrow][0] && target <= matrix[midrow][n - 1]) {
                return searchinrow(matrix, target, midrow);
            } else if (target > matrix[midrow][n - 1]) {
                srow = midrow + 1;
            } else {
                erow = midrow - 1;
            }
        }

        return false;
    }
};