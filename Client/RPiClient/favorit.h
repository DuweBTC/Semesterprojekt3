#ifndef FAVORIT_H
#define FAVORIT_H


#include <QDialog>
#include "mainwindow.h"
#include "account.h"
#include "HTTP.h"

/************************************************
 *  Contains methods of the class Favorit of the User Interface
 ***********************************************/

namespace Ui {
class Favorit;
}

class Favorit : public QDialog
{
    Q_OBJECT

public:
    explicit Favorit(QWidget *parent = nullptr, Account account = ("d", 2, 2));
    ~Favorit();

private slots:

    void on_pushButtonMenu_clicked();

private:
    Ui::Favorit *ui;
    Account account;
    void setText(QString text);
    HTTP http;
};

#endif // FAVORIT_H
