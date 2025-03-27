#include "BankingSystem.h"
#include "StreamHelper.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << endl;
    cout << "--------- Banking System Menu ---------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Inquire All Accounts" << endl;
    cout << "5. Exit" << endl;
    cout << "Select an option: ";
}

int main() {
    BankingSystem bankSystem;
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        cout << endl;
        //stripNewlines();
        switch (choice) {
            case 1:
                bankSystem.makeAccount();
                break;
            case 2:
                bankSystem.depositMoney();
                break;
            case 3:
                bankSystem.withdrawMoney();
                break;
            case 4:
                bankSystem.printAllAccounts();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Illegal selection. Please try again." << endl;
        }
    }
    return 0;
}
