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
    return _titel;
}

void DrinkItem::setTitel(QString titel)
{
    _titel = titel;
}

int DrinkItem::getDrinkId() const
{
    return _drinkId;
}

void DrinkItem::setDrinkId(int drinkId)
{
    _drinkId = drinkId;
}

QString DrinkItem::getDescription() const
{
    return _description;
}

void DrinkItem::setDescription(QString description)
{
    _description = description;
}

double DrinkItem::getPrice() const
{
    return _price;
}

void DrinkItem::setPrice(double price)
{
    _price = price;
}

bool DrinkItem::operator==(const DrinkItem &rigthRef) const
{
    return ((_titel == rigthRef.getTitel()) &&
            (_drinkId == rigthRef.getDrinkId() &&
             _description == rigthRef.getDescription() &&
             _price == rigthRef.getPrice()));
}

void DrinkItem::setRecipe(Recipe & ingredient){
    _ingredients.push_back(ingredient);
}

std::list<Recipe> DrinkItem::getRecipe(){
    return _ingredients;
}
