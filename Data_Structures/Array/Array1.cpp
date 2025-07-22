#include <iostream>
#include <limits.h>
using namespace std ;

int main() {
    int size = 5;
    int marks[size];
    int smallest = INT_MAX;
    

    for (int i=0;i<size;i++){
        cout << "Enter the marks : ";
        cin>>marks[i];
    }
    
    for(int i=0;i<size;i++){
      // if (marks[i]<smallest){  //similarly we can do for max
      //   smallest = marks[i];
      // }
      smallest = min(marks[i],smallest); //since in C++ min and max are implecit func
    }
    for (int i=0;i<size;i++){
      if (smallest==marks[i]){
        cout<<"the index of the smallest number is : " <<i;
      }
    }
    return 0;
}