#ifndef INGREDIENTITEM_H
#define INGREDIENTITEM_H

#include <QObject>

class IngredientItem
{
public:
    IngredientItem(int IngredientItemId = 0, QString Titel = "");
    int getIngredientItemId() const;
    void setIngredientItemId(int IngredientItemId);
    QString getTitel() const;
    void setTitel(QString Titel);

private:
    int _IngredientItemId;
    QString _Titel;
};

#endif // INGREDIENTITEM_H
