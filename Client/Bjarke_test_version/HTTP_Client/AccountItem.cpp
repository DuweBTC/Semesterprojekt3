#include "AccountItem.h"
using namespace std;

AccountItem::getBalance() const
{
    return balance_;
}

AccountItem::setBalance(double balance)
{
    balance_ = balance;
}

AccountItem::setName(QString name)
{
    name_ = name;
}

AccountItem::getName() const
{
    return name_;
}
