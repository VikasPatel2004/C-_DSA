
// This oops concept is about constructor and this function and copu constructor

#include <iostream>
using namespace std;

class Teacher{
    private:
    double salary;

    public: 
    string name;
    string dept;
    string mobile;
    string subject;

    Teacher(string name , string dept ,double salary){
    cout << "i am the constructor" <<endl;
    this->name = name;
    this->dept = dept;
    this->salary = salary;
    }

    Teacher(Teacher &orgObj){ // we can create our own copy constructor from this 
       cout << "i am the copy constructor"<<endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->salary = orgObj.salary;
    }



    void ChangeDept(string newDept){
        dept = newDept;
    }

    // void setSalary(double s){
    //     salary = s;
    // }
    // double getSalary(){
    //     return salary;
    // }

    void getInfo(){
        cout <<"name : " << name <<endl;
        cout <<"dept : " << dept << endl;
        cout <<"salary : " << salary <<endl;
    }

    
};

int main(){
    Teacher t1("vikas","cs",25000);
    Teacher t2(t1); // if no copy const was made defalut const is being called.

    t2.getInfo();
};