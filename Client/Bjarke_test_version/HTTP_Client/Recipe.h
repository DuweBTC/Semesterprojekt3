#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>

class Recipe
{
public:
    Recipe(double Amount = 0, int RecipeItemId = 0);
    void setAmount(double Amount);
    double getAmount() const;
    void setRecipeItemId(int RecipeItemId);
    int getRecipeItemId() const;

private:
    int _RecipeItemId;
    double _Amount;
};

#endif // RECIPE_H
