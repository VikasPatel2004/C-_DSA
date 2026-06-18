#include <iostream> 
using namespace std ;

class Person{
public: 
string name;

};

class Student : public Person {
public: 
string id;
};

class Team : public Student {
public:
string group ;
};

int main(){
    Team s1 ;
    s1.name = "Vikas";
    s1.id = "9120";
    s1.group = "yellow";

    cout <<s1.name<<endl;
    cout <<s1.id<<endl;
    cout <<s1.group<<endl;



}