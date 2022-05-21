#include "Containeritem.h"

ContainerItem::ContainerItem(QString ContainerId, int Place)
{
    setContainerId(ContainerId);
    setPlace(Place);
}

QString ContainerItem::getContainerId() const
{
    return _ContainerId;
}

void ContainerItem::setContainerId(QString ContainerId)
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
