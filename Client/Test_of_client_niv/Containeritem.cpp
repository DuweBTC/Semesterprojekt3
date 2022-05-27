#include "Containeritem.h"

ContainerItem::ContainerItem(int containerItemId, int place)
{
    setContainerId(containerItemId);
    setPlace(place);
}

int ContainerItem::getContainerId() const
{
    return _containerItemId;
}

void ContainerItem::setContainerId(int containerItemId)
{
    _containerItemId = containerItemId;
}

int ContainerItem::getPlace() const
{
    return _place;
}

void ContainerItem::setPlace(int place)
{
    _place = place;
}

void ContainerItem::operator=(const ContainerItem &temp){
    _containerItemId = temp.getContainerId();
    _place = temp.getPlace();
    _ingredient = temp.getIngredient();

}

void ContainerItem::setIngredient(const IngredientItem& temp){
    _ingredient = temp;
}

IngredientItem ContainerItem::getIngredient() const{
    return _ingredient;
}

ContainerItem::~ContainerItem(){

}
