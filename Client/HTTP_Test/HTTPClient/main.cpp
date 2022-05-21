#include "mainwindow.h"
#include <QCoreApplication>
#include <QDebug>
#include <QApplication>
//#include <QtWebKitWidgets/QWebFrame>
//#include <QtWebKitWidgets/QWebPage>
//#include <QtWebKitWidgets/QWebView>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
//#include <QWebSettings>
#include <QVariant>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>

void sendRequest();
void postWeather();
void putWeather(QString index);
void deleteWeather(QString index);

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //sendRequest();
    //postWeather();
    //putWeather(index);
    QString index = "2";
    deleteWeather(index);
    return a.exec();
}

void sendRequest(){
    // create custom temporary event loop on stack
        QEventLoop eventLoop;

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
                    QJsonObject json_obj = value.toObject();
                    QJsonObject json_obj2 = json_obj.value("place").toObject();
                    qDebug() << json_obj["id"].toString();
                    qDebug() << json_obj["date"].toString();
                    qDebug() << json_obj["time"].toString();
                    qDebug() << json_obj2["placeName"].toString();
                    qDebug() << json_obj2["lat"].toDouble();
                    qDebug() << json_obj2["lon"].toDouble();
                    qDebug() << json_obj["temperature"].toDouble();
                    qDebug() << json_obj["humidity"].toInt();

                }

            delete reply;
        }
        else {
            //failure
            qDebug() << "Failure" <<reply->errorString();
            delete reply;
        }
    }



void postWeather(){
//    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
//    const QUrl url(QStringLiteral("http://127.0.0.1:8080/"));
//    QNetworkRequest request(url);

    // create custom temporary event loop on stack
    //QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    //QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/"));
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject place_t;
    place_t["placeName"] = "Aarhus N";
    place_t["lat"] = 19;
    place_t["lon"] = 12;

    QJsonObject obj;
    obj["id"] = "value1";
    obj["date"] = "value2";
    obj["time"] = "value3";
    obj["place"] = place_t;
    obj["temperature"] = 20;
    obj["humidity"] = 69;

    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"key1\":\"value1\",\"key2\":\"value2\"}");
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

void putWeather(QString index){
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
    QJsonObject place_t;
    place_t["placeName"] = "Aarhus N";
    place_t["lat"] = 1;
    place_t["lon"] = 1;

    QJsonObject obj;
    obj["id"] = "value1";
    obj["date"] = "value2";
    obj["time"] = "value3";
    obj["place"] = place_t;
    obj["temperature"] = 0;
    obj["humidity"] = 9;

    QJsonDocument doc(obj);
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

void deleteWeather(QString index){
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
