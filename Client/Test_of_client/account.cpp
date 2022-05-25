#include "account.h"
using namespace std;

Account::Account(int AccountId, QString name, double balance)
//: _accountId(AccountId)
{
    setBalance(balance);
    setName(name);
    setAccountId(AccountId);
}

double Account::getBalance() const
{
    return _balance;
}

void Account::setBalance(double balance)
{
    _balance = balance;
}

void Account::setName(QString name)
{
    _name = name;
}

QString Account::getName() const
{
    return _name;
}

int Account::getAccountId() const
{
    return _accountId;
}

void Account::setAccountId(int AccountId)
{
    _accountId = AccountId;
}

void Account::operator =(const Account &temp){
    _accountId = temp.getAccountId();
    _balance = temp.getBalance();
    _name = temp.getName();
}

void Account::addFavorits(DrinkItem drinkItem){
    favorits.push_back(drinkItem);
}

void Account::deleteFavorits(DrinkItem drinkItem){
    for (auto iterator = favorits.begin(); iterator != favorits.end(); iterator++ ){
        if (drinkItem == *iterator){
            favorits.remove(*iterator);
        }
    }
}


Account::~Account(){

}
