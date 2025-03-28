#include "NormalAccount.h"


NormalAccount::NormalAccount(int id, int balance, const std::string &name, int rate)
    : Account(id, balance, name), interRate(rate) {}

NormalAccount::~NormalAccount() {}

void NormalAccount::deposit(int money)
{
    int inter = (getBalance() + money) * interRate / 100;
    Account::deposit(money + inter);
}
