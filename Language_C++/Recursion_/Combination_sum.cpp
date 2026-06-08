#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(int idx,
               vector<int>& candidates,
               int target,
               vector<int>& current,
               vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(current);
            return;
        }

        if(idx >= candidates.size() || target < 0) {
            return;
        }

        // Take current element
        current.push_back(candidates[idx]);

        solve(idx,
              candidates,
              target - candidates[idx],
              current,
              ans);

        current.pop_back();

        // Skip current element
        solve(idx + 1,
              candidates,
              target,
              current,
              ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(0,
              candidates,
              target,
              current,
              ans);

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans =
        s.combinationSum(candidates, target);

    cout << "Combinations are:\n";

    for(auto vec : ans) {

        cout << "[ ";

        for(int x : vec) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}