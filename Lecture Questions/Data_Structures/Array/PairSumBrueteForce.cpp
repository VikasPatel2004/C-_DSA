#include <iostream>
#include <vector>
using namespace std ;


vector<int> PairSum(vector<int>nums,int target){
    int n = nums.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (nums[i]+nums[j] == target){
              ans.push_back(nums[i]);
              ans.push_back(nums[j]);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {7,2,3,8,4};
    int target = 9;
    vector<int> ans = PairSum(nums,target);
    cout << "the given pair of sum equals target is " << ans[0] <<", " <<ans[1];
     return 0;

}