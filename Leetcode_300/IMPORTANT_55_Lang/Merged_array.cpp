#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Result container
        vector<vector<int>> merged;

        // Step 3: Iterate through intervals
        for (auto interval : intervals) {
            // Case 1: If merged is empty OR no overlap
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } 
            // Case 2: Overlap → merge
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    // Call function
    vector<vector<int>> result = sol.merge(intervals);

    // Print output
    cout << "Merged Intervals: ";
    for (auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

    return 0;
}