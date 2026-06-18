#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans, vector<vector<bool>> &vis) {
    int n = mat.size();

    // Boundary and invalid checks
    if (r < 0 || c < 0 || r >= n || c >= n) return;
    if (mat[r][c] == 0) return;
    if (vis[r][c]) return;

    // Destination reached
    if (r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark visited
    vis[r][c] = true;

    // Explore all 4 directions
    helper(mat, r + 1, c, path + "D", ans, vis); // Down
    helper(mat, r, c + 1, path + "R", ans, vis); // Right
    helper(mat, r - 1, c, path + "U", ans, vis); // Up
    helper(mat, r, c - 1, path + "L", ans, vis); // Left

    // Backtracking step → unmark visited
    vis[r][c] = false;
}

vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    helper(mat, 0, 0, "", ans, vis);
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    vector<string> ans = findPath(mat);
    for (string path : ans) {
        cout << path << endl;
    }
}