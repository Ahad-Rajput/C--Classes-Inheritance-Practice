#include <iostream>
#include <string>
using namespace std;

class Aslam;
class Ali{
private:
    int money = 100;
    friend void Ahmad(Ali , Aslam);
};
class Aslam{
private:
    int money = 200;
    friend void Ahmad(Ali , Aslam);
};
void Ahmad(Ali f1, Aslam f2){
    cout << "Money = " << f1.money+f2.money << endl;
}

int main()
{
    Ali obj1; Aslam obj2;
    Ahmad(obj1,obj2);
}