// * :
#include <iostream>
using namespace std;

class Mult{
private:
    int a;
public: 
    Mult(){
        a = 0;
    }
    void in(){
        cout << "Enter a : ";
        cin >> a;
    }
    void show(){
        cout << "a = " << a << endl;
    }
    Mult operator * (Mult p){
        Mult temp;
        temp.a = this->a * p.a ;
        return temp;
    }

};

int main()
{
    Mult x, y, z;
    x.in();
    y.in();
    z = x * y;
    // x.show();
    // y.show();
    cout << "------\n";
    z.show();
    return 0;
}