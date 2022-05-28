#ifndef BALANCEMENU_H
#define BALANCEMENU_H

#include <QDialog>
#include "HTTP.h"
#include "account.h"
#include "mainwindow.h"

namespace Ui {
class BalanceMenu;
}

class BalanceMenu : public QDialog
{
    Q_OBJECT

public:
    explicit BalanceMenu(QWidget *parent = nullptr, Account account = ("d", 3, 3));
    ~BalanceMenu();

private slots:
    void on_pushButtonMoney100_clicked();
    void on_pushButtonMoney10_clicked();
    void on_pushButtonMoney1_clicked();
    void on_pushButtonMoneyMinus100_clicked();
    void on_pushButtonMoneyMinus10_clicked();
    void on_pushButtonMoneyMinus1_clicked();
    void on_pushButtonConfirm_clicked();

    void on_pushButton_clicked();

private:
    Ui::BalanceMenu *ui;
    double money;
    Account account;
    HTTP http;
    void setText(QString text);
};

#endif // BALANCEMENU_H
