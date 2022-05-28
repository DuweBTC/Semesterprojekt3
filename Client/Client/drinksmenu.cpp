#include "drinksmenu.h"
#include "ui_drinksmenu.h"

DrinksMenu::DrinksMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrinksMenu)
{
    ui->setupUi(this);

    QString text = "\nDrink Name: " + drink.getTitel() + "\nDescription: " + drink.getDescription() + "\nPrice: " + QString::number(drink.getPrice()) + " kr" ;
    setText(text);

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

void DrinksMenu::setText(QString text)
{
    ui->textBrowserDrinkInformation->setText(text);
    ui->textBrowserDrinkInformation->setFontPointSize(16);
    ui->textBrowserDrinkInformation->setAlignment(Qt::AlignCenter);

    ui->textBrowserDrinkInformation_2->setText(text);
    ui->textBrowserDrinkInformation_2->setFontPointSize(16);
    ui->textBrowserDrinkInformation_2->setAlignment(Qt::AlignCenter);
}



void DrinksMenu::on_pushButtonConfirm_clicked()
{
    //http.getDrink(QString::number(Drink.getDrinkId()),&Drink);
    drink.setTitel("Test");
    drink.setDescription("bla bla");
    //drink.getDrinkId(http.getDrinkListAmount());
    drink.setPrice(100);
   //http.getDrink(QString::number(drink.getDrinkId()),&drink);
    Recipe first(1,1);
    Recipe second(1,1);
    drink.setRecipe(first);
    drink.setRecipe(second);
    http.postDrink(&drink);


}


void DrinksMenu::on_pushButtonConfirm_2_clicked()
{
     //http.getDrink(QString::number(Drink.getDrinkId()),&Drink);

}

