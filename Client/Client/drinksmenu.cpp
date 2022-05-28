#include "drinksmenu.h"
#include "ui_drinksmenu.h"

DrinksMenu::DrinksMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrinksMenu)
{
    ui->setupUi(this);

    drinkList = http.getDrinkList();
    setText();

}

DrinksMenu::~DrinksMenu()
{
    delete ui;
}

// Button for Main Menu
void DrinksMenu::on_pushButton_clicked()
{
    hide();
    MainWindow mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();

}





void DrinksMenu::on_pushButtonBuyDrink_1_clicked()
{
    http.postDrink(&drinkList[0]);
}


void DrinksMenu::on_pushButtonBuyDrink_2_clicked()
{
     http.postDrink(&drinkList[1]);
}

void DrinksMenu::setText()
{
    QString text[drinkList.size()];
    int textItems = 0;

    for (auto iterator = drinkList.begin(); iterator != drinkList.end(); iterator++)
    {
        text[textItems] = "\nDrink Name: " + iterator->getTitel() + "\nDescription: "
                            + iterator->getDescription() + "\nPrice: " + QString::number(iterator->getPrice()) + " kr" ;
        textItems++;
    }

    ui->textBrowserDrinkInformation_1->setText(text[0]);
    ui->textBrowserDrinkInformation_1->setFontPointSize(16);
    ui->textBrowserDrinkInformation_1->setAlignment(Qt::AlignCenter);

    ui->textBrowserDrinkInformation_2->setText(text[1]);
    ui->textBrowserDrinkInformation_2->setFontPointSize(16);
    ui->textBrowserDrinkInformation_2->setAlignment(Qt::AlignCenter);
}
