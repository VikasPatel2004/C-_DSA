#include <iostream>
#include <vector> 
using namespace std ;

class Solution {
public:
int MajorityElement(vector<int>& nums){
    int freq = 0;
    int ans = 0 ;
    for ( int i = 0 ; i<nums.size(); i++){
        if(freq==0){
            ans = nums[i];
        }
        if(ans == nums[i]){
            freq++; 
        }
        else{
            freq--;
        }

    }

return ans;

}
};

int main(){
    vector<int> nums = {1,2,2,2,2,1,3};
    Solution obj ;
    cout << "The Given Majority Element is : " << obj.MajorityElement(nums);

}