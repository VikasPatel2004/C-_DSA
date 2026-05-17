#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextsmaller(vector<int>& arr){
     vector<int> ans(arr.size()); // always mention arrays size in it 
     stack<int> st;

     for(int i = 0 ; i<=arr.size()-1;i++){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]); // to make it the top of stack

    }
    return ans;
}

int main(){
   
    vector<int> arr = {0,5,9,10,1};
   vector<int> ans = nextsmaller(arr);
    
    for(int val : ans){
        cout << val << " ";
    }

}