#include "Ingredientitem.h"

IngredientItem::IngredientItem(int IngredientItemId, QString Titel)
{
    setIngredientItemId(IngredientItemId);
    setTitel(Titel);
}

int IngredientItem::getIngredientItemId() const
{
    return _IngredientItemId;
}

void IngredientItem::setIngredientItemId(int IngredientItemId)
{
    _IngredientItemId = IngredientItemId;
}

QString IngredientItem::getTitel() const
{
    return _Titel;
}

void IngredientItem::setTitel(QString Titel)
{
    _Titel = Titel;
}
