#include <iostream>
using namespace std;

int main(){

    //triangle number pattern
    int n =4;
    int num = 1;
    int m=n;
    // for (int i=0;i<n;i++){
    //     for(int j = 0;j<i+1;j++) {
    //        cout <<num; //also in place of num we can use i+1;
    //     }
    //    num++;
    //     cout << endl;
    // }

    //floyds triangle pattern
    // int numb =1;
    // for (int i=0;i<n;i++){
    //     for(int j = 0;j<i+1;j++) {
    //        cout <<numb; 
    //        numb++;
    //     }
    //     cout << endl;
    // }

     //forward trinagle

    // for (int i=0;i<n;i++){
    //     int num = 1; // Reset num for each row
    //     for(int j = 0;j<i+1;j++) {
    //        cout <<num; //also in place of num we can use j;
    //        num++;
    //     }
    //     cout << endl;
    //}

    //reverse triangle

    // for (int i=0;i<n;i++){
    //     for(int j=i+1;j>0;j--) {
    //        cout <<j; //also in place of num we can use j;
    //     }
    //     cout << endl;
    // }


    //inverted triangle pattern 

    // for (int i=0;i<n;i++){
    //     for(int j=0;j<i;j++) {
    //         cout << " "; // Print stars in increasing order
    //     }
    //     for (int j=0;j<m;j++) {  //in place of m we can use n-i
    //         cout<<num;  //in place of num we can print i+1
    //     }
    //     num++;
    //     m--;
    //     cout << endl;
    // }


    return 0;
};