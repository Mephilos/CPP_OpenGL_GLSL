#pragma once

#include <string>
#include <iostream>

class Account {
protected:
    int accID;
    int balance;
    std::string cusName;
    
public:
    Account(int id, int initBalance, const std::string &name);
    virtual ~Account();

    virtual void display() const;
    virtual void deposit(int money);
    virtual bool withdraw(int money);

    int getID() const;
    int getBalance() const;

};