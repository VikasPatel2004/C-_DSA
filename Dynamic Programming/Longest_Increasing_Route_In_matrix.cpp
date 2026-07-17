#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        // Memoization base case
        if (dp[i][j] != -1) return dp[i][j];

        int up = 1, down = 1, left = 1, right = 1;

        // Explore neighbors only if they are strictly greater
        if (i > 0 && matrix[i-1][j] > matrix[i][j])
            up = 1 + dfs(i-1, j, m, n, matrix, dp);
        if (j > 0 && matrix[i][j-1] > matrix[i][j])
            left = 1 + dfs(i, j-1, m, n, matrix, dp);
        if (i < m-1 && matrix[i+1][j] > matrix[i][j])
            down = 1 + dfs(i+1, j, m, n, matrix, dp);
        if (j < n-1 && matrix[i][j+1] > matrix[i][j])
            right = 1 + dfs(i, j+1, m, n, matrix, dp);

        // Store and return the maximum path length
        return dp[i][j] = max({up, down, left, right});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Try DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, m, n, matrix, dp));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << "Longest Increasing Path: " 
         << sol.longestIncreasingPath(matrix) << endl;

    return 0;
}
