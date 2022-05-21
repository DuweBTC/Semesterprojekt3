#include "Drinkitem.h"

DrinkItem::DrinkItem(QString Titel, int DrinkId, QString Description, double Price)
{
    setTitel(Titel);
    setDrinkId(DrinkId);
    setDescription(Description);
    setPrice(Price);
}

QString DrinkItem::getTitel() const
{
    return _Titel;
}

void DrinkItem::setTitel(QString Titel)
{
    _Titel = Titel;
}

int DrinkItem::getDrinkId() const
{
    return _DrinkId;
}

void DrinkItem::setDrinkId(int DrinkId)
{
    _DrinkId = DrinkId;
}

QString DrinkItem::getDescription() const
{
    return _Description;
}

void DrinkItem::setDescription(QString Description)
{
    _Description = Description;
}

double DrinkItem::getPrice() const
{
    return _Price;
}

void DrinkItem::setPrice(double Price)
{
    _Price = Price;
}
