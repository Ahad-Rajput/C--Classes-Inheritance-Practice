#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_ACCOUNTS = 50;

class BankSystem {
private:
    string accountHolders[MAX_ACCOUNTS];
    int accountNumbers[MAX_ACCOUNTS];
    double balances[MAX_ACCOUNTS];
    int totalAccounts;
    int nextAccountNum;

public:
    BankSystem() : totalAccounts(0), nextAccountNum(1001) {
        loadAccounts();
    }

    ~BankSystem() {
        saveAccounts();
    }
    void createAccount() {
        if (totalAccounts >= MAX_ACCOUNTS) {
            cout << "Cannot create more accounts. Maximum limit reached.\n";
            return;
        }

        string name;
        double initialBalance;

        cout << "Enter Account Holder's Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        // Create account
        accountHolders[totalAccounts] = name;
        accountNumbers[totalAccounts] = nextAccountNum++;
        balances[totalAccounts] = initialBalance;
        totalAccounts++;

        // Display account number to user
        cout << "Account created successfully!\n";
        cout << "Your Account Number is: " << accountNumbers[totalAccounts - 1] << endl;
    }

    void checkBalance() {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        int index = findAccountIndex(accNum);
        if (index != -1) {
            displayAccount(index);
        } else {
            cout << "Account not found.\n";
        }
    }

    void deposit() {
        int accNum;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        int index = findAccountIndex(accNum);
        if (index != -1) {
            balances[index] += amount;
            cout << "Deposit successful. Updated balance: " << balances[index] << endl;
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdraw() {
        int accNum;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        int index = findAccountIndex(accNum);
        if (index != -1) {
            if (amount <= balances[index]) {
                balances[index] -= amount;
                cout << "Withdrawal successful. Remaining balance: " << balances[index] << endl;
            } else {
                cout << "Insufficient balance.\n";
            }
        } else {
            cout << "Account not found.\n";
        }
    }

    void deleteAccount() {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        int index = findAccountIndex(accNum);
        if (index != -1) {
            // Shift all attributes to fill the gap
            for (int i = index; i < totalAccounts - 1; i++) {
                accountHolders[i] = accountHolders[i + 1];
                accountNumbers[i] = accountNumbers[i + 1];
                balances[i] = balances[i + 1];
            }
            totalAccounts--;
            cout << "Account deleted successfully.\n";
        } else {
            cout << "Account not found.\n";
        }
    }

private:
    int findAccountIndex(int accNum) const {
        for (int i = 0; i < totalAccounts; i++) {
            if (accountNumbers[i] == accNum) {
                return i;
            }
        }
        return -1; // Not found
    }

    void displayAccount(int index) const {
        cout << "\nAccount Holder: " << accountHolders[index] << endl;
        cout << "Account Number: " << accountNumbers[index] << endl;
        cout << "Balance: " << fixed << setprecision(2) << balances[index] << endl;
    }

    void loadAccounts() {
        ifstream inFile("accs.txt");
        if (!inFile.is_open()) return;

        inFile >> nextAccountNum;
        inFile >> totalAccounts;

        inFile.ignore();
        for (int i = 0; i < totalAccounts; i++) {
            getline(inFile, accountHolders[i]);
            inFile >> accountNumbers[i] >> balances[i];
            inFile.ignore();
        }
        inFile.close();
    }

    void saveAccounts() const {
        ofstream outFile("accs.txt");
        if (!outFile.is_open()) return;

        outFile << nextAccountNum << '\n';
        outFile << totalAccounts << '\n';

        for (int i = 0; i < totalAccounts; i++) {
            outFile << accountHolders[i] << '\n'
                    << accountNumbers[i] << '\n'
                    << balances[i] << '\n';
        }
        outFile.close();
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
    BankSystem bank;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.checkBalance(); break;
            case 3: bank.deposit(); break;
            case 4: bank.withdraw(); break;
            case 5: bank.deleteAccount(); break;
            case 6: cout << "Thank you for using ABC Bank.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
