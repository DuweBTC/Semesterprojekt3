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

void Account::operator=(const Account &temp)
{
    _accountId = temp.getAccountId();
    _balance = temp.getBalance();
    _name = temp.getName();
}

void Account::addFavorits(DrinkItem drinkItem)
{
    _favorits.push_back(drinkItem);
}

void Account::deleteFavorits(DrinkItem drinkItem)
{
    for (auto iterator = _favorits.begin(); iterator != _favorits.end(); iterator++)
    {
        if (drinkItem == *iterator)
        {
            _favorits.remove(*iterator);
        }
    }
}

std::list<DrinkItem> Account::getFavorits() const{
    return _favorits;
}

DrinkItem Account::getOneFavorit(int index) const{
    for (auto iterator = _favorits.cbegin(); iterator != _favorits.cend(); iterator++)
    {
        if (index == iterator->getDrinkId())
        {
            ++iterator;
        }
        return *iterator;
    }
    return DrinkItem();
}

Account::Account(const Account &temp){
    _name = temp.getName();
    _balance = temp.getBalance();
    _accountId = temp.getAccountId();

    for (unsigned long i = 0; i <= (temp.getFavorits()).size(); i++)
    {
        _favorits.push_back(getOneFavorit(i));
    }

}

Account::~Account()
{
}
