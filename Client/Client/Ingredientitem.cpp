#include "Ingredientitem.h"

IngredientItem::IngredientItem(int ingredientItemId, QString titel)
{
    setIngredientItemId(ingredientItemId);
    setTitel(titel);
}

int IngredientItem::getIngredientItemId() const
{
    return _ingredientItemId;
}

void IngredientItem::setIngredientItemId(int ingredientItemId)
{
    _ingredientItemId = ingredientItemId;
}

QString IngredientItem::getTitel() const
{
    return _titel;
}

void IngredientItem::setTitel(QString titel)
{
    _titel = titel;
}

void IngredientItem::operator=(const IngredientItem &temp){
    _titel = temp.getTitel();
    _ingredientItemId = temp.getIngredientItemId();
}

IngredientItem::~IngredientItem(){

}
