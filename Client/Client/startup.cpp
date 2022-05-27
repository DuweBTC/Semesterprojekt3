#include "startup.h"
#include "ui_startup.h"


StartUp::StartUp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartUp)
{
    ui->setupUi(this);
}

StartUp::~StartUp()
{
    delete ui;
}



void StartUp::on_pushButtonCardScan_clicked()
{
    int placeHolderForStudentCard = 21431241;
    if (user == NEW_USER){
        account.setAccountId(placeHolderForStudentCard);
        hide();
        NewUser newUserMenu(nullptr, account);
        newUserMenu.setModal(true);
        newUserMenu.exec();

    } else if (user == USER){
        hide();
        MainWindow mainMenu;
        mainMenu.setModal(true);
        mainMenu.exec();
    }


}

