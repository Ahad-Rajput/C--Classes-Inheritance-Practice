#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int Max_Accounts = 50;

class Account{
private:
    string accountHolder[Max_Accounts];
    int accountNum[Max_Accounts];
    double balance[Max_Accounts];
    int totalAccounts, nextAccountNum;
    
    int findAccountIndex(int accNum){
        for (int i = 0; i < totalAccounts; i++)
        {
            if(accountNum[i] == accNum){
                return i;
            }
        }
        return -1;
    }

    void displayAccount(int index) const{
        cout << "Account Holder Name : " << accountHolder[index] << endl;
        cout << "Balance : " << fixed << setprecision(3) << balance[index] << endl;
    }

    void loadAccount(){
        ifstream in("Accounts_Details.txt");
        if(!in.is_open()){
            return;
        }

        in >> nextAccountNum;
        in >> totalAccounts;

        in.ignore();
        for (int i = 0; i < totalAccounts; i++)
        {
            getline(in, accountHolder[i]);
            in >> accountNum[i];
            in >> balance[i];
            in.ignore();
        }
        in.close();
    }

    void saveAccount() const{
        ofstream out("Accounts_Details.txt");
        if(!out.is_open()){
            return;
        }

        out << nextAccountNum << '\n';
        out << totalAccounts << '\n'; 

        for (int i = 0; i < totalAccounts; i++)
        {
            out << accountHolder[i] << '\n';
            out << accountNum[i] << '\n';
            out << balance[i] << '\n';
        }
        out.close();
    }

public: 
    Account():totalAccounts(0),nextAccountNum(201){
        loadAccount();
    } 
    ~Account(){
        saveAccount();
    }

    void createAccount(){
        if(totalAccounts >= Max_Accounts){
            cout << "Cannot create more accounts. Maximum limit reached.\n";
            return;
        }

        string name;
        double initialBalance;

        cout << "Enter Account Holder's Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Inital Balance : ";
        cin >> initialBalance;

        accountHolder[totalAccounts] = name;
        accountNum[totalAccounts] = nextAccountNum++;
        balance[totalAccounts] = initialBalance;

        cout << "\n---------------------------------------\n\n";
        cout << "> Account Holder : " << accountHolder[totalAccounts] << endl;
        cout << "> Balance : " << balance[totalAccounts] << endl;
        cout << "> Your Account Number : " << accountNum[totalAccounts] << endl;

        totalAccounts++;
    }
    
    void checkBalance(){
        int accNum;
        cout << "Enter Account Number : ";
        cin >> accNum;

        int index = findAccountIndex(accNum);

        if(index != -1){
            displayAccount(index);
        }
        else{
            cout << "Account not found!" << endl;
        }
    }

    void deposit(){
        double amount;
        int accNum;
        cout << "Enter Account Number : ";
        cin >> accNum;

        int index = findAccountIndex(accNum);
        if (index != -1)
        {
            cout << "Enter amount, You want to deposit : ";
            cin >> amount;
            balance[index] += amount;
            cout << "Deposit successful. Updated Balance : " << fixed << setprecision(3) << balance[index] << endl;
        }
        else{
            cout << "Account not found!" << endl;
        }
    }

    void withdraw(){
        int accNum;
        double amount;
        cout << "Enter Account Number : ";
        cin >> accNum;

        int index = findAccountIndex(accNum);
        if(index != -1){
            cout << "Enter amount, You want to withdraw : ";
            cin >> amount;
            if (amount < balance[index])
            {
                balance[index] -= amount;
                cout << "Withdrawl Successfully. Updated Balance : " << fixed << setprecision(3) << balance[index] << endl;
            }
            else{
                cout << "Insufficent Balance!" << endl;
            }
        }
        else{
            cout << "Account not found!" << endl;
        }
    }

    void deleteAccount(){
        int accNum;
        cout << "Enter Account Number : ";
        cin >> accNum;

        int index = findAccountIndex(accNum);
        if (index != -1)
        {
            accountHolder[index] = "";
            balance[index] = 0;
            cout << "Account deleted successfully\n" << endl;
        }
        else{
            cout << "Account not found!" << endl;
        }
    }

};

// Display menu
void displayMenu() {
    cout << "\n-------> Welcome to ABC Bank <-------\n";
    cout << "1. Create Account\n";
    cout << "2. Check Balance\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Delete Account\n";
    cout << "6. Exit\n";
    cout << "-------------------------------------------\n";
}

int main() {
    Account acc;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acc.createAccount();
                break;
            case 2:
                acc.checkBalance();
                break;
            case 3:
                acc.deposit();
                break;
            case 4:
                acc.withdraw();
                break;
            case 5:
                acc.deleteAccount();
                break;
            case 6:
                cout << "Thank you for using ABC Bank.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}