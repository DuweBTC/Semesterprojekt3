#include "mainwindow.h"
#include "ui_mainwindow.h"
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

// Defined what to do when finished
void MainWindow::downloadFinished(QNetworkReply * reply){
    QPixmap pix;
    pix.loadFromData(reply->readAll());
    ui->label->setPixmap(pix);
}

void MainWindow::getWeatherStation(QNetworkReply * reply){
    ui->textBrowser->setText(reply->readAll());
    //ui->textBrowser = reply->readAll();

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QNetworkAccessManager* man = new QNetworkAccessManager(this);
    //connect(man, &QNetworkAccessManager::finished, this, &MainWindow::downloadFinished);
    connect(man, &QNetworkAccessManager::finished, this, &MainWindow::getWeatherStation);
    const QUrl url = QUrl(myURL);
    QNetworkRequest request(url);
    man->get(request);

}

//void buttonclicked(){
//    account.SetAccount()
//    Account newAccount =  dbDriver.getAccount();
//    account.setName() =  newAccount.getName();
//}

