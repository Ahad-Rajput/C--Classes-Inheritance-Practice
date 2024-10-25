#include <iostream>
using namespace std;

class A{
public:
    virtual void show(){
        cout << "A";
    }
};

class B : public A{
public:
    void show(){
        cout << "B";
    }
};

class C : public A{
public:
    void show(){
        cout << "C";
    }
};


int main()
{
    A *ptr;
    A a;
    B b;
    C c;
    ptr = &a;
    ptr->show();
    ptr = &b;
    ptr->show();
    ptr = &c;
    ptr->show();
    return 0;
}