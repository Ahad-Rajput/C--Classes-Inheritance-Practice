#include <iostream>
using namespace std;

class Demo{
private:
    int num1;
public:
    int num2;
    static int num3;

    void setNum1(){
        num1 = 3;
    }
    void setNum2(){
        num1 = 4;
    }
    static int setNum3(){
        return num3;
    }

};
int Demo::num3 = 5;

int main()
{
    cout << "Static Variable : " << Demo::num3 << endl;
    cout << "Static Function : " << Demo::setNum3() << endl;
    cout <<"Size of Demo Class : "<< sizeof(Demo) << endl;
    
    return 0;
}