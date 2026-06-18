#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void merge(vector<int>& nums,
               int st,
               int mid,
               int end) {

        vector<int> temp;

        int i = st;
        int j = mid + 1;

        while(i <= mid && j <= end) {

            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        for(int idx = 0; idx < temp.size(); idx++) {
            nums[st + idx] = temp[idx];
        }
    }

    void mergeSort(vector<int>& nums,
                   int st,
                   int end) {

        if(st >= end) {
            return;
        }

        int mid = st + (end - st) / 2;

        mergeSort(nums, st, mid);

        mergeSort(nums, mid + 1, end);

        merge(nums, st, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {

        int st = 0;
        int end = nums.size() - 1;

        mergeSort(nums, st, end);

        return nums;
    }
};

int main() {

    Solution s;

    vector<int> nums = {5, 2, 3, 1};

    vector<int> ans = s.sortArray(nums);

    cout << "Sorted Array: ";

    for(int num : ans) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}