#ifndef ACCOUNTITEM_H
#define ACCOUNTITEM_H

#include <QObject>
using namespace std;

class AccountItem
{

private:
    string name_;
    double balance_;

public:
    void setName(string name);
    QString getName()const;
    void setBalance(double balance);
    QString getBalance()const;
};

#endif // ACCOUNTITEM_H


