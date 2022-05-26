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
    // Functions
    void makeAccountList(QJsonArray JsonFormat);
    void makeDrinkList(QJsonArray JsonFormat);
    void makeRecipeList(QJsonArray JsonFormat);
    void makeContainerList(QJsonArray JsonFormat);
    void makeIngredientList(QJsonArray tJsonFormat);

    // One Instance objects
    Ui::MainWindow *ui;
    DatabaseDriver dbDriver;
    Account *accountPtr = &account;
    Account account;
    Recipe recipe;
    DrinkItem drinkItem;
    IngredientItem ingredientItem;
    ContainerItem containerItem;

    // List of the object
    std::list<Account> accountList;
    std::list<DrinkItem> drinkList;
    std::list<IngredientItem> ingredientList;
    std::list<Recipe> recipeList;
    std::list<ContainerItem> containerList;
    enum
    {
        NO_CARD,
        CARD
    };
    enum
    {
        NEW_USER,
        ALREADY_USER
    };
    enum
    {
        SCAN_CARD_MENU,
        MAIN_MENU,
        NEW_USER_MENU,
        KONTO_MENU,
        KATALOG_MENU,
        ADD_DRINK_MENU,
        BALANCE_MENU,
        FAVORIT_MENU
    };
    int WindowMenu = 0;
    void setText(QString text);

private slots:
    // Event handling programning
    void run();
    int scanStudentCard();
    void mainWindow();
    void newUserWindow();
    void on_pushMainMenu_clicked();
    void on_pushFavoritsMenu_clicked();

    // Events for Account
    void on_pushGetAccount_clicked();
    void on_pushPostAccount_clicked();
    void on_pushPutAccount_clicked();
    void on_pushDeleteAccount_clicked();
    void on_pushGetAllAccount_clicked();
    void on_pushGetAccountBalance_clicked();
    void on_pushPutAccountBalance_clicked();
    void on_pushAddFavorits_clicked();
    void on_pushDeleteFavorits_clicked();


    // Events for Recipe
    void on_pushGetRecipe_clicked();
    void on_pushPostRecipe_clicked();
    void on_pushPutRecipe_clicked();
    void on_pushDeleteRecipe_clicked();
    void on_pushGetAllRecipe_clicked();

    // Events for Ingredient
    void on_pushGetIngredient_clicked();
    void on_pushPostIngredient_clicked();
    void on_pushPutIngredient_clicked();
    void on_pushDeleteIngredient_clicked();
    void on_pushGetAllIngredient_clicked();

    // Events for Drink
    void on_pushGetDrink_clicked();
    void on_pushPostDrink_clicked();
    void on_pushPutDrink_clicked();
    void on_pushDeleteDrink_clicked();
    void on_pushGetAllDrink_clicked();

    // Events for Container
    void on_pushGetContainer_clicked();
    void on_pushPostContainer_clicked();
    void on_pushPutContainer_clicked();
    void on_pushDeleteContaier_clicked();
    void on_pushGetAllContainer_clicked();

};
#endif // MAINWINDOW_H
