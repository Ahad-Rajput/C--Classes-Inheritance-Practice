#include <iostream>
using namespace std;

class A{
private:
    static int x, n;
public:
    A(){
        x++;
        n++;
    }
    void show(){
        cout << "X : " << x << "  " << "n : " << n << endl;
    }
};

int A::x = 0;
int A::n = 1;

int main()
{
    A a, b, c, d, e;
    a.show();
    b.show();
    c.show();
    d.show(); 
    e.show(); 

    return 0;
}