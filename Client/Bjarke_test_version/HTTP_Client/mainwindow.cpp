#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->GetAccountButton->setVisible(false);
    ui->PostAccountButton->setVisible(false);
    ui->buttonBalanceMenu->setVisible(false);


    // Initializes list object for latter use
    makeDrinkList(dbDriver.getDrinkList());
    makeContainerList(dbDriver.getContainerList());

    // We have to make a event loop or idk how, but have a funktion to scan student card
    // Initializes the RFID here
    scanStudentCard();


}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::scanStudentCard(){
    int state = NO_CARD;
    int cardValue = 0;

    while (state == NO_CARD){
        // Call function for student card here


        if (cardValue != 0){
            ui->textStartScreen->setVisible(false);
            account = dbDriver.getAccount(QString::number(cardValue));
            if (account.getAccountId() == cardValue){
                mainWindow();
            } else {
                newUserWindow();
            }

            state = CARD;

        }
    }


    return cardValue;
}

void MainWindow::mainWindow(){
    ui->buttonBalanceMenu->setVisible(true);
}

void MainWindow::newUserWindow(){

}

void MainWindow::on_buttonBalanceMenu_clicked(){

}



void MainWindow::on_GetAccountButton_clicked(){
    account.setAccountId(1);
    //account = dbDriver.getAccount(QString::number(account.getAccountId()));
    makeAccountList(dbDriver.getAccountList());

    //Create an iterator of std::list
    std::list<Account>::iterator it;

    for (unsigned long i = 0; i < sizeof(accountList); i++){

    for (it = accountList.begin(); it != accountList.end(); it++)
    {
        // Access the object through iterator
        ui->textBrowser->append(it->getName());
        qDebug() << it->getAccountId();
    }
    }

}



void MainWindow::on_PostAccountButton_clicked(){
    account.setName("Duwe");
    account.setAccountId(1);
    account.setBalance(30000);
    dbDriver.postAccount(&account);
}

void MainWindow::RecipeButton()
{
    //recipe = dbDriver.getRecipe();
}

void MainWindow::DrinkButton()
{
    //drinkItem = dbDriver.getDrink();
}

void MainWindow::IngredientButton()
{
    //ingredientItem = dbDriver.getIngredient();
}

void MainWindow::ContainerButton()
{
    //containerItem = dbDriver.getContainer();
}

void MainWindow::makeAccountList(QJsonArray accountJsonFormat){
    foreach (const QJsonValue &value, accountJsonFormat)
    {
        QJsonObject json_account_obj = value.toObject();
        // Make a account object to the accountList
        accountList.push_back(Account(json_account_obj["accountItemId"].toInt(),
                                        json_account_obj["name"].toString(),
                                        json_account_obj["balance"].toDouble()));
    }
}

void MainWindow::makeDrinkList(QJsonArray drinkJsonFormat){
    foreach (const QJsonValue &value, drinkJsonFormat)
    {
        QJsonObject json_drink_obj = value.toObject();
        // Make a account object to the accountList
        drinkList.push_back(DrinkItem(json_drink_obj["RecipeItemId"].toString(),
                                        json_drink_obj["Amount"].toInt(),
                                        json_drink_obj["Amount"].toString(),
                                        json_drink_obj["Amount"].toDouble()));

    }
}

void MainWindow::makeRecipetList(QJsonArray recipeJsonFormat){
    foreach (const QJsonValue &value, recipeJsonFormat)
    {
        QJsonObject json_recipe_obj = value.toObject();
        // Make a account object to the accountList
//        accountList.push_back(Account(json_account_obj["recipeItemId"].toInt(),
//                                        json_account_obj["ingredientItem"].ToObject(),
//                                        json_account_obj["amount"].toDouble()));

    }
}

void MainWindow::makeContainerList(QJsonArray containerJsonFormat){
    foreach (const QJsonValue &value, containerJsonFormat)
    {
        QJsonObject json_container_obj = value.toObject();
        // Make a account object to the accountList
//        drinkList.push_back(DrinkItem(json_container_obj["RecipeItemId"].toString(),
//                                        json_container_obj["containerItemId"].toInt(),
//                                        json_container_obj["place"].toString(),
//                                        json_container_obj["ingredientItem"].toObject()));

    }
}

void MainWindow::makeIngredienttList(QJsonArray ingredientJsonFormat){
    foreach (const QJsonValue &value, ingredientJsonFormat)
    {
        QJsonObject json_ingredient_obj = value.toObject();
        // Make a account object to the accountList
        ingredientList.push_back(IngredientItem(json_ingredient_obj["IngredientItemId"].toInt(),
                                        json_ingredient_obj["Titel"].toString()));

    }
}


