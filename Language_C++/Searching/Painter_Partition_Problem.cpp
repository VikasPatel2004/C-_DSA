#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int N,int M,int maxAllowed){
    int painter = 1 , time = 0;
for(int i=0;i<N;i++){
    if(arr[i]>maxAllowed){
        return false;
    }
    else if(time+arr[i]<=maxAllowed){
        time+=arr[i];
    }
    else{
     painter++;
     time = arr[i];
    }
}
return painter<=M;
}

int Painter_Partition(vector<int> &arr,int N,int M){
    int sum=0;
    for(int i=0;i<N;i++){
    sum+=arr[i];
    }

    int start = arr[0];
    int end = sum;
    int mid = 0;
    int ans = 0;

    while(start<=end){
       mid = start+(end-start)/2;
       if(isValid(arr,N,M,mid)) {
        ans = mid;
        end = mid-1; // trying to find more smaller 
       }
       else{
        start = mid + 1;
       }
    }
    return ans;

}



int main(){
    vector<int> arr = {40,30,10,20};
    int N = 4 , M =2;
   int Min_Time = Painter_Partition(arr,N,M);
   cout << "the minimum time taken by the painters is : " <<Min_Time;
   return 0;
}
