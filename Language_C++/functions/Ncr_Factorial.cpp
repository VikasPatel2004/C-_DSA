#include <iostream>
using namespace std;

int factorial(int n){
int fact =1;
for (int i=1;i<=n;i++){
    fact*=i;
}
return fact;
}
int nCr_Num(int n,int r){
    int fact_n = factorial(n);
    int fact_r = factorial(r);
    int fact_nMr = factorial(n-r);

    return fact_n/(fact_r*fact_nMr);
}

int main(){
    int n,r;
    cout <<"Enter value of n : ";
    cin >> n;
    cout << "Enter value of r : ";
    cin >> r;
    cout << "the nCr is : " <<nCr_Num(n,r)<<endl;
};