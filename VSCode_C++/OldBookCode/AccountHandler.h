#pragma once


#include <memory>
#include <string>
#include "Account.h"
#include "NormalAccount.h"
#include "CreditAccount.h"

enum class AccountType {
    Normal,
    Credit
};

namespace AccountHandler
{
    std::unique_ptr<Account> createAccount(AccountType type,
                                             int accountId,
                                             int balance,
                                             const std::string &customerName,
                                             int interestRate,
                                             int creditInterestRate = 0);
}
