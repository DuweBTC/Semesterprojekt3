#ifndef ADDDRINKMENU_H
#define ADDDRINKMENU_H

#include <QDialog>
#include "databasedriver.h"
#include "Drinkitem.h"

namespace Ui {
class AddDrinkMenu;
}

class AddDrinkMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AddDrinkMenu(QWidget *parent = nullptr);
    ~AddDrinkMenu();

private slots:
    void on_pushButtonAddDrink_clicked();

private:
    Ui::AddDrinkMenu *ui;
    DatabaseDriver http;
    DrinkItem drink;

};

#endif // ADDDRINKMENU_H
