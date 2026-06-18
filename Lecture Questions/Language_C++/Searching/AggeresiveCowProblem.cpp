#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution{
    public:

    bool isPossible(vector<int> &arr , int cows , int minallowed){
        int laststallpos = arr[0] , cowcount = 1;
        for(int i = 0 ; i<arr.size() ; i++){
            if(arr[i]-laststallpos >= minallowed){
                cowcount++;
                laststallpos = arr[i];

                if(cowcount == cows){
                    return true;
                }
            }
        }
        return false;

    }


    int aggresiveCow(vector<int> &arr , int cows){
        sort(arr.begin(),arr.end());
        int N = arr.size()-1 , ans = -1;
        int st = 1 , end = arr[N]-arr[0]; // this the min search array in which our min value can exist

        while(st<=end){
            int mid = st+(end-st)/2;
            if(isPossible(arr,cows,mid)){
                ans = mid;
                st = mid+1 ;
            }
            else{
                end = mid-1;
            }

        }
        return ans;

    }

};

int main(){
    Solution s;
    vector<int> arr = {1,2,8,4,9}; // given stalls postions for cows 
    int cows = 3; // cows to be placed
    int Mindistance = s.aggresiveCow(arr,cows);
    cout << "the minimum distance between the stalls of aggresive cows is : " <<Mindistance;

    return 0;

}