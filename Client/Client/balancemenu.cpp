#include "balancemenu.h"
#include "ui_balancemenu.h"

BalanceMenu::BalanceMenu(QWidget *parent, Account accountOld) :
    QDialog(parent),
    ui(new Ui::BalanceMenu)
{
    ui->setupUi(this);
    account = accountOld;
    setText("Amount");
}

BalanceMenu::~BalanceMenu()
{
    delete ui;
}

void BalanceMenu::on_pushButtonMoney100_clicked()
{
    money += 100;
    setText(QString::number(money));
}


void BalanceMenu::on_pushButtonMoney10_clicked()
{
    money += 10;
    setText(QString::number(money));
}

void BalanceMenu::on_pushButtonMoney1_clicked()
{
    money += 1;
    setText(QString::number(money));
}

void BalanceMenu::on_pushButtonMoneyMinus100_clicked()
{
    money -= 100;
    setText(QString::number(money));
}


void BalanceMenu::on_pushButtonMoneyMinus10_clicked()
{
    money -= 10;
    setText(QString::number(money));
}

void BalanceMenu::on_pushButtonMoneyMinus1_clicked()
{
    money -= 1;
    setText(QString::number(money));

}
// Button to update balance
void BalanceMenu::on_pushButtonConfirm_clicked(){
    if (money <= 0 ){
        ui->textBrowserAmountOfMoney->setFontPointSize(14);
        ui->textBrowserAmountOfMoney->insertPlainText("Cant insert negativ amount of money");
        http.putAccountBalance(money,&account); // Test at man kan trække fra sin nuværende balance..
    } else {
    http.putAccountBalance(money, &account); // Opdatere balance for Account.
    }
}

void BalanceMenu::setText(QString text){
    ui->textBrowserAmountOfMoney->setText(text);
    ui->textBrowserAmountOfMoney->setFontPointSize(24);
    ui->textBrowserAmountOfMoney->setAlignment(Qt::AlignCenter);
}

// Button to get back to Main Menu
void BalanceMenu::on_pushButton_clicked()
{
    hide();
    MainWindow mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();

}

