// + :
#include <iostream>
using namespace std;

class Add{
private:
    int a;
public: 
    Add(){
        a = 0;
    }
    void in(){
        cout << "Enter a : ";
        cin >> a;
    }
    void show(){
        cout << "a = " << a << endl;
    }
    Add operator + (Add p){
        Add temp;
        temp.a = this->a + p.a ;
        return temp;
    }

};

main()
{
    Add x, y;
    x.in();
    y.in();
    z = x + y;
    // x.show();
    // y.show();
    cout << "------\n";
    z.show();
}