#include <iostream>
#include <string>

using namespace std;

class student {
public:
    student(){      // Constructor
        dept = "Computer Science";
    } 
    string name ;
    int age;
    int roll_no;
    string dept;
};

int main()
{
    student s1;
    student s2;
    s1.name = "Thomas";
    s2.name = "Arthur";
    s1.age = 19;
    cout << "Name = " << s1.name << endl;
    cout << "Department = " << s1.dept << endl;
    cout << "Name = " << s2.name << endl;
    cout << "Department = " << s2.dept << endl;

    return 0;

}