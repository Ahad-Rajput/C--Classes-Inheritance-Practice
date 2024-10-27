// a++
#include <iostream>
using namespace std;

class A{
public:
    int n = 0;
    void show(){
        cout << "n : " << n << endl;
    }
    A operator ++ (int){
        A temp;
        n = n+1;
        temp.n = n;
        return temp;
    }
};

int main()
{
    A a;
    a.show();
    a++;
    a.show();
    return 0;
}