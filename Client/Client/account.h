#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include "Drinkitem.h"

class Account
{
public:
    Account(int AccountId = 0, QString name = "", double balance = 0);
    void setName(QString name);
    QString getName() const;
    void setBalance(double balance);
    double getBalance() const;
    int getAccountId() const;
    void setAccountId(int AccountId);
    void operator=(const Account &temp);
    void addFavorits(DrinkItem);
    void deleteFavorits(DrinkItem);
    std::list<DrinkItem> getFavorits() const;
    Account(const Account & copy);
    ~Account();

private:
    QString _name;
    double _balance;
    int _accountId;
    std::list<DrinkItem> _favorits;
    DrinkItem getOneFavorit(int index) const;
};

#endif // ACCOUNT_H
