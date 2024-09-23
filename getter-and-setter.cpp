#include <iostream>
#include <string>

using namespace std;


class Teacher
{
private:
    float salary;
public:
    string name;
    int age;
    string dept;

    string changeDept(string newDept){
        dept = newDept;
        return dept;
    } 

    // setter
    void setSalary(float s){
        salary = s;
    }

    // getter
    float getSalary(){
        return salary;
    }

};


int main()
{

    Teacher t1;
    t1.name = "Ahad Ali";
    t1.age = 19;
    t1.setSalary(2500);

    cout << t1.name << endl;
    cout << t1.age << endl;
    cout << t1.getSalary() << endl;

    return 0;

}