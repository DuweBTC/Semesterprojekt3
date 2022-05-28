#ifndef ADDDRINKMENU_H
#define ADDDRINKMENU_H

#include <QDialog>
#include "HTTP.h"
#include "Drinkitem.h"
#include "mainwindow.h"

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

    void on_pushButton_clicked();

private:
    Ui::AddDrinkMenu *ui;
    HTTP http;
    DrinkItem drink;

};

#endif // ADDDRINKMENU_H
