#include <iostream>
#include <climits>
using namespace std;

int main(){
int n = 6;
int arr[] = {-1,2,3,4,-5,6};

int maxsum = INT_MIN;
for(int str =0 ; str<n;str++){
    int currsum = 0;
    for(int end =str;end<n;end++){
        // for(int i=str;i<end;i++){
        //     cout<<arr[i];      // for printing all the subarray 
        // }
        // cout<<" ";
      currsum+=arr[end];
      maxsum = max(currsum,maxsum);  //brutte force approach 
    }
    
}
    cout <<"the maxsum of the subarray of the given array is : "<<maxsum;
return 0;
}