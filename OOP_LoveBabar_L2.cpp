#include <iostream>
using namespace std;

class temp{
public:
    temp(){
        cout << "Value of this->" << this << "\n";
    }
};

int main()
{
    temp t1;
    cout << "Address of t1 : " << &t1 << endl;
    return 0;
}