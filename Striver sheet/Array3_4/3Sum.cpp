#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> result;

    // Sort the array
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for(int i = 0; i < n; i++) {

        // Skip duplicate values for i
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while(j < k) {

            int sumTriplet = nums[i] + nums[j] + nums[k];

            if(sumTriplet == 0) {

                result.push_back({nums[i], nums[j], nums[k]});

                j++;
                k--;

                // Skip duplicate values of j
                while(j < k && nums[j] == nums[j - 1]) {
                    j++;
                }

                // Skip duplicate values of k
                while(j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }

            else if(sumTriplet < 0) {
                j++;
            }

            else {
                k--;
            }
        }
    }

    return result;
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

    vector<vector<int>> ans = threeSum(nums);

    cout << "\nTriplets whose sum is 0:\n";

    if(ans.empty()) {
        cout << "No Triplets Found!";
    }
    else {
        for(auto triplet : ans) {

            cout << "[ ";

            for(int x : triplet) {
                cout << x << " ";
            }

            cout << "]" << endl;
        }
    }

    return 0;
}