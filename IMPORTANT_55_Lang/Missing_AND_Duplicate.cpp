#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int N = grid.size() * grid.size(); // total number of elements
        vector<int> freq(N+1, 0);          // frequency array

        // Count frequencies
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                freq[grid[i][j]]++;
            }
        }

        int duplicate = -1, missing = -1;

        // Find duplicate and missing
        for (int i = 1; i <= N; i++) {
            if(freq[i] == 2) {
                duplicate = i;
            }
            if(freq[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> grid1 = {{1,3},{2,2}};
    vector<int> ans1 = sol.findMissingAndRepeatedValues(grid1);
    cout << "Output for grid1: [" << ans1[0] << "," << ans1[1] << "]" << endl;

    // Example 2
    vector<vector<int>> grid2 = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> ans2 = sol.findMissingAndRepeatedValues(grid2);
    cout << "Output for grid2: [" << ans2[0] << "," << ans2[1] << "]" << endl;

    return 0;
}