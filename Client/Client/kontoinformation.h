#ifndef KONTOINFORMATION_H
#define KONTOINFORMATION_H

#include <QDialog>
#include "mainwindow.h"
#include "account.h"
#include "databasedriver.h"

namespace Ui {
class KontoInformation;
}

class KontoInformation : public QDialog
{
    Q_OBJECT

public:
    explicit KontoInformation(QWidget *parent = nullptr, Account account = ("d", 3, 3));
    ~KontoInformation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::KontoInformation *ui;
    Account account;
    void setText(QString text);
    DatabaseDriver http;
};

#endif // KONTOINFORMATION_H
