#include <iostream>

using namespace std;

class Number {
private:
    int num1, num2;

public:

    Number(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }

       friend void calculate(const Number& obj) {
        cout << "Addition: " << (obj.num1 + obj.num2) << endl;
        cout << "Subtraction: " << (obj.num1 - obj.num2) << endl;
    }
};

int main() {
    Number num(10, 5);
    calculate(num);
    return 0;
}