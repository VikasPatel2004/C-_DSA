#include <iostream>
using namespace std;

void Reverse_Array(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main(){
    int size = 6;
    int arr[] = {1,2,3,4,5,6};

 Reverse_Array(arr,size);

 for (int i=0;i<size;i++){
    cout <<arr[i]<<" ";
 }
 cout <<endl;

    // for(int i=size-1;i>=0;i--){ // this way is good but it actually not reverse the array
    //    cout <<arr[i];           // as in memory the array will not be reversed 
    // }
};