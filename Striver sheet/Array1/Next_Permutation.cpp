#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {

    // Step 1: Find the Pivot
    int piv = -1;
    int n = nums.size();

    for(int i = n - 2; i >= 0; i--) {

        if(nums[i] < nums[i + 1]) {

            piv = i;
            break;
        }
    }

    // Step 2: If no pivot exists
    if(piv == -1) {

        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the next greater element
    for(int i = n - 1; i > piv; i--) {

        if(nums[i] > nums[piv]) {

            swap(nums[piv], nums[i]);
            break;
        }
    }

    // Step 4: Reverse the remaining part
    int i = piv + 1;
    int j = n - 1;

    while(i < j) {

        swap(nums[i], nums[j]);

        i++;
        j--;
    }
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    nextPermutation(nums);

    cout << "Next Permutation: ";

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}