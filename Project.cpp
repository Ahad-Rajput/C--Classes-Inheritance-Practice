#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int Max_Accounts = 50;

class Account{
private:
    string accountHolder;
    int accountNum;
    double balance;
public:
    // Default constructor
    Account() : accountHolder(""), accountNum(0), balance(0.0){}

    // Parameterized constructor
    Account(string name, int accNum, double initialBalance) : accountHolder(name), accountNum(accNum), balance(initialBalance){}

    // Accessor functions
    string getAccountHolder() const{return accountHolder}
    int getAccountNum() const{return accountNum}
    double getBalance() const{return balance}

    // Setter functions
    void setAccount(string name, int accNum, double initialBalance){
        accountHolder = name;
        accountNum = accNum;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(double amount){
        balance += amount;
    }

    // Withdraw money
    bool withdraw(double amount){
        if (amount < balance)
        {
            balance -= amount;
            return true;
        }
        return false
    }

    // Display account details
    void display(){
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNum << endl;
        cout << "Balance : " << fixed << setprecision(2) << balance << endl;
    }
};