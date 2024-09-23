#include <iostream>
#include <string>

using namespace std;
 // Writing data in class is called Encapsulation.
class BankAccoun {
    double balance;   //hiding data
    int password;
public:
    int accountNum;
    string accountHodler;
    
};

int main()
{
    BankAccoun b1;
    b1.accountHodler = "Ahmad";
    cout << b1.accountHodler << endl;
    return 0;

}