#include <iostream>
using namespace std;

int main (){
    int n=4;
    int m =3;
    for(int i = 0;i<n;i++){
        for(int j =0;j<n-i-1;j++){
            cout <<" ";
        }
        for(int j =1;j<2;j++){
            cout<<"*";
        }
       if(i!=0){
         for(int j=0;j<2*i-1;j++){
            cout<<" ";
        }
        for(int j =1;j<2;j++){
            cout<<"*";
        }
       }
        cout<<endl;
    }

    for(int i=0;i<n-1;i++){
        for(int j =0;j<i+1;j++){
            cout<<" ";
        }
         cout<<"*";

         if(i!=n-2){
            for(int j=0;j<2*(n-i)-5;j++){
                cout<<" ";
            }
            cout<<"*";
         }
        
        cout<<endl;

    }

};