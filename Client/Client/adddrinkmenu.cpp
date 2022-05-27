#include "adddrinkmenu.h"
#include "ui_adddrinkmenu.h"

AddDrinkMenu::AddDrinkMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDrinkMenu)
{
    ui->setupUi(this);
}

AddDrinkMenu::~AddDrinkMenu()
{
    delete ui;
}


void AddDrinkMenu::on_pushButtonAddDrink_clicked()
{


   drink.setTitel(ui->lineAddDrinkName->text());
   drink.setDescription("");
   //drink.getDrinkId(http.getDrinkListAmount());
   drink.setPrice(2103);
   Recipe first(1,1);
   Recipe second(1,1);
   drink.setRecipe(first);
   drink.setRecipe(second);
   http.postDrink(&drink);
}

