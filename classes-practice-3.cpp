#include <iostream>
#include <string>

using namespace std;

class Calculator {
private:
    int num1 , num2;
public:
    Calculator(int a , int b){
        num1 = a;
        num2 = b;
    }

    int sum();
    int sub();
    int mult();
    int div();
};

int Calculator :: sum(){
    int ans = num1 + num2;
    return ans;
}
int Calculator :: sub(){
    int ans = num1 - num2;
    return ans;
}
int Calculator :: mult(){
    int ans = num1 * num2;
    return ans;
}
int Calculator :: div(){
    int ans = num1 / num2;
    return ans;
}

int main()
{

    Calculator obj(5,6);
    cout << "Addition = " << obj.sum() << endl;
    cout << "Subtraction = " << obj.sub() << endl;
    cout << "Multiplication = " << obj.mult() << endl;
    cout << "Division = " << obj.div() << endl;
    return 0;

}