#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H
#include "account.h"
#include "Recipe.h"
#include "Drinkitem.h"
#include "Ingredientitem.h"
#include "Containeritem.h"
#include <QObject>

class DatabaseDriver
{
public:
    DatabaseDriver();
    // For Account
    QJsonArray getAccountList();
    Account* getAccount(QString id, Account *);
    void postAccount(Account *account);
    void putAccount(Account *account);
    void deleteAccount(QString index);

    // For Recipe
    QJsonArray getRecipeList();
    Recipe getRecipe(QString id);
    void postRecipe(Recipe *recipe);
    void putRecipe(Recipe *recipe);
    void deleteRecipe(QString index);

    // For Drinkitem
    QJsonArray getDrinkList();
    DrinkItem getDrink(QString id);
    void postDrink(DrinkItem *drink);
    void putDrink(DrinkItem *drink);
    void deleteDrink(QString index);

    // For IngredientItem
    QJsonArray getIngredientList();
    IngredientItem getIngredient(QString id);
    void postIngredient(IngredientItem *Ingredient);
    void putIngredient(IngredientItem *Ingredient);
    void deleteIngredient(QString index);

    // For ContainerItem
    QJsonArray getContainerList();
    ContainerItem getContainer(QString id);
    void postContainer(ContainerItem *container);
    void putContainer(ContainerItem *container);
    void deleteContainer(QString index);

private:
    const QString _url = "http://localhost:5123/";
};

#endif // DATABASEDRIVER_H
