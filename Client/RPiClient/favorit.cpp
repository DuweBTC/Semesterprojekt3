#include "favorit.h"
#include "ui_favorit.h"

Favorit::Favorit(QWidget *parent, Account accountOld) :
    QDialog(parent),
    ui(new Ui::Favorit)
{
    ui->setupUi(this);
    account = accountOld;
    http.getAccount(QString::number(account.getAccountId()), &account);

    QString text = "\nName: " + account.getName() + "\nFavorit Drink: " ;
    setText(text);
}

Favorit::~Favorit()
{
    delete ui;

}


void Favorit::setText(QString text){
    ui->textBrowserFavoritInformation->setText(text);
    ui->textBrowserFavoritInformation->setFontPointSize(16);
    ui->textBrowserFavoritInformation->setAlignment(Qt::AlignCenter);
}


void Favorit::on_pushButtonMenu_clicked()
{
    hide();
    MainWindow mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}

