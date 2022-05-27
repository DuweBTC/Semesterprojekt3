#ifndef DRINKITEM_H
#define DRINKITEM_H

#include <QObject>
#include "Recipe.h"

class DrinkItem
{
public:
    DrinkItem(QString Titel = "", int DrinkId = 0, QString Description = "", double Price = 0);
    QString getTitel() const;
    void setTitel(QString Titel);
    int getDrinkId() const;
    void setDrinkId(int DrinkId);
    QString getDescription() const;
    void setDescription(QString Description);
    double getPrice() const;
    void setPrice(double Price);
    bool operator==(const DrinkItem &) const;
    void setRecipe(Recipe & ingredient);
    std::list<Recipe> getRecipe();

private:
    QString _titel;
    int _drinkId;
    QString _description;
    double _price;
    std::list<Recipe> _ingredients;
};

#endif // DRINKITEM_H
