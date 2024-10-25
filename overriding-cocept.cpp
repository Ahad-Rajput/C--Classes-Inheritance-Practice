#include <iostream>
using namespace std;

class Parent{
public:
    void hello(){
        cout << "Hello!" << endl;
    }
};

class Child : public Parent{
public:
    void hello(){
        cout << "Bye!" << endl;
    }
};

main()
{
    Parent p;
    Child c;
    p.hello();
    c.hello();
}