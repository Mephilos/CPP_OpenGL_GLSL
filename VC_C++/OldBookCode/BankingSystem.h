#pragma once

#include "Account.h"
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
    int inputId();
    int inputBalance();

    Account* findAccountById(int id);

    void makeAccount();
    void makeNormalAccount();
    void makeCreditAccount();
    void depositMoney();
    void withdrawMoney();
    void printAllAccounts() const;
};
