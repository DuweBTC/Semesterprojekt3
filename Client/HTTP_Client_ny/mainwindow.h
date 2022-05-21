#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager> // To make requests and so on
#include <QNetworkReply>
#include <qpixmap.h>
#include "account.h"
#include "Recipe.h"
#include "Drinkitem.h"
#include "Ingredientitem.h"
#include "databasedriver.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString myURL = "http://127.0.0.1:8080/";
    Account account;
    Recipe recipe;
    DrinkItem drinkItem;
    IngredientItem ingredientItem;
    ContainerItem containerItem;
    DatabaseDriver dbDriver;
    //    Drink drink[100];
    //    DatabaseDriver dbDriver;

private slots:
    //    void downloadFinished(QNetworkReply*);
    //    void getWeatherStation(QNetworkReply * reply);
    //    void on_pushButton_clicked();
    void AccountButton();
    void RecipeButton();
    void DrinkButton();
    void IngredientButton();
    void ContainerButton();
};
#endif // MAINWINDOW_H
