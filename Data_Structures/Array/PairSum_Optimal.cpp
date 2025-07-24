#include  <iostream>
#include <vector>
using namespace std;

vector<int> PairSum(vector<int> &nums , int target){
int n = nums.size();
vector<int> ans ;
int i =0;
int j=n-1;
while(i<j){
    int pairsum = nums[i]+nums[j];
    if(pairsum<target){
        i++;
    }
    else if(pairsum>target){
        j--;
    }
    else{
       ans.push_back(nums[i]);
       ans.push_back(nums[j]);
       return ans;
    }
}
return ans ;
}

int main() {
    vector<int> nums ={1,2,3,4,5,6}; //this must be in ascending order
    int target = 10;
    vector<int> ans = PairSum(nums,target);
    cout <<ans[0] << " ," <<ans[1];
}