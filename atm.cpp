#include <iostream>
using namespace std;

class ATM {
private:
    double balance;
    
public:
    ATM() : balance(0.0) {}
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "RS/- Successfully deposited " << amount << ".\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << ".\n";
        } else {
            cout << "Invalid amount or insufficient funds.\n";
        }
    }
    
    void checkBalance() {
        cout << "Your current balance is $" << balance << ".\n";
    }
};

int main() {
    ATM atm;
    int choice;
    double amount;

    while (true) {
        cout << "\nATM Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                atm.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                atm.withdraw(amount);
                break;
            case 3:
                atm.checkBalance();
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}