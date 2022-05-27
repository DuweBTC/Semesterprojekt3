#ifndef INGREDIENTITEM_H
#define INGREDIENTITEM_H

#include <QObject>

class IngredientItem
{
public:
    IngredientItem(int ingredientItemId = 0, QString titel = "");
    int getIngredientItemId() const;
    void setIngredientItemId(int ingredientItemId);
    QString getTitel() const;
    void setTitel(QString titel);
    void operator=(const IngredientItem &temp);
    ~IngredientItem();


private:
    int _ingredientItemId;
    QString _titel;
};

#endif // INGREDIENTITEM_H
