#include "kontoinformation.h"
#include "ui_kontoinformation.h"

KontoInformation::KontoInformation(QWidget *parent, Account accountOld) :
    QDialog(parent),
    ui(new Ui::KontoInformation)
{
    ui->setupUi(this);
    account = accountOld;
    http.getAccount(QString::number(account.getAccountId()), &account);

    QString text = "Name: " + account.getName() + "\nBalance: " + QString::number(account.getBalance());
    setText(text);
}

KontoInformation::~KontoInformation()
{
    delete ui;

}

void KontoInformation::on_pushButton_clicked()
{
    hide();
    MainWindow mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}

void KontoInformation::setText(QString text){
    ui->textBrowserKontoInformation->setText(text);
    ui->textBrowserKontoInformation->setFontPointSize(16);
    ui->textBrowserKontoInformation->setAlignment(Qt::AlignCenter);
}
