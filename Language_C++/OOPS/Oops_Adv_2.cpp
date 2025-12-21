
// This oops concept is about shallow and deep copy using *ptr 

#include <iostream>
using namespace std;

class Student {

    private:
    string id;

    public : 
    string name ;
    double *cgpaPtr;

    Student(string name, double cgpa,string id){
        this->id = id;
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    Student(Student &obj){ //copy constructor with deep copy 
        this->id = obj.id;
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    void getInfo(){
        cout << " id : " << id <<endl;
        cout << " name : " << name <<endl;
        cout << " cgpa : " << *cgpaPtr <<endl;
    }

};


int main(){
    Student s1{"vikas", 9.8 , "0901AI231073"};
    Student s2(s1);

    *(s2.cgpaPtr) = 8.8;
    s1.getInfo();
    s2.getInfo();

}