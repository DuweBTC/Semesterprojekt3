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
    Account getAccount();
    void postAccount(Account *account);
    void putAccount(Account *account);
    void deleteAccount(QString index);

    // For Recipe
    Recipe getRecipe();
    void postRecipe(Recipe *recipe);
    void putRecipe(Recipe *recipe);
    void deleteRecipe(QString index);

    // For Drinkitem
    DrinkItem getDrink();
    void postDrink(DrinkItem *drink);
    void putDrink(DrinkItem *drink);
    void deleteDrink(QString index);

    // For IngredientItem
    IngredientItem getIngredient();
    void postIngredient(IngredientItem *Ingredient);
    void putIngredient(IngredientItem *Ingredient);
    void deleteIngredient(QString index);

    // For ContainerItem
    ContainerItem getContainer();
    void postContainer(ContainerItem *container);
    void putContainer(ContainerItem *container);
    void deleteContainer(QString index);

private:
    const QString _url = "url";
};

#endif // DATABASEDRIVER_H
