#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype>
#include <memory>

using namespace std;

enum class BaseInterRate
{
    baseRate = 1
};

enum class CreditRate
{
    A = 7,
    B = 4,
    C = 2,
};
void cinClear()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int MakeCreditAccountSelect()
{
    int select;

    while (true)
    {
        cout << endl;
        cout << "--------- Select Credit Rate Menu ---------" << endl;
        cout << "1. Credit Rate A" << endl;
        cout << "2. Credit Rate B" << endl;
        cout << "3. Credit Rate C" << endl;
        cout << "Select an option: ";

        cin >> select;
        if (cin.fail() || !(select < 4 && select > 0))
        {
            cout << "Illegal selection. Please try again" << endl;
            cinClear();
            continue;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    switch (select)
    {
    case 1:
        return static_cast<int>(CreditRate::A);
    case 2:
        return static_cast<int>(CreditRate::B);
    case 3:
        return static_cast<int>(CreditRate::C);
    default:
        cout << "Illegal selection. Please try again" << endl;
    }
    return 0;
}

class Account // 계좌에 관련된 클래스
{
private:
    int accID;           // 어카운트 아이디
    int balance;         // 잔액
    std::string cusName; // 고객명
public:
    // 생성자
    Account(int id, int init_Balance, const std::string &name)
        : accID(id), balance(init_Balance), cusName(name) {}

    virtual ~Account() {}
    void Display() const
    {
        cout << "Account ID: " << accID << endl;
        cout << "Customer Name: " << cusName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void deposit(int money)
    {
        if (money > 0)
            balance += money;
    }

    bool withdraw(int money)
    {
        if (money > balance)
        {
            return false;
        }
        else
        {
            balance -= money;
            return true;
        }
    }
    // 정규화된 테이블이 있다면, 고객명만 알아도 될것 같으니 고객명만
    int getID() const
    {
        return accID;
    }
    int getBalance() const
    {
        return balance;
    }
};
class NormalAccount : public Account
{
private:
    int interRate;

public:
    NormalAccount(int id, int balance, const std::string &name, int rate)
        : Account(id, balance, name), interRate(rate) {}

    virtual void deposit(int in_money) override
    {
        //  Account::deposit(in_money);
        int inter = (getBalance() + in_money) * interRate / 100;
        Account::deposit(in_money + inter);
    }
    ~NormalAccount() {}
};

class CreditAccount : public NormalAccount
{
private:
    int creditInterRate;

public:
    CreditAccount(int id, int balance, const std::string &name, int rate, int credit_rate)
        : NormalAccount(id, balance, name, rate), creditInterRate(credit_rate) {}

    virtual void deposit(int in_money) override
    {
        int inter = (getBalance() + in_money) * creditInterRate / 100;
        NormalAccount::deposit(in_money + inter);
    }
    ~CreditAccount() {}
};

class BankingSystem
{
private:
    std::vector<std::unique_ptr<Account>> accounts;

public:
    bool isValidName(const string &name)
    {
        for (char c : name)
        {
            if (!isalpha(static_cast<unsigned char>(c)) && !isspace(static_cast<unsigned char>(c)))
            {
                return false;
            }
        }
        return true;
    }

    std::string inputName()
    {
        string name;
        while (true)
        {
            cout << "Customer Name: ";
            std::getline(cin, name);

            if (name.empty())
            {
                cout << "The name is empty. Please enter it again" << endl;
                continue;
            }
            if (isValidName(name))
            {
                break;
            }
            else
            {
                cout << "Please enter a name that contains only English letters and spaces" << endl;
            }
        }
        return name;
    }
    int inputID()
    {
        int accID;
        while (true)
        {
            if (cin >> accID) // int외 fail() else로 넘어감
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a valid numeric Account ID" << endl;
                cinClear();
            }
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 정상 입력 후 루프문 탈출시 남아있는 개행 문자 제거
        return accID;
    }
    int inputBalance()
    {
        int money;

        while (!(cin >> money))
        {
            cout << "Invalid input. Please enter a valid numeric balance" << endl;
            cinClear();
        }
        return money;
    }
    // TODO:std::Optional은 여기선 이질적인 느낌이라 일단 보류
    // 중복 체크 루프 함수
    Account *findAccountByID(int id)
    {
        for (auto &account : accounts)
        {
            if (account->getID() == id)
                return account.get();
        }
        return nullptr;
    }
    void makeAccount()
    {
        int id;
        int balance;
        string name;

        while (true)
        {
            cout << "Enter your desired ID number: ";
            id = inputID();
            if (findAccountByID(id) != nullptr)
            {
                cout << "Duplicate ID. Please Re-enter" << endl;
                continue;
            }
            break;
        }

        name = inputName();

        cout << "Initial Deposit: ";
        balance = inputBalance();

        // 생성시 어카운트 객체 추가
        accounts.emplace_back(make_unique<Account>(id, balance, name));
        cout << "Account Creation Completed" << endl;
        cout << "ID: " << id << endl;
        cout << "Balance: " << balance << endl;
        cout << "Name: " << name << endl;
    }
    void makeNormalAccount()
    {
        int id;
        int balance;
        string name;
        int interRate = static_cast<int>(BaseInterRate::baseRate);
        while (true)
        {
            cout << "Enter your desired ID number: ";
            id = inputID();
            if (findAccountByID(id) != nullptr)
            {
                cout << "Duplicate ID. Please Re-enter" << endl;
                continue;
            }
            break;
        }

        name = inputName();
        cout << "Initial Deposit: ";
        balance = inputBalance();

        // 생성시 어카운트 객체 추가
        accounts.emplace_back(make_unique<NormalAccount>(id, balance, name, interRate));
        cout << "Account Creation Completed" << endl;
        cout << "ID: " << id << endl;
        cout << "Balance: " << balance << endl;
        cout << "Name: " << name << endl;
    }
    void makeCreditAccount()
    {
        int id;
        int balance;
        string name;
        int interRate = static_cast<int>(BaseInterRate::baseRate);
        int creditRate;

        while (true)
        {
            cout << "Enter your desired ID number: ";
            id = inputID();
            if (findAccountByID(id) != nullptr)
            {
                cout << "Duplicate ID. Please Re-enter" << endl;
                continue;
            }
            break;
        }

        name = inputName();
        cout << "Initial Deposit: ";
        balance = inputBalance();
        creditRate = MakeCreditAccountSelect();

        // 생성시 어카운트 객체 추가
        accounts.emplace_back(make_unique<CreditAccount>(id, balance, name, interRate, creditRate));
        cout << "Account Creation Completed" << endl;
        cout << "ID: " << id << endl;
        cout << "Balance: " << balance << endl;
        cout << "Name: " << name << endl;
        cout << "CreditRate: " << creditRate << endl;
    }
    void depositMoney()
    {

        int id;
        int money;

        cout << "Enter your desired ID number: ";
        id = inputID();

        Account *account = findAccountByID(id);

        if (account)
        {
            cout << "Enter Deposit: ";
            money = inputBalance();
            account->deposit(money);
            cout << "Deposit Completed" << endl;
            cout << "Current Balance: " << account->getBalance() << endl;
        }
        else
        {
            cout << "Account not found" << endl;
        }
    }

    void withdrawMoney()
    {
        int id, money;
        cout << "Enter your Account ID for Withdrawal: ";
        id = inputID();

        Account *account = findAccountByID(id);

        if (account)
        {
            cout << "Enter Withdrawal amount: ";
            money = inputBalance();
            if (account->withdraw(money))
            {
                cout << "Withdrawal Completed" << endl;
            }
            else
            {
                cout << "Insufficient funds" << endl;
            }
            cout << "Current Balance: " << account->getBalance() << endl;
        }
        else
        {
            cout << "Account not found" << endl;
        }
    }
    void printAllAccounts() const
    {
        if (accounts.empty())
        {
            cout << "No accounts available" << endl;
            return;
        }
        for (const auto &account : accounts)
        {
            account->Display();
            cout << "--------------------------" << endl;
        }
    }
};

void showMenu()
{
    cout << endl;
    cout << "--------- Banking System Menu ---------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Inquire All Accounts" << endl;
    cout << "5. Exit" << endl;
    cout << "Select an option: ";
}

void MakeAccountSelect(BankingSystem &bankSystem)
{
    int select;

    while (true)
    {
        cout << endl;
        cout << "--------- Make Account Menu ---------" << endl;
        cout << "1. Make Normal Account" << endl;
        cout << "2. Make Credit Account" << endl;
        cout << "Select an option: ";

        cin >> select;
        if (cin.fail() || !(select == 1 || select == 2))
        {
            cout << "Illegal selection. Please try again" << endl;
            cinClear();
            continue;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    switch (select)
    {
    case 1:
        // TODO: 보통계좌 계설
        bankSystem.makeNormalAccount();
        break;
    case 2:
        // TODO: 신용계좌 계설
        bankSystem.makeCreditAccount();
        break;
    default:
        cout << "Illegal selection. Please try again" << endl;
    }
}

int main()
{
    BankingSystem bankSystem;
    int choice;

    while (true)
    {
        showMenu();
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            MakeAccountSelect(bankSystem);

            break;
        case 2:
            bankSystem.depositMoney();

            break;
        case 3:
            bankSystem.withdrawMoney();

            break;
        case 4:
            bankSystem.printAllAccounts();

            break;
        case 5:
            std::cout << "Exiting the program..." << endl;
            return 0;
        default:
            cinClear();
            std::cout << "Illegal selection. Please try again." << endl;
        }
    }
    return 0;
}
