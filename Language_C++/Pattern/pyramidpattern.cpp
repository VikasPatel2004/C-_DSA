#include <iostream>
using namespace std;
int main(){
    int n = 4;
    int num = 1;
    for (int i =0;i<n;i++) {
       for(int j =0;j<n-i-1;j++){
        cout<<" "; // Print spaces for pyramid shape
       }
       for(int j =1;j<=i+1;j++){
        cout<<j; // Print numbers in increasing order
       }
       for(int j =i;j>0;j--){
        cout<<j;
       }
       cout <<endl;
    }
}