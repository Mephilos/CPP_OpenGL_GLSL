#pragma once

#include "Account.h"
#include "InterestRates.h"
#include <vector>
#include <memory>
#include <string>


class BankingSystem {
private:
    std::vector<std::unique_ptr<Account>> accounts;

public:
    BankingSystem();
    ~BankingSystem();

    bool isValidName(const std::string &name);
    std::string inputName();
    int inputID();
    int inputBalance();

    Account* findAccountByID(int id);

    void makeAccount();
    void makeNormalAccount();
    void makeCreditAccount();
    void depositMoney();
    void withdrawMoney();
    void printAllAccounts() const;
};
