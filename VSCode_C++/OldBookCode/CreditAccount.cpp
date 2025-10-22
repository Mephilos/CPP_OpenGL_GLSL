#include "CreditAccount.h"


CreditAccount::CreditAccount(int id, int balance, const std::string &name, int rate, int creditRate)
    : NormalAccount(id, balance, name, rate), creditInterRate(creditRate) {}

CreditAccount::~CreditAccount() {};

void CreditAccount::deposit(int money)
{
    int inter = (getBalance() + money) * creditInterRate / 100;
    NormalAccount::deposit(money + inter);
}
