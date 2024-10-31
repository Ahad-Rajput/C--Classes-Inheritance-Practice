// + :
#include <iostream>
using namespace std;

class Subtract{
private:
    int a;
public: 
    Subtract(){
        a = 0;
    }
    void in(){
        cout << "Enter a : ";
        cin >> a;
    }
    void show(){
        cout << "a = " << a << endl;
    }
    Subtract operator - (Subtract p){
        Subtract temp;
        temp.a = this->a - p.a ;
        return temp;
    }

};

int main()
{
    Subtract x, y, z;
    x.in();
    y.in();
    z = x - y;
    // x.show();
    // y.show();
    cout << "------\n";
    z.show();
    return 0;
}