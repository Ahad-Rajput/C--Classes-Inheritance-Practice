#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int Max_Accounts = 50; // Maximum number of accounts

// Class to represent a Bank Account
class Account {
private:
    string accountHolder;
    int accountNum;
    double balance;

public:
    // Default constructor
    Account() : accountHolder(""), accountNum(0), balance(0.0) {}

    // Parameterized constructor
    Account(string name, int accNum, double initialBalance)
        : accountHolder(name), accountNum(accNum), balance(initialBalance) {}

    // Accessor functions
    string getAccountHolder() const { return accountHolder; }
    int getAccountNum() const { return accountNum; }
    double getBalance() const { return balance; }

    // Mutator functions
    void setAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNum = accNum;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Withdraw money
    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Display account details
    void display() const {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNum << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
    }

    // Save account details to file
    void saveToFile(ofstream& outFile) const {
        outFile << accountHolder << '\n'
                << accountNum << '\n'
                << balance << '\n';
    }

    // Load account details from file
    void loadFromFile(ifstream& inFile) {
        getline(inFile, accountHolder);
        inFile >> accountNum >> balance;
        inFile.ignore(); // Consume the newline after reading balance
    }
};

// Class to manage the bank system
class Bank {
private:
    Account accounts[Max_Accounts];
    int numAccounts;
    int nextAccountNum;

public:
    // Constructor
    Bank() : numAccounts(0), nextAccountNum(201) {
        loadAccounts();
    }

    // Destructor
    ~Bank() {
        saveAccounts();
    }

    // Create a new account
    void createAccount() {
        if (numAccounts >= Max_Accounts) {
            cout << "Cannot create account. Maximum limit reached.\n";
            return;
        }

        string name;
        double initialBalance;

        cout << "Enter Account Holder's Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        accounts[numAccounts].setAccount(name, nextAccountNum, initialBalance);
        cout << "Account created successfully! Account Number: " << nextAccountNum << endl;

        numAccounts++;
        nextAccountNum++;
    }

    // Find account by number
    Account* findAccount(int accNum) {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].getAccountNum() == accNum) {
                return &accounts[i];
            }
        }
        return nullptr;
    }

    // Check balance
    void checkBalance() {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        Account* account = findAccount(accNum);
        if (account) {
            account->display();
        } else {
            cout << "Account not found.\n";
        }
    }

    // Deposit money
    void deposit() {
        int accNum;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accNum;

        Account* account = findAccount(accNum);
        if (account) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            account->deposit(amount);
            cout << "Deposit successful. Updated balance: " << fixed << setprecision(2) << account->getBalance() << endl;
        } else {
            cout << "Account not found.\n";
        }
    }

    // Withdraw money
    void withdraw() {
        int accNum;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accNum;

        Account* account = findAccount(accNum);
        if (account) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            if (account->withdraw(amount)) {
                cout << "Withdrawal successful. Remaining balance: " << fixed << setprecision(2) << account->getBalance() << endl;
            } else {
                cout << "Insufficient balance.\n";
            }
        } else {
            cout << "Account not found.\n";
        }
    }

    // Delete account
    void deleteAccount() {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].getAccountNum() == accNum) {
                // Shift accounts to remove the deleted one
                for (int j = i; j < numAccounts - 1; j++) {
                    accounts[j] = accounts[j + 1];
                }
                numAccounts--;
                cout << "Account deleted successfully.\n";
                return;
            }
        }
        cout << "Account not found.\n";
    }

    // Load accounts from file
    void loadAccounts() {
        ifstream inFile("accounts.txt");
        if (inFile.is_open()) {
            inFile >> nextAccountNum >> numAccounts;
            inFile.ignore(); // Consume the newline after numAccounts

            for (int i = 0; i < numAccounts; i++) {
                accounts[i].loadFromFile(inFile);
            }
            inFile.close();
        }
    }

    // Save accounts to file
    void saveAccounts() {
        ofstream outFile("accounts.txt");
        if (outFile.is_open()) {
            outFile << nextAccountNum << '\n' << numAccounts << '\n';
            for (int i = 0; i < numAccounts; i++) {
                accounts[i].saveToFile(outFile);
            }
            outFile.close();
        }
    }
};

// Display menu
void displayMenu() {
    cout << "\n-------> Welcome to ABC Bank <-------\n\n";
    cout << "1. Create Account\n";
    cout << "2. Check Balance\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Delete Account\n";
    cout << "6. Exit\n";
    cout << "\n-------------------------------------------\n\n";
}

int main() {
    Bank bank;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.checkBalance();
                break;
            case 3:
                bank.deposit();
                break;
            case 4:
                bank.withdraw();
                break;
            case 5:
                bank.deleteAccount();
                break;
            case 6:
                cout << "---> Exiting the Program.\nThank you for using ABC Bank Management...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
