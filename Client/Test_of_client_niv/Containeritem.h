#ifndef CONTAINERITEM_H
#define CONTAINERITEM_H

#include <QObject>
#include "Ingredientitem.h"

class ContainerItem
{
public:
    ContainerItem(int containerItemId = 0, int place = 0);
    int getContainerId() const;
    void setContainerId(int containerItemId);
    int getPlace() const;
    void setPlace(int place);
    //void operator=(ContainerItem &temp);
    void operator=(const ContainerItem &temp);
    void setIngredient(const IngredientItem& temp);
    IngredientItem getIngredient() const;
    ~ContainerItem();


private:
    int _containerItemId;
    int _place;
    IngredientItem _ingredient;
};

#endif // CONTAINERITEM_H
