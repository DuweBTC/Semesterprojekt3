#include "newuser.h"
#include "ui_newuser.h"
#include "mainwindow.h"

NewUser::NewUser(QWidget *parent, Account accountOld) :
    QDialog(parent),
    ui(new Ui::NewUser)
{
    ui->setupUi(this);
    account = accountOld;
}

NewUser::~NewUser()
{
    delete ui;
}

void NewUser::on_pushButtonConfirm_clicked()
{
    account.setName((ui->textInsertName)->text());
    account.setBalance(0);
    http.postAccount(&account);

    hide();
    MainWindow mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}
