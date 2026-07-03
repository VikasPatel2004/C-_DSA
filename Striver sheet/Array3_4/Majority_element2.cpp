#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {

    int count1 = 0, count2 = 0;
    int candidate1 = 0, candidate2 = 1;

    // Step 1: Find the two potential candidates
    for(int num : nums) {

        if(num == candidate1) {

            count1++;
        }

        else if(num == candidate2) {

            count2++;
        }

        else if(count1 == 0) {

            candidate1 = num;
            count1 = 1;
        }

        else if(count2 == 0) {

            candidate2 = num;
            count2 = 1;
        }

        else {

            count1--;
            count2--;
        }
    }

    // Step 2: Verify the candidates
    count1 = 0;
    count2 = 0;

    for(int num : nums) {

        if(num == candidate1) {

            count1++;
        }

        else if(num == candidate2) {

            count2++;
        }
    }

    vector<int> ans;

    if(count1 > nums.size() / 3) {

        ans.push_back(candidate1);
    }

    if(count2 > nums.size() / 3) {

        ans.push_back(candidate2);
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

    vector<int> ans = majorityElement(nums);

    cout << "Majority Elements: ";

    for(int x : ans) {

        cout << x << " ";
    }

    cout << endl;

    return 0;
}