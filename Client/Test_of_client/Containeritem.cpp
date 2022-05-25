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


