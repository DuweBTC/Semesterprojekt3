#include "Containeritem.h"

ContainerItem::ContainerItem(int ContainerId, int Place)
{
    setContainerId(ContainerId);
    setPlace(Place);
}

int ContainerItem::getContainerId() const
{
    return _ContainerId;
}

void ContainerItem::setContainerId(int ContainerId)
{
    _ContainerId = ContainerId;
}

int ContainerItem::getPlace() const
{
    return _Place;
}

void ContainerItem::setPlace(int Place)
{
    _Place = Place;
}

void ContainerItem::operator=(const ContainerItem &temp){
    _ContainerId = temp.getContainerId();
    _Place = temp.getPlace();
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
