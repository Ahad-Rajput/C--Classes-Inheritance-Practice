#include <iostream>
using namespace std;

class Demo{
public:
    Demo(){
        cout << "Simple Constructor is called" << endl;
    }
    ~Demo(){
        cout << "Destructor is called" << endl;
    }
};

int main()
{
    //Static Allocation
    Demo d1;
    
    //Dynamic Allocation
    Demo *d2;
    d2 = new Demo;
    delete d2;  // Manually invoked Destructor
    
    return 0;
}

