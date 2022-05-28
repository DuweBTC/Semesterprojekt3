#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include "startup.h"
#include "account.h"
#include "HTTP.h"

namespace Ui {
class NewUser;
}

class NewUser : public QDialog
{
    Q_OBJECT

public:
    explicit NewUser(QWidget *parent = nullptr, Account account = ("d", 3, 3));
    ~NewUser();

private slots:
    void on_pushButtonConfirm_clicked();

private:
    Ui::NewUser *ui;
    Account account;
    HTTP http;
};

#endif // NEWUSER_H
