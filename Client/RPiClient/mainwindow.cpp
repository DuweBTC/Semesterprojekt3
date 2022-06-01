#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAccountMenu_clicked()
{
    hide();
    KontoInformation kontoMenu;
    kontoMenu.setModal(true);
    kontoMenu.exec();
}


void MainWindow::on_pushButtonBalanceMenu_clicked()
{
    hide();
    BalanceMenu balanceMenu;
    balanceMenu.setModal(true);
    balanceMenu.exec();
}


void MainWindow::on_pushButtonDrinkMenu_clicked()
{
    hide();
    DrinksMenu drinksMenu;
    drinksMenu.setModal(true);
    drinksMenu.exec();
}


void MainWindow::on_pushButtonNewDrinkMenu_clicked()
{
    hide();
    AddDrinkMenu addDrinkMenu;
    addDrinkMenu.setModal(true);
    addDrinkMenu.exec();
}


void MainWindow::on_pushButtonFarvorits_clicked()
{
    hide();
    Favorit favorit;
    favorit.setModal(true);
    favorit.exec();
}

