#ifndef DATABASEDRIVER_H

#include <QCoreApplication>
#include <QDebug>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QVariant>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <QSslConfiguration>

#include "account.h"
//#include "mainwindow.h"

#include <QObject>

class DatabaseDriver
{
public:
    DatabaseDriver();
    Account getAccount();
    void postAccount(Account *account);
    void putAccount(Account *account);
    void deleteAccount(QString index);
    void finished(QNetworkReply *reply);
    void sslErrors(QNetworkReply* reply, const QList<QSslError> & errors);
private:
    const QString _url = "url";

};


#endif // DATABASEDRIVER_H
