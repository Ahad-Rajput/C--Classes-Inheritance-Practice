#include <iostream>
using namespace std;

class A{
private:
    static int x;
public:
    A(){
        x++;
    }
    void show(){
        cout << "x : " << x << endl;
    }
};

int A::x = 0;

int main()
{
    A a;
    a.show();
    return 0;
}