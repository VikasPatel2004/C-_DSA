#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

class Solution{
    public: 
    int MajorityElement(vector<int>& nums){
        int n = nums.size();
        int maxFreq = 0 ;
        int MajorElem = nums[0];
        for (int i = 0 ; i<n ; i++){
            int freq = 1;
            for (int j = i+1 ; j < n ; j++){
                if (nums[j]==nums[i]){
                    freq++;
                }
                if (freq > maxFreq){
                    maxFreq = freq ; 
                    MajorElem = nums[i];
                }
            }
        }
        return MajorElem;


    }
    

};

int main(){
    vector<int> nums = {2,1,1,1,2,2,2};
    Solution obj;

    cout << "The Majority element in this case is : " << obj.MajorityElement(nums) ;
    return 0 ;


}