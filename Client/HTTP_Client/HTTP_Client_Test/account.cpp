#include "account.h"
using namespace std;

Account::Account(QString AccountId, QString name, double balance)
    : _accountId(AccountId)
{
    setBalance(balance);
    setName(name);
}

double Account::getBalance()const
{
    return balance_;
}

void Account::setBalance(double balance)
{
    balance_ = balance;

}

void Account::setName(QString name)
{
    name_ = name;
}

QString Account::getName()const
{
    return name_;
}

QString Account::getAccountId()const
{
    return _accountId;
}
