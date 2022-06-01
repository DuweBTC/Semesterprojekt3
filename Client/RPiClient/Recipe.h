#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include "Ingredientitem.h"

/************************************************
 *  Contains methods of the class Recipe
 ***********************************************/

class Recipe
{
public:
    Recipe(double Amount = 0, int RecipeItemId = 0);
    void setAmount(double Amount);
    double getAmount() const;
    void setRecipeItemId(int RecipeItemId);
    int getRecipeItemId() const;
    void setIngredient(const IngredientItem& temp);
    IngredientItem getIngredient() const;

private:
    int _RecipeItemId;
    double _Amount;
    IngredientItem _ingredient;
};

#endif // RECIPE_H
