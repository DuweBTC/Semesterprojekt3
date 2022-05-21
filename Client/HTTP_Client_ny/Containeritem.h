#ifndef CONTAINERITEM_H
#define CONTAINERITEM_H

#include <QObject>

class ContainerItem
{
public:
    ContainerItem(QString ContainerId = "", int Place = 0);
    QString getContainerId() const;
    void setContainerId(QString ContainerId);
    int getPlace() const;
    void setPlace(int Place);

private:
    QString _ContainerId;
    int _Place;
};

#endif // CONTAINERITEM_H
