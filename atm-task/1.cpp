#include <iostream>
using namespace std;

const int CORRECT_PIN = 1234;
int balance = 10000;

int checkPin() {
    int pin;

    for (int attempt = 1; attempt <= 3; attempt++) {
        cout << "Write Your Pin: ";
        cin >> pin;

        if (pin == CORRECT_PIN) {
            return 1;
        }

        cout << "Incorrect Pin: " << 3 - attempt << endl;
    }

    return 0;
}

void showMenu() {
    cout << endl;
    cout << "===== ATM MENU =====" << endl;
    cout << "1. Balance Check" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose Your Option (1-4): ";
}


void checkBalance() {
    cout << "Yours balance : Rs. " << balance << endl;
}

void deposit() {
    int amount;
    cout << "Write amount? ";
    cin >> amount;

    if (amount > 0) {
        balance = balance + amount;
        cout << "Rs. " << amount << " Deposited." << endl;
        checkBalance();
    } else {
        cout << "Amount must be greater than 0." << endl;
    }
}

void withdraw() {
    int amount;
    cout << "Write Amount? ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Amount must be greater than 0." << endl;
    } else if (amount > balance) {
        cout << "Your account has insufficent balance!" << endl;
    } else {
        balance = balance - amount;
        cout << "Rs. " << amount << " Withdrawed." << endl;
        checkBalance();
    }
}

int main() {
    cout << "===== ATM =====" << endl;

    if (checkPin() == 0) {
        cout << "Your Account is banned" << endl;
        return 0;
    }

    cout << "Pin Corrected!" << endl;

    int option;

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                cout << "Thanks for using ATM." << endl;
                break;
            default:
                cout << "Invalid Option." << endl;
        }

    } while (option != 4);

    return 0;
}