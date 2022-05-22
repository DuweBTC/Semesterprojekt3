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
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
using std::list;

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
    //Functions
    void makeAccountList(QJsonArray JsonFormat);
    void makeDrinkList(QJsonArray JsonFormat);
    void makeRecipetList(QJsonArray JsonFormat);
    void makeContainerList(QJsonArray JsonFormat);
    void makeIngredienttList(QJsonArray tJsonFormat);


    // One Instance objects
    Ui::MainWindow *ui;
    DatabaseDriver dbDriver;
    Account account;
    Recipe recipe;
    DrinkItem drinkItem;
    IngredientItem ingredientItem;
    ContainerItem containerItem;    

    // List of the object
    std::list <Account> accountList;
    std::list <DrinkItem> drinkList;
    std::list <IngredientItem> ingredientList;
    std::list <Recipe> recipeList;
    std::list <ContainerItem> containerList;
    enum {NO_CARD, CARD};
    enum {NEW_USER, ALREADY_USER};

private slots:
    // Event handling programning
    void startscreen();
    int scanStudentCard();
    void mainWindow();
    void newUserWindow();
    void on_buttonBalanceMenu_clicked();
    void on_pushKontoMenu_clicked();

//    void on_PostAccountButton_clicked();
//    void on_GetAccountButton_clicked();

    void DrinkButton();
    void IngredientButton();
    void ContainerButton();
    void RecipeButton();
};
#endif // MAINWINDOW_H
