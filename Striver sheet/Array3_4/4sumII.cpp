#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                 vector<int>& nums3, vector<int>& nums4) {

    unordered_map<int, int> mp;

    // Store all possible sums of nums1 and nums2
    for(int i = 0; i < nums1.size(); i++) {
        for(int j = 0; j < nums2.size(); j++) {
            mp[nums1[i] + nums2[j]]++;
        }
    }

    int count = 0;

    // Find complementary sums from nums3 and nums4
    for(int i = 0; i < nums3.size(); i++) {
        for(int j = 0; j < nums4.size(); j++) {

            int sum = nums3[i] + nums4[j];

            if(mp.find(-sum) != mp.end()) {
                count += mp[-sum];
            }
        }
    }

    return count;
}

int main() {

    int n;

    cout << "Enter size of arrays: ";
    cin >> n;

    vector<int> nums1(n), nums2(n), nums3(n), nums4(n);

    cout << "Enter elements of nums1: ";
    for(int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter elements of nums2: ";
    for(int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    cout << "Enter elements of nums3: ";
    for(int i = 0; i < n; i++) {
        cin >> nums3[i];
    }

    cout << "Enter elements of nums4: ";
    for(int i = 0; i < n; i++) {
        cin >> nums4[i];
    }

    int ans = fourSumCount(nums1, nums2, nums3, nums4);

    cout << "\nNumber of valid quadruplets = " << ans << endl;

    return 0;
}