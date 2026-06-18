#include <iostream>
#include <vector>
#include <algorithm> // for max_element

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    for (int i = 0; i <= nums.size() - k; i++) {
        // get max in current window
        int windowMax = *max_element(nums.begin() + i, nums.begin() + i + k);
        result.push_back(windowMax);
    }
    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}