#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>

class Account
{
public:
    Account(QString AccountId = "", QString name = "", double balance = 0);
    void setName(QString name);
    QString getName()const;
    void setBalance(double balance);
    double getBalance() const;
    QString getAccountId()const;

private:
    QString name_;
    double balance_;
    QString _accountId;



};

#endif // ACCOUNT_H
