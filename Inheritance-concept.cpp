#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    void hello(){
        cout << "Hello world !";
    }
};

class Student : public Person {
public:
    void set_values(string name , int age){
        this->name = name ;
        this->age = age;
    }
    void printing(){
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
    }
};

int main()
{
    Student obj;
    obj.set_values("Ahad", 19);
    obj.printing();
    obj.hello();
    return 0;
}