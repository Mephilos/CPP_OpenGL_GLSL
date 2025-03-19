#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

enum class Menu
{
    MAKE,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT,
};

class Account //계좌에 관련된 클래스
{
private:
    int accID; //어카운트 아이디
    int balance; //잔액
    std::string cusName; //고객명
public:
    //생성자
    Account(int id, int init_Balance, const std::string& name)
        : accID(id), balance(init_Balance), cusName(name){} 

    void display() const{
        cout << "Account ID: "    << accID   << endl; 
        cout << "Customer Name: " << cusName << endl; 
        cout << "Balance: "       << balance << endl;
    }

    void deposit(int money) 
    {
        if(money > 0)
            balance += money;
    }

    bool withraw(int money)
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
    //정규화된 테이블이 있다면, 고객명만 알아도 될것 같으니 고객명만
    int getID() const
    {
        return accID;
    }
};

class BankingSystem 
{
private:
    std::vector<Account> accounts;
    
public:
    void makeAccount()
    {
        int id;
        int balance;
        std::string name;

        cout << "Account ID: ";
        cin >> id;
        //버퍼 정리
        cin.ignore(std::numeric_limits<std::streamsize>::max());
        cout << endl;

        cout << "Customer Name: ";
        std::getline(cin, name);


        
        cout << "Initial Balance: ";
        //그냥 입력
        cin >> balance;
        //생성시 어카운트 객체 추가
        accounts.emplace_back(id, balance, name);
        cout << "Account Creation Completed" << endl;
    }

    void depositMoney()
    {
        int id, money;
        cout << "Enter your Account ID for deposit: ";
        cin >> id;
        cout << "Enter deposit amount: ";
        cin >> money;

        for (auto& account : accounts)
        {
            if(account.getID() == id)
            {
                account.deposit(money);
                cout<< "Deposit Completed" << endl;
                return;
            }
        }
        cout << "Account not found" << endl;
    }

    void withdrawMoney()
    {
        int id, money ;
        cout << "Enter your Account ID for withdrawal: ";
        cin >> id;
        cout << "Enter withdrawal amount: ";
        cin >> money;
        for (auto& account : accounts)
        {
            if(account.getID() == id)
            {
                if(account.withraw(money))
                {
                    cout<< "Withdrawal Completed" << endl;
                }
                else
                {
                    cout << "Insufficient funds" << endl;
                } 
                return;
            }
        }
        cout << "Account not found" << endl;
    }
    void printAllAccounts() const {
        if (accounts.empty()) 
        {
            cout << "No accounts available" << endl;
            return;
        }
        for (const auto& account : accounts) 
        {
            account.display();
            cout << "--------------------------" << endl;;
        }
    }
};

void showMenu()
{
    cout << endl;
    cout << "--------- Banking System Meun ---------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Inquire All Accounts" << endl;
    cout << "5. Exit" << endl;
    cout << "Select an option: " ; 
}

int main()
{
    BankingSystem bankSystem;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;
        cout << endl;

        switch (choice) {
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
