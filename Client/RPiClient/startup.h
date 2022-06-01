#ifndef STARTUP_H
#define STARTUP_H

#include <QMainWindow>
#include "newuser.h"
#include "mainwindow.h"
#include "account.h"
#include "HTTP.h"

/************************************************
 *  Contains methods of the class StartUp of the User Interface
 ***********************************************/

QT_BEGIN_NAMESPACE
namespace Ui { class StartUp; }
QT_END_NAMESPACE

class StartUp : public QMainWindow
{
    Q_OBJECT

public:
    StartUp(QWidget *parent = nullptr);
    ~StartUp();

    Account account;
    HTTP http;


private slots:
    void on_pushButtonCardScan_clicked();

private:
    Ui::StartUp *ui;
    enum state {NEW_USER, USER};
    int user = NEW_USER;


};
#endif // STARTUP_H
