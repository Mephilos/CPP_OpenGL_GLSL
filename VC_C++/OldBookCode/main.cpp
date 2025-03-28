#include "BankingSystem.h"
#include "StreamHelper.h"
#include <iostream>

using namespace std;

void showMenu()
{
    cout << endl;
    cout << "--------- Banking System Menu ---------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Inquire All Accounts" << endl;
    cout << "5. Exit" << endl;
    cout << "Select an option: ";
}

// void makeAccountSelect(BankingSystem &bankSystem)
// {
//     int select;
//     while(true)
//     {
//         cout << endl;
//         cout << "--------- Make Account Menu ---------" << endl;
//         cout << "1. Make Normal Account" << endl;
//         cout << "2. Make Credit Account" << endl;
//         cout << "Select an option: ";
        
        
//         cin >> select;
//         if (cin.fail() || !(select == 1 || select == 2))
//         {
//             cout << "Illegal selection. Please try again." << endl;
//             cinClear();
//             continue;
//         }
//         else
//         {
//             stripNewlines();
//             break;
//         }
//     }
//     switch (select)
//     {
//         case 1:
//             bankSystem.makeNormalAccount();
//             break;
//         case 2:
//             bankSystem.makeCreditAccount();
//             break;
//         default:
//             cout << "Illegal selection. Please try again." << endl;
//             break;
//     }
    
// }
int main()
{
    BankingSystem bankSystem;
    int select;
    
    while (true)
    {
        showMenu();
        cin >> select;
        cout << endl;
        
        stripNewlines();
        
        switch (select)
        {
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
                cinClear();
                cout << "Illegal selection. Please try again." << endl;
        }
    }
    return 0;
}
