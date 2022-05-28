#ifndef DRINKSMENU_H
#define DRINKSMENU_H

#include <QDialog>
#include "mainwindow.h"
#include "databasedriver.h"
#include "Drinkitem.h"

namespace Ui {
class DrinksMenu;
}

class DrinksMenu : public QDialog
{
    Q_OBJECT

public:
    explicit DrinksMenu(QWidget *parent = nullptr);
    ~DrinksMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonConfirm_clicked();

    void on_pushButtonConfirm_2_clicked();

private:
    Ui::DrinksMenu *ui;
    DrinkItem drink;
    void setText(QString text);
    DatabaseDriver http;
};

#endif // DRINKSMENU_H
