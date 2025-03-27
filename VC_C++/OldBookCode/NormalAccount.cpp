#include "NormalAccount.h"


NormalAccount::NormalAccount(int id, int balance, const std::string &name, int rate)
    : Account(id, balance, name), interRate(rate) {}

NormalAccount::~NormalAccount() {}

void NormalAccount::deposit(int money)
{
    Account::deposit(money + (money * interRate / 100));
}