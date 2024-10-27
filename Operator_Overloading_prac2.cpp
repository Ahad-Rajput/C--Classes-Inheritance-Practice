// ++a
#include <iostream>
using namespace std;

class A{
public:
    int n = 0;
    void show(){
        cout << "n : " << n << endl;
    }
    void operator ++ (){
        n = n+1;
    }
};

int main()
{
    A a;
    a.show();
    ++a;
    a.show();
    return 0;
}