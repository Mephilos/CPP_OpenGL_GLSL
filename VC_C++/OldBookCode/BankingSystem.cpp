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
    stripNewlines();
    return id;
}

int BankingSystem::inputBalance()
{
    int money;

    cout << "Balance: ";
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
{   //기본적으로 NormalAccount 생성 호출 (사용자가 선택으로 분리)
    makeNormalAccount();
}

void BankingSystem::makeNormalAccount() 
{
    int id;
    while(true) 
    {
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
    int rate;
    cout << "Enter interest rate for Normal Account: ";
    cin >> rate;
    stripNewlines();
    accounts.push_back(make_unique<NormalAccount>(id,balance,name, rate));
    cout << "Normal Account Creation Completed" <<endl;
    cout << "ID: " << id << ", Balance: " <<balance << ", Name: " << name << endl;

}
void BankingSystem::makeCreditAccount()
{
    int id;
    while(true)
    {
        id = inputID();
        if(findAccountByID(id) != nullptr)
        {
            cout << "Duplicate ID. Please re-enter" << endl;
            continue;
        }
        break;
    }
    string name = inputName();
    int balance = inputBalance();
    int rate, credit_rate;

    cout<< "Enter interest rate for normal Account: ";
    cin>> rate;
    cout << "Enter credit interest rate for Credit Account: ";
    cin >> credit_rate;
    stripNewlines();
    accounts.push_back(make_unique<CreditAccount>(id, balance, name, rate, credit_rate));
    cout << "Credit Account Creation Completed" <<endl;
    cout << "ID: " << id << ", Balance: " << balance << ", Name: " << name <<endl;
}
void BankingSystem::depositMoney()
{
    int id = inputID();
    int money = inputBalance();
    Account* account = findAccountByID(id);
    if(account)
    {
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
    int id = inputID();
    int money = inputBalance();
    Account* account = findAccountByID(id);
    if (account) {
        if (account->withdraw(money))
            cout << "Withdrawal Completed." << endl;
        else
            cout << "Insufficient funds." << endl;
        cout << "Current Balance: " << account->getBalance() << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

void BankingSystem::printAllAccounts() const {
    if (accounts.empty()) {
        cout << "No accounts available." << endl;
        return;
    }
    for (const auto &acc : accounts) {
        acc->display();
        cout << "--------------------------" << endl;
    }
}
