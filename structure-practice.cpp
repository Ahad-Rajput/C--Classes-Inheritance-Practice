#include <iostream>
#include <string>
using namespace std;

struct emp
{
    string name[5];
    int id[5];
    float salary[5];
};

int main()
{
    struct emp e;
    e.name[0] = "Ahad Ali";
    e.id[0] = 223;
    e.salary[0] = 20000;
    cout << "Employee Name : " << e.name[0] << endl;
    cout << "Employee ID : " << e.id[0] << endl;
    cout << "Employee Salary : " << e.salary[0] << endl;
    e.name[1] = "Jani";
    e.id[1] = 224;
    e.salary[1] = 20000;
    cout << "Employee Name : " << e.name[1] << endl;
    cout << "Employee ID : " << e.id[1] << endl;
    cout << "Employee Salary : " << e.salary[1] << endl;
    return 0;
}
