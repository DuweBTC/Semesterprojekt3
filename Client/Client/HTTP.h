
#ifndef HTTP_H
#define HTTP_H
#include "account.h"
#include "Recipe.h"
#include "Drinkitem.h"
#include "Ingredientitem.h"
#include "Containeritem.h"
#include <QObject>

class HTTP
{
public:
    HTTP();
    // For Account
    std::list<Account> getAccountList();
    bool getAccount(QString id, Account *);
    void getAccountBalance(QString id, Account *account);
    void postAccount(Account *account);
    void putAccount(Account *account);
    void putAccountBalance(double amount, Account *account);
    void deleteAccount(QString index);

    // For Recipe
    std::vector<Recipe> getRecipeList();
    Recipe getRecipe(QString id);
    void postRecipe(Recipe *recipe);
    void putRecipe(Recipe *recipe);
    void deleteRecipe(QString index);

    // For Drinkitem
    std::vector<DrinkItem> getDrinkList();
    DrinkItem getDrink(QString id);
    int getDrinkAmount();
    void postDrink(DrinkItem *drink);
    void putDrink(DrinkItem *drink);
    void deleteDrink(QString index);

    // For IngredientItem
    std::vector<IngredientItem> getIngredientList();
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
    const QString _url = "http://localhost:5123/"; //PC
    //const QString _url = "http://10.77.77.77:5000/"; // RPI
};

#endif // HTTP_H
