#include "drinksmenu.h"
#include "ui_drinksmenu.h"

DrinksMenu::DrinksMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrinksMenu)
{
    ui->setupUi(this);
}

DrinksMenu::~DrinksMenu()
{
    delete ui;
}
