#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {

    // Edge case
    if(nums.empty()) {
        return 0;
    }

    unordered_set<int> st;

    // Insert all elements into the set
    for(int num : nums) {
        st.insert(num);
    }

    int longest = 0;

    // Traverse the set (duplicates already removed)
    for(int num : st) {

        // Check if it is the starting element of a sequence
        if(st.find(num - 1) == st.end()) {

            int currentNum = num;
            int count = 1;

            // Count consecutive numbers
            while(st.find(currentNum + 1) != st.end()) {
                currentNum++;
                count++;
            }

            longest = max(longest, count);
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

    cout << "\nLength of Longest Consecutive Sequence = "
         << longestConsecutive(nums) << endl;

    return 0;
}