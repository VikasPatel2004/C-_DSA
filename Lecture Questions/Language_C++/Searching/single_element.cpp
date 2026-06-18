#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {

    int st = 0;
    int end = nums.size() - 1;

    while(st < end) {

        int mid = st + (end - st) / 2;

        // Make mid even
        if(mid % 2 == 1) {
            mid--;
        }

        if(nums[mid] == nums[mid + 1]) {
            st = mid + 2;
        }
        else {
            end = mid;
        }
    }

    return nums[st];
}

int main() {

    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    int ans = singleNonDuplicate(nums);

    cout << "Single Element = " << ans << endl;

    return 0;
}