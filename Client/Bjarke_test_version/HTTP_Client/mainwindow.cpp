#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textStartScreen->setVisible(true);
//   startscreen();
    ui->textKontoMenu->setVisible(false);


    // Initializes list object for latter use
//    makeDrinkList(dbDriver.getDrinkList());
//    makeContainerList(dbDriver.getContainerList());

    // We have to make a event loop or idk how, but have a funktion to scan student card
    // Initializes the RFID here
    scanStudentCard();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startscreen(){
    ui->textStartScreen->setVisible(true);
    ui->pushAddDrink->setVisible(false);
    ui->pushBalanceMenu->setVisible(false);
    ui->pushFavoritsMenu->setVisible(false);
    ui->pushKatalogMenu->setVisible(false);
    ui->pushKontoMenu->setVisible(false);
    ui->textKontoInformation->setVisible(false);
    ui->pushKontoMenu->setVisible(false);

}

int MainWindow::scanStudentCard(){
    int state = NO_CARD;
    int cardValue = 0;

    while (state == NO_CARD){
        // Call function for student card here
        //cardValue is just tested here
        cardValue = 1;

        if (cardValue != 0){
            ui->textStartScreen->setVisible(false);
            Account *accountPtr = &account;
            accountPtr = dbDriver.getAccount(QString::number(cardValue), accountPtr);
            qDebug() << accountPtr->getName();
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
    ui->pushAddDrink->setVisible(true);
    ui->pushBalanceMenu->setVisible(true);
    ui->pushFavoritsMenu->setVisible(true);
    ui->pushKatalogMenu->setVisible(true);
    ui->pushKontoMenu->setVisible(true);
}

void MainWindow::newUserWindow(){

}

void MainWindow::on_buttonBalanceMenu_clicked(){

}

void MainWindow::on_pushKontoMenu_clicked(){
    ui->pushKontoMenu->setVisible(true);
    //makeAccountList(dbDriver.getAccountList());

//    account = dbDriver.getAccount("1", account);
    qDebug() << account.getName();
    ui->textKontoInformation->setText(account.getName() + "\n " + QString::number(account.getBalance()) );
//    //Create an iterator of std::list
//    std::list<Account>::iterator it;


//    for (it = accountList.begin(); it != accountList.end(); it++)
//    {
//        // Access the object through iterator
//        ui->textKontoInformation->append("Name: " + it->getName());
//        qDebug() << it->getAccountId();
//    }

//    account = dbDriver.getAccount("1");
//    ui->textKontoInformation->setVisible(true);
//    ui->textKontoInformation->append(account.getName() + "\n " + QString::number(account.getBalance()) );

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


//void MainWindow::on_GetAccountButton_clicked(){
//    account.setAccountId(1);
//    //account = dbDriver.getAccount(QString::number(account.getAccountId()));
//    makeAccountList(dbDriver.getAccountList());

//    //Create an iterator of std::list
//    std::list<Account>::iterator it;

//    for (unsigned long i = 0; i < sizeof(accountList); i++){

//    for (it = accountList.begin(); it != accountList.end(); it++)
//    {
//        // Access the object through iterator
//        ui->textKontoInformation->append(it->getName());
//        qDebug() << it->getAccountId();
//    }
//    }

//}



//void MainWindow::on_PostAccountButton_clicked(){
//    account.setName("Duwe");
//    account.setAccountId(1);
//    account.setBalance(30000);
//    dbDriver.postAccount(&account);
//}
