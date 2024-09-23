#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    virtual void show(){
        cout << "Student" << endl;
    }
};

class Inter_Std : public Student{
public:
    void show(){
        cout << "Inter_Student" << endl;
    }
};
class BS_Std : public Student{
public:
    void show(){
        cout << "BS_Student" << endl;
    }
};

int main()
{
    Student *S;
    Student obj1;
    Inter_Std obj2;
    BS_Std obj3;
    S = new Student;
    S = &obj1;
    S->show();
    S = &obj2;
    S->show();
    S = &obj3;
    S->show();

    return 0;
}