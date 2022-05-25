#include "Recipe.h"

Recipe::Recipe(double Amount, int RecipeItemId)
{
    setAmount(Amount);
    setRecipeItemId(RecipeItemId);
}

double Recipe::getAmount() const
{
    return _Amount;
}

void Recipe::setAmount(double Amount)
{
    _Amount = Amount;
}

int Recipe::getRecipeItemId() const
{
    return _RecipeItemId;
}

void Recipe::setRecipeItemId(int RecipeItemId)
{
    _RecipeItemId = RecipeItemId;
}

void Recipe::setIngredient(const IngredientItem& temp){
    _ingredient = temp;

}

IngredientItem Recipe::getIngredient() const{
    return _ingredient;
}
