#include <iostream>
using namespace std;

int Dec_To_Bin(int num){
    int pow=1,ans=0,rem;
    while(num>0){
        rem = num % 10 ;
        num/=10;
        ans+=(rem*pow);
        pow*=2;

    }
    return ans;
}

int main(){
    int num;
    cout << "Enter the number you want to Convert from Binary to decimal : ";
    cin >> num;
    cout << "The required decimal conversion from Binary Number : "<<num<<" is " <<Dec_To_Bin(num);
    return 0;
}