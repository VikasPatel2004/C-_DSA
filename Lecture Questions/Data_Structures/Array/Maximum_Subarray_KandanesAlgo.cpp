#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n = 6;
    int arr[] = {-3,-6,-1,3,5,6};
    int maxsum = INT_MIN;
    int currsum =0;
    for(int i=0;i<n;i++){
       currsum += arr[i];
       maxsum = max(maxsum,currsum);
       if (currsum<0){
         currsum =0;
       }
    }
    cout <<maxsum;
}