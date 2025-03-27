#include "Account.h"


Account::Account(int id, int Balance, const std::string &name)
    : accID(id), balance(Balance), cusName(name) {}

Account::~Account() { }


void Account::display() const 
{
    std::cout << "Account ID: " << accID << std::endl;
    std::cout << "Customer Name: " <<cusName << std::endl;
    std::cout << "Balance: " <<balance << std::endl;   
}

void Account::deposit(int money)
{
    if(money > 0)
    {
        balance += money;
    }
}

bool Account::withdraw(int money)
{
    if(money > balance)
    {
        return false;
    }
    balance -= money;
    return true;
}

int Account::getID() const
{
    return accID;
}
int Account::getBalance() const
{
    return balance;
}
