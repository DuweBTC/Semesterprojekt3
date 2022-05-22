#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>

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

private:
    QString _name;
    double _balance;
    int _accountId;
};

#endif // ACCOUNT_H
