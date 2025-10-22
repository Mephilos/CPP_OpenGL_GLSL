#pragma once

#include <string>
#include <iostream>

class Account {
protected:
    int accID; //계좌 아이디
    int balance;// 잔액
    std::string cusName; //고객명
    
public:
    Account(int id, int initBalance, const std::string &name);
    virtual ~Account();

    virtual void display() const;
    virtual void deposit(int money);
    virtual bool withdraw(int money);

    int getID() const;
    int getBalance() const;

};
