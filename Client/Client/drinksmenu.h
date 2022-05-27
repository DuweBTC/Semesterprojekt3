#ifndef DRINKSMENU_H
#define DRINKSMENU_H

#include <QDialog>

namespace Ui {
class DrinksMenu;
}

class DrinksMenu : public QDialog
{
    Q_OBJECT

public:
    explicit DrinksMenu(QWidget *parent = nullptr);
    ~DrinksMenu();

private:
    Ui::DrinksMenu *ui;
};

#endif // DRINKSMENU_H
