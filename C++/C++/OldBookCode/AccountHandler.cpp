//
//  AccountHandler.cpp
//  C++
//
//  Created by TAEHO SIM on 3/27/25.
//

#include "AccountHandler.h"

namespace AccountFactory {
    std::unique_ptr<Account> createAccount(AccountType type,
                                             int accountId,
                                             int balance,
                                             const std::string &customerName,
                                             int interestRate,
                                             int creditInterestRate)
    {
        switch (type)
        {
        case AccountType::Normal:
            return std::make_unique<NormalAccount>(accountId, balance, customerName, interestRate);
        case AccountType::Credit:
            return std::make_unique<CreditAccount>(accountId, balance, customerName, interestRate, creditInterestRate);
        default:
            return nullptr;
        }
    }
}
