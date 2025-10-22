#include "BankingSystem.h"
#include "NormalAccount.h"
#include "CreditAccount.h"
#include "StreamHelper.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

BankingSystem::BankingSystem() {}
BankingSystem::~BankingSystem() {}



//공백 알파뱃만 허용
bool BankingSystem::isValidName(const string &name)
{
    for (char c : name)
    {
        if (!isalpha(static_cast<unsigned char>(c)) && !isspace(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }
    return true;
}

string BankingSystem::inputName()
{
    string name;
    while (true)
    {
        cout << "Customer Name: ";
        getline(cin, name);
        if (name.empty())
        {
            cout << "The name is empty. Please enter it again" << endl;
            continue;
        }
        if (isValidName(name))
        {
            break;
        }
        else
        {
            cout << "Please enter a name that contains only English letters and spaces" << endl;
        }
    }
    return name;
}

int BankingSystem::inputID()
{
    int id;
    while (true)
    {
        //cout << "Enter your desired ID number: ";
        if (cin >> id)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please enter a valid numeric Account ID " <<endl;
            cinClear();
        }
    }
    stripNewlines(); //루프 탈출 시 제거
    return id;
}

int BankingSystem::inputBalance()
{
    int money;
    
    //cout << "Balance: ";
    while (!(cin >> money))
    {
        cout << "Invalid input. Please enter a valid numeric balance" << endl;
        cinClear();
    }
    stripNewlines();
    return money;
}

Account* BankingSystem::findAccountByID(int id)
{
    for(auto &acc : accounts)
    {
        if(acc->getID() == id)
        {
            return acc.get();
        }
    }
    return nullptr;
}

void BankingSystem::makeAccount()
{
    makeNormalAccount();
}

void BankingSystem::makeNormalAccount()
{
    int id;
    while(true)
    {
        cout << "Enter your desired ID number: ";
        id = inputID();
        if(findAccountByID(id) != nullptr)
        {
            cout << "Duplicate ID. Please re-enter" <<endl;
            continue;
        }
        break;
    }
    string name = inputName();
    int balance = inputBalance();
    int rate = static_cast<int>(BaseInterestRate::BaseRate);
    
    accounts.push_back(make_unique<NormalAccount>(id,balance,name, rate));
    cout << "Normal Account Creation Completed" <<endl;
    cout << "ID: " << id << ", Balance: " <<balance << ", Name: " << name << endl;
    
}

int MakeCreditAccountSelect()
{
    int select;
    
    while (true)
    {
        cout << endl;
        cout << "--------- Select Credit Rate Menu ---------" << endl;
        cout << "1. Credit Rate A" << endl;
        cout << "2. Credit Rate B" << endl;
        cout << "3. Credit Rate C" << endl;
        cout << "Select an option: ";
        
        cin >> select;
        if (cin.fail() || !(select < 4 && select > 0))
        {
            cout << "Illegal selection. Please try again" << endl;
            cinClear();
            continue;
        }
        else
        {
            stripNewlines();
            break;
        }
    }
    
    switch (select)
    {
        case 1:
            return static_cast<int>(CreditInterestRate::A);
        case 2:
            return static_cast<int>(CreditInterestRate::B);
        case 3:
            return static_cast<int>(CreditInterestRate::C);
        default:
            cout << "Illegal selection. Please try again" << endl;
    }
    return 0;
}

void BankingSystem::makeCreditAccount()
{
    int id;
    int balance;
    string name;
    int rate = static_cast<int>(BaseInterestRate::BaseRate);
    int creditRate;
    while(true)
    {
        cout << "Enter your desired ID number: ";
        id = inputID();
        if(findAccountByID(id) != nullptr)
        {
            cout << "Duplicate ID. Please re-enter" << endl;
            continue;
        }
        break;
    }
    name = inputName();
    cout << "Initial Deposit: ";
    balance = inputBalance();
    creditRate = MakeCreditAccountSelect();
    stripNewlines();
    
    accounts.push_back(make_unique<CreditAccount>(id, balance, name, rate, creditRate));
    cout << "Credit Account Creation Completed" <<endl;
    cout << "ID: " << id << ", Balance: " << balance << ", Name: " << name <<endl;
    cout << "Credit Rate: " << creditRate << endl;
}
void BankingSystem::depositMoney()
{
    int id;
    int money;
    
    cout << "Enter your desired ID number: ";
    id = inputID();
    Account* account = findAccountByID(id);
    if(account)
    {
        cout << "Enter Deposit: ";
        money = inputBalance();
        account -> deposit(money);
        cout << "Deposit Completed" << endl;
        cout << "Current Balance: " << account -> getBalance() <<endl;
    }
    else
    {
        cout << "Account not found" <<endl;
    }
}

void BankingSystem::withdrawMoney()
{
    int id;
    int money;
    
    cout << "Enter your Account ID for Withdrawal: ";
    id = inputID();
    
    Account* account = findAccountByID(id);
    if (account)
    {
        cout << "Enter Withdrawal amount: ";
        money = inputBalance();
        if (account->withdraw(money))
            cout << "Withdrawal Completed." << endl;
        else
            cout << "Insufficient funds" << endl;
        cout << "Current Balance: " << account->getBalance() << endl;
    }
    else
    {
        cout << "Account not found." << endl;
    }
}

void BankingSystem::printAllAccounts() const
{
    if (accounts.empty())
    {
        cout << "No accounts available." << endl;
        return;
    }
    for (const auto &acc : accounts)
    {
        acc->display();
        cout << "--------------------------" << endl;
    }
}
