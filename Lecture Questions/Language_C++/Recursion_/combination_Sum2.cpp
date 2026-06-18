#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void solve(int idx,
               vector<int>& candidates,
               int target,
               vector<int>& combination,
               vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(combination);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {

            // Skip duplicate elements
            if(i > idx &&
               candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted
            if(candidates[i] > target) {
                break;
            }

            combination.push_back(candidates[i]);

            solve(i + 1,
                  candidates,
                  target - candidates[i],
                  combination,
                  ans);

            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> combination;

        solve(0,
              candidates,
              target,
              combination,
              ans);

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans =
        s.combinationSum2(candidates, target);

    cout << "Combinations are:\n";

    for(auto vec : ans) {

        cout << "[ ";

        for(int num : vec) {
            cout << num << " ";
        }

        cout << "]\n";
    }

    return 0;
}