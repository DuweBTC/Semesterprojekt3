#ifndef DRINKSMENU_H
#define DRINKSMENU_H

#include <QDialog>
#include "mainwindow.h"
#include "HTTP.h"
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

    void on_pushButtonBuyDrink_1_clicked();

    void on_pushButtonBuyDrink_2_clicked();

private:
    Ui::DrinksMenu *ui;
    DrinkItem drink;
    void setText();
    HTTP http;
    std::vector<DrinkItem> drinkList;
};

#endif // DRINKSMENU_H
