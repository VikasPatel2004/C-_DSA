#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarray(vector<int>& nums, int k) {

    unordered_map<long long, int> mp;

    long long sum = 0;
    int longest = 0;

    for(int i = 0; i < nums.size(); i++) {

        sum += nums[i];

        // If prefix sum itself equals k
        if(sum == k) {
            longest = i + 1;
        }

        long long rem = sum - k;

        // Check if (sum - k) exists
        if(mp.find(rem) != mp.end()) {
            longest = max(longest, i - mp[rem]);
        }

        // Store first occurrence of prefix sum
        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return longest;
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

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Length of Longest Subarray = "
         << longestSubarray(nums, k) << endl;

    return 0;
}