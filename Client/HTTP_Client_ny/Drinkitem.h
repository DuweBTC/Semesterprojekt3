#ifndef DRINKITEM_H
#define DRINKITEM_H

#include <QObject>

class DrinkItem
{
public:
    DrinkItem(QString Titel = "", int DrinkId = 0, QString Description = "", double Price = 0);
    QString getTitel()const;
    void setTitel(QString Titel);
    int getDrinkId()const;
    void setDrinkId(int DrinkId);
    QString getDescription()const;
    void setDescription(QString Description);
    double getPrice()const;
    void setPrice(double Price);

private:
    QString _Titel;
    int _DrinkId;
    QString _Description;
    double _Price;

};

#endif // DRINKITEM_H
