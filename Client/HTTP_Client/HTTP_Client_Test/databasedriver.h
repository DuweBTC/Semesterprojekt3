#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H
#include "account.h"

#include <QObject>

class DatabaseDriver
{
public:
    DatabaseDriver();
    Account getAccount();
    void postAccount(Account *account);
    void putAccount(Account *account);
    void deleteAccount(QString index);
private:
    const QString _url = "url";

};

#endif // DATABASEDRIVER_H
