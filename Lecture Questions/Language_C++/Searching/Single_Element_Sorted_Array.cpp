#include <iostream>
#include <vector>
using namespace std ;

int Single_Element( vector<int> &arr){
int start = 1;
int end = arr.size()-2;

while(start<=end){
    int mid = start+(end-start)/2;
    if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
        return mid;
    }
    if (mid%2==0){  //this means the left and right half is even
        if(arr[mid]==arr[mid-1]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    else{ // this means left and right half is odd
      if(arr[mid]==arr[mid-1]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

}
}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4,5,5};
    int start = 0;
    int end = 0;
    int result = Single_Element(arr);
    cout << "the index at which the element is reapeating is : "<<result;
    return 0;
    

}