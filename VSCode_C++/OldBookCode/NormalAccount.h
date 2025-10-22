#pragma once

#include "Account.h"

class NormalAccount : public Account
{
private:
    int interRate; //이자율
public:
    NormalAccount(int id, int balance, const std::string &name, int rate);
    virtual ~NormalAccount();
    virtual void deposit(int money) override;
};


