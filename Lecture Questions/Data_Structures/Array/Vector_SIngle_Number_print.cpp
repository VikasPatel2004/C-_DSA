#include <iostream>
#include <vector>
using namespace std;

int Sigle_No_Print(vector<int>& nums){
    int ans =0;
    for(int val:nums){
        ans ^=val;
    }
    return ans;

}

int main(){
    vector<int> nums = {4,4,3,3,1};
    int Unique = Sigle_No_Print(nums);
    cout << "The Single Number is : " <<Unique;
    return 0;
}