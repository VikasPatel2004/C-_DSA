#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    bool isvalid(vector<int> &arr , int k , int maxallowed){
        int pages=0 , student=1;
        for(int i = 0  ; i<=arr.size()-1 ; i++){
            if(pages+arr[i] <= maxallowed){
                pages+=arr[i];
            }
            else{
                student++;
                pages = arr[i];
            }

        }
        return student<=k; // this will verify if student is less than or equal to allowed student 

    }


        int BookAllocation(vector<int> &arr , int k){
        int Total = 0 , MinAllocation = 0 , ans = -1;
        for(int i = 0 ; i<=arr.size()-1; i++){
            MinAllocation = max(MinAllocation,arr[i]); // this will give us the minimum max allocation that should have to given to a single student 
            Total += arr[i];
        }

        int st=MinAllocation , end = Total;
        while(st<=end){
            int mid = st +(end-st)/2;
            if(isvalid(arr , k , mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }

};

int main(){
    Solution s;
    vector<int> arr = {12,34,67,90};
    int maxallowedpages = s.BookAllocation(arr,2);

    cout << "the maximum allowed pages are : " << maxallowedpages;

    return 0 ;

}