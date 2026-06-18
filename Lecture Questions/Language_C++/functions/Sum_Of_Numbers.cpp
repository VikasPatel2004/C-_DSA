#include <iostream>
using namespace std ;

int SumOfNum(int n) {
    int sum=0;
    for (int i=0;i<n;i++){
    sum = sum +i;
}
return sum;
}

int main () {
int n ;
cout<<"Enter the Number of Interger You Want Sum of :";
cin >>n;
cout << "sum of the number is :"<< SumOfNum(n);
}