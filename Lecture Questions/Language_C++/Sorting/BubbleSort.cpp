#include <iostream>
#include <vector>
using namespace std;

vector<int> BubbleSort(vector<int> &arr,int n){
    for(int i =0 ; i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr ;
}


int main(){
    int n = 5;
    vector<int> arr = {4,1,5,2,3};
    vector<int> ans = BubbleSort(arr,n);
    
    for(int num:ans){
        cout << num <<" ";

    }
    return 0;



}