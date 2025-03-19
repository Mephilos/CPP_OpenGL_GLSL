#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

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

    void display() const
    {
        cout << "Account ID: " << accID << endl;
        cout << "Customer Name: " << cusName << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit(int money)
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

class BankingSystem
{
private:
    std::vector<Account> accounts;

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
            cout << "Enter your desired ID number: ";
            if (cin >> accID) // int외 fail() else로 넘어감
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a valid numeric Account ID" << endl;
                cin.clear();                                                   // cin 의 오류 초기화
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 정리
            }
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 정상 입력 후 루프문 탈출시 남아있는 개행 문자 제거
        return accID;
    }
    int inputBalance()
    {
        int money;
        cout << "Balance: ";
        while (!(cin >> money))
        {
            cout << "Invalid input. Please enter a valid numeric balance" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return money;
    }
    // TODO:std::Optional은 여기선 이질적인 느낌이라 일단 보류
    // 중복 체크 루프 함수
    Account *findAccountByID(int &id)
    {
        for (auto &account : accounts)
        {
            if (account.getID() == id)
                return &account;
        }
        return nullptr;
    }

    void makeAccount()
    {
        int id;
        while (true)
        {
            id = inputID();
            if (findAccountByID(id) != nullptr)
            {
                cout << "Duplicate ID. Please Re-enter" << endl;
                continue;
            }
            break;
        }

        string name = inputName();
        int balance = inputBalance();

        // 생성시 어카운트 객체 추가
        accounts.emplace_back(id, balance, name);
        cout << "Account Creation Completed" << endl;
        cout << "ID: " << id << endl;
        cout << "Balance: " << balance << endl;
        cout << "Name: " << name << endl;
    }

    void depositMoney()
    {
        int id = inputID();
        int money = inputBalance();

        Account* account = findAccountByID(id);
        
        
        if(account)
        {
            account->deposit(money);
            cout << "Deposit Completed" << endl;
            cout << "Current Balance: " << account->getBalance() << endl;
        }
        else
        {
            cout << "Account not found" <<endl;
        }
    }

    void withdrawMoney()
    {
        int id, money;
        cout << "Enter your Account ID for withdrawal: ";
        id = inputID();
        cout << "Enter withdrawal amount: ";
        money = inputBalance();

        Account* account = findAccountByID(id);
        
        if(account)
        {
            if(account -> withdraw(money))
            {
                cout << "Withdrawal Completed" << endl;
            }
            else
            {
                cout << "Insufficient funds" << endl;
            }
            cout << "Current Balance: " << account -> getBalance() << endl;
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
            account.display();
            cout << "--------------------------" << endl;
        }
    }
};

void showMenu()
{
    cout << endl;
    cout << "--------- Banking System Menㅕ ---------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Inquire All Accounts" << endl;
    cout << "5. Exit" << endl;
    cout << "Select an option: ";
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
            bankSystem.makeAccount();
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
            std::cout << "Illegal selection. Please try again." << endl;
        }
    }
    return 0;
}
