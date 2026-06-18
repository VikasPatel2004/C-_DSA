#include <iostream> 
using namespace std ;

class Person {
    // private :
    public : 
    string name ;
    
    Person( string name ){
    this->name = name ;
    }

    // void getvalues(){
    // cout << "name : " << name <<endl ;
    // }
};

class Student : public Person {
    public : 
    double id;
    Student( string name , double id) : Person(name){
      this->id  = id ;
    }
    void getInfo(){
        cout << "id : " << id << endl ;
        cout << "name : " << name << endl ;
    }
};
int main(){
    Student s1("Vikas" ,901) ; 
    s1.getInfo();
    return 0 ;

}