#include <iostream>
#include <vector>
using namespace std ;

int main(){
vector<int> arr = {1,2,3,4,5,6,7}; //this is in ascending order only
int n = arr.size();
int target = 5;
int start = 0;
int end = n-1;

while(start<=end){
    int mid = start+(end-start)/2;
    if(arr[mid]<target){
        start=mid+1;

    }
    else if (arr[mid]>target){
        end = mid-1;
    }
    else{
        cout << "target is being found at : " <<mid ;
        break;
    }
}
return 0;

}