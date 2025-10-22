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

// 팩토리 네임스페이스로 캡슐화 (네임스페이스 사용 권장)
namespace AccountFactory
{
    // 팩토리 메서드: 계좌 유형, 계좌ID, 초기 잔액, 고객 이름, 일반 계좌의 이자율, (신용 계좌의 경우) 신용 이자율을 받아
    // 해당하는 타입의 Account 객체를 생성하여 반환합니다.
    std::unique_ptr<Account> createAccount(AccountType type,
                                             int accountId,
                                             int balance,
                                             const std::string &customerName,
                                             int interestRate,
                                             int creditInterestRate = 0);
}
