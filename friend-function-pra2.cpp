#include <iostream>
#include <string>

using namespace std;

class Complex {
    int a , b;
    friend Complex sumComplex(Complex o1, Complex o2);
    public:
        void setNum(int n1, int n2){
            a = n1; b = n2;
        }
        void showNum(){
            cout << "Your Num = " << a << " + " << b << "i" << endl;
        }
};
Complex sumComplex(Complex o1, Complex o2){
    Complex o3;
    o3.setNum((o1.a + o2.a) , (o1.b + o2.b));
    return o3;
}
int main()
{
    Complex c1, c2, sum;
    c1.setNum(1,4);
    c1.showNum();

    c2.setNum(5,2);
    c2.showNum();

    sum = sumComplex(c1, c2);
    sum.showNum();

    return 0;
}