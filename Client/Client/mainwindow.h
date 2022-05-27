#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "kontoinformation.h"
#include "balancemenu.h"
#include "drinksmenu.h"
#include "adddrinkmenu.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAccountMenu_clicked();

    void on_pushButtonBalanceMenu_clicked();

    void on_pushButtonDrinkMenu_clicked();

    void on_pushButtonNewDrinkMenu_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
