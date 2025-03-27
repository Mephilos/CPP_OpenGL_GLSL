#pragma once

#include "NormalAccount.h"

class CreditAccount : public NormalAccount
{
private:
    int creditInterRate;
public:
    CreditAccount (int id, int balance, const std::string &name, int rate, int creditInterRate);
    virtual ~CreditAccount();
    virtual void deposit(int money) override;
};