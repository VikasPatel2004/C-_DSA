#include <iostream>
#include <vector>

using namespace std ; 

void helper(vector<vector<int>> &mat , int r , int c , string path , vector<string> &ans) {
  if (mat[r][c]==0){
    return ;
  }
  else if (r<0 && c<0){
    return ;
  }
  else if (r>=n && c>=n){
    return ;
  }
  else if (r==n-1&&c==n-1){
    ans.push_back(path);
    return;
  }

  vector<string> findPath(vector<vector<int>> &mat , int r , int c , string path , vector<string> &ans){
    string path = "";
    int n = 
    helper(mat,r,c,path,ans);
    return ans ;
  }


int main(){
    
    //we made a matrix of the problem 
      vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
      vector<string> ans = findPath(mat);
      for(string path : ans){
        cout << path <<endl ;
      }



 
}