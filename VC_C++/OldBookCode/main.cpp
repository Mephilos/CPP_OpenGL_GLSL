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


        //TODO:여기다가 직접 입금하는거 만들꺼임.
        cout << "Initial Balance: ";
        cin >> balance;
        //생성시 어카운트 객체 추가하는 방식
        accounts.emplace_back(id, balance, name);
        cout << "Account Created" << endl;
    }

    void depositMoney()
    {
        int id, money;
        cout << "Enter your Account ID for deposit: ";
        cin >> id;
        
    }
};


