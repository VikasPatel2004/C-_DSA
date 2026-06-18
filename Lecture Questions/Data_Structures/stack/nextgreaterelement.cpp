#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    // int arr[] ={6,8,0,1,3};
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans(arr.size(),0); //starting from index 0 and ending at size of arr
    stack<int> s;

    for(int i = arr.size()-1 ; i>=0 ; i--){
        while(!s.empty() && s.top()<=arr[i] ){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        } else {
            ans[i]=s.top();
        }

        s.push(arr[i]);
    }
    for(int val : ans){
        cout << val << ",";
    }
    cout << endl;
    return 0 ;
}
