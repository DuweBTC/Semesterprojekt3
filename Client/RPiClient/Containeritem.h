#ifndef CONTAINERITEM_H
#define CONTAINERITEM_H

#include <QObject>
#include "Ingredientitem.h"

/************************************************
 *  Contains methods of the class ContainerItem
 ***********************************************/

class ContainerItem
{
public:
    ContainerItem(int ContainerId = 0, int Place = 0);
    int getContainerId() const;
    void setContainerId(int ContainerId);
    int getPlace() const;
    void setPlace(int Place);
    void operator=(ContainerItem &temp);
    void setIngredient(const IngredientItem& temp);
    IngredientItem getIngredient() const;
    ~ContainerItem();


private:
    int _ContainerId;
    int _Place;
    IngredientItem _ingredient;
};

#endif // CONTAINERITEM_H
