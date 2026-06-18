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

    Teacher(){
    // cout << "i am the constructor" <<endl;
    dept = "computer Science";
    }

    void ChangeDept(string newDept){
        dept = newDept;
    }

    void setSalary(double s){
        salary = s;
    }
    double getSalary(){
        return salary;
    }

    
};

int main(){
    Teacher t1,t2,t3;
    t1.name = "vikas";
    t1.setSalary(25000);


    cout << t1.name <<endl;
    cout << t1.getSalary() <<endl;
    cout << t1.dept <<endl;



};