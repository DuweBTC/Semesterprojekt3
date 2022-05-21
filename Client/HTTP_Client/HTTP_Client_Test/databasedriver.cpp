#include "databasedriver.h"
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
#include "mainwindow.h"


DatabaseDriver::DatabaseDriver()
{

}

Account DatabaseDriver::getAccount(){
    // create custom temporary event loop on stack
        QEventLoop eventLoop;
        Account account_local;

        // "quit()" the event-loop, when the network request "finished()"
        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        // the HTTP request
        QNetworkRequest req( QUrl( QString("http://127.0.0.1:8080/") ) );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        if (reply->error() == QNetworkReply::NoError) {

            QString strReply = (QString)reply->readAll();

            //parse json
            qDebug() << "Response:" << strReply;
            QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

            QJsonArray json_array = jsonResponse.array();

                foreach (const QJsonValue &value, json_array) {
                    QJsonObject json_account_obj = value.toObject();
                    //QJsonObject json_account_obj = json_obj.value("place").toObject();
                    qDebug() << json_account_obj["AccountId"].toString();
                    qDebug() << json_account_obj["Name"].toString();
                    qDebug() << json_account_obj["Balance"].toDouble();
                    //Account account_local(json_accont_obj["AccountId"].toString(),json_account_obj["AccountId"].toString(), json_account_obj["Balance"].toDouble() );
                    account_local.setName(json_account_obj["AccountId"].toString());
                    account_local.setBalance(json_account_obj["Balance"].toDouble());

                }

            delete reply;
        }
        else {
            //failure
            qDebug() << "Failure" <<reply->errorString();
            delete reply;
        }

        return account_local;
}

void DatabaseDriver::postAccount(Account *account )
{
    // "quit()" the event-loop, when the network request "finished()"
     //Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    //QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/"));
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject account_local;
    account_local["Name"] = account->getName();
    account_local["Balance"] = account->getBalance();
    account_local["AccountId"] = account->getAccountId();



    /*QJsonObject obj;
    obj["id"] = "value1";
    obj["date"] = "value2";
    obj["time"] = "value3";
    obj["place"] = place_t;
    obj["temperature"] = 20;
    obj["humidity"] = 69;*/

    QJsonDocument doc(account_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"Name\":\"account->getName()\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater();
    });

}

void DatabaseDriver::putAccount(Account *account)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    //QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    int id = 5;
    QString URL = "http://127.0.0.1:8080/";
    //URL +=  + id.toString();
    // the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/2" ));
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject account_local;
    account_local["Name"] = account->getName();
    account_local["Balance"] = account->getBalance();
    account_local["AccountId"] = account->getAccountId();



    QJsonDocument doc(account_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"key1\":\"value1\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->put(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater();
    });



}

void deleteAccount(QString index)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    //QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QString const URL = "http://127.0.0.1:8080/" + index;


    // the HTTP request
    const QUrl url(URL);
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->deleteResource(request);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater();
    });

}








