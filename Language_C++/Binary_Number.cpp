#include <iostream>
using namespace std;

int BinaryNumConv(int num){
    int pow=1,ans=0,rem;
    while(num > 0){
        rem = num % 2;
        num/=2;
        ans+=(rem*pow);
        pow*=10;
    }
    return ans;
}

int main (){
    int num ;
    cout << "Enter the num you want to convert in binary : ";
    cin >>num;
    cout << "the binary conversion of the number is : " <<BinaryNumConv(num);


}