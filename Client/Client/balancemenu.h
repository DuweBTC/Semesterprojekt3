#ifndef BALANCEMENU_H
#define BALANCEMENU_H

#include <QDialog>
#include "databasedriver.h"
#include "account.h"

namespace Ui {
class BalanceMenu;
}

class BalanceMenu : public QDialog
{
    Q_OBJECT

public:
    explicit BalanceMenu(QWidget *parent = nullptr, Account account = ("d", 2, 2));
    ~BalanceMenu();

private slots:
    void on_pushButtonMoney100_clicked();
    void on_pushButtonMoney10_clicked();
    void on_pushButtonMoney1_clicked();
    void on_pushButtonMoneyMinus100_clicked();
    void on_pushButtonMoneyMinus10_clicked();
    void on_pushButtonMoneyMinus1_clicked();
    void on_pushButtonConfirm_clicked();

private:
    Ui::BalanceMenu *ui;
    double money;
    Account account;
    DatabaseDriver http;
    void setText(QString text);
};

#endif // BALANCEMENU_H
