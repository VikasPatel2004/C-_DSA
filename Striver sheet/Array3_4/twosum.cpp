#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int, int> mp;

    for(int i = 0; i < nums.size(); i++) {

        int need = target - nums[i];

        if(mp.find(need) != mp.end()) {

            return {mp[need], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    if(ans.empty()) {
        cout << "No pair found.";
    }
    else {
        cout << "Indices are: " << ans[0] << " " << ans[1];
    }

    return 0;
}