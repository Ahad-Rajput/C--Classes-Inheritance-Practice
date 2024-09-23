#include <iostream>
#include <string>
using namespace std;

class student{
    public:
        string name;
        int roll_no;
        int marks;
        char grade;
        string department;
};

int main()
{

    student st1;
    st1.name = "Ahad Ali";
    st1.grade = 'A';
    st1.marks = 97;
    st1.roll_no = 23;
    st1.department = "Computer Science";
    cout << "Name = " << st1.name << endl;
    cout << "Roll No. = " << st1.roll_no << endl;
    cout << "Marks = " << st1.marks << endl;
    cout << "Grade = " << st1.grade << endl;
    cout << "Depratment = " << st1.department << endl;
    return 0;

}