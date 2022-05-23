#ifndef CONTAINERITEM_H
#define CONTAINERITEM_H

#include <QObject>

class ContainerItem
{
public:
    ContainerItem(int ContainerId = 0, int Place = 0);
    int getContainerId() const;
    void setContainerId(int ContainerId);
    int getPlace() const;
    void setPlace(int Place);

private:
    int _ContainerId;
    int _Place;
};

#endif // CONTAINERITEM_H
