#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {

    int freq = 0;
    int ans = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(freq == 0) {
            ans = nums[i];
        }

        if(nums[i] == ans) {
            freq++;
        }
        else {
            freq--;
        }
    }

    return ans;
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

    int ans = majorityElement(nums);

    cout << "Majority Element = " << ans << endl;

    return 0;
}