#ifndef FAVORITMENU_H
#define FAVORITMENU_H

#include <QDialog>
#include "mainwindow.h"
#include "account.h"
#include "databasedriver.h"

namespace Ui {
class FavoritMenu;
}

class FavoritMenu : public QDialog
{
    Q_OBJECT

public:
    explicit FavoritMenu(QWidget * parent = nullptr);
    ~FavoritMenu();



};

#endif // FAVORITMENU_H
