#include "CreditAccount.h"


CreditAccount::CreditAccount(int id, int balance, const std::string &name, int rate, int creditRate)
    : NormalAccount(id, balance, name, rate), creditInterRate(creditRate) {}

CreditAccount::~CreditAccount() {};

void CreditAccount::deposit(int money)
{
    NormalAccount::deposit(money + (money * creditInterRate / 100));
}
