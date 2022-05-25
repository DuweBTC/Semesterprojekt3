#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //   startscreen();
    //
    WindowMenu = SCAN_CARD_MENU;
    setText("Scan Card");

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

void MainWindow::startscreen()
{

    //    ui->pushAddDrink->hide();
    //    ui->pushBalanceMenu->hide();
    //    ui->pushFavoritsMenu->hide();
    //    ui->pushKatalogMenu->hide();
    //    ui->pushKontoMenu->hide();
    // ui->TextBalance->hide();
}

int MainWindow::scanStudentCard()
{
    int state = NO_CARD;
    int cardValue = 0;

    while (state == NO_CARD)
    {
        // Call function for student card here
        // cardValue is just tested here
        cardValue = 1;

        if (cardValue != 0)
        {
            // ui->textStartScreen->hide();

            dbDriver.getAccount(QString::number(cardValue), accountPtr);
            qDebug() << accountPtr->getName();

            if (account.getAccountId() == cardValue)
            {
                mainWindow();
            }
            else
            {
                newUserWindow();
            }

            state = CARD;
        }
    }

    return cardValue;
}

void MainWindow::mainWindow()
{
    WindowMenu = MAIN_MENU;
    setText("Main Menu");
    if (WindowMenu == MAIN_MENU)
    {
        ui->textInformation->show();
        ui->pushMainMenu->show();
        ui->pushAddDrink->show();
        ui->pushBalanceMenu->show();
        ui->pushFavoritsMenu->show();
        ui->pushKatalogMenu->show();
        ui->pushKontoMenu->show();
    }
}

void MainWindow::newUserWindow()
{
    WindowMenu = NEW_USER_MENU;
    setText("New User");
    // Disable all button on menu
    if (WindowMenu == NEW_USER_MENU)
    {
        //    ui->textInformation->hide();
        //    ui->pushMainMenu->hide();
        //    ui->pushAddDrink->hide();
        //    ui->pushBalanceMenu->hide();
        //    ui->pushFavoritsMenu->hide();
        //    ui->pushKatalogMenu->hide();
        //    ui->pushKontoMenu->hide();
    }

    // UI to make a account
    on_pushInsertName_clicked();
}

// On_button_clicked
//------------------------------------------------------------------------------------
void MainWindow::on_pushMainMenu_clicked()
{
    mainWindow();
}

void MainWindow::on_pushKatalogMenu_clicked()
{
    setText("Drinks");
}

void MainWindow::on_pushBalanceMenu_clicked()
{
    setText("Change Balance");
    dbDriver.putAccountBalance(ui->textInsertBalance->toPlainText(), accountPtr);
    ui->textInformation->setText("Konto Information: \nName: " + account.getName() + "\nBalance: " + QString::number(account.getBalance()));
}

void MainWindow::on_pushFavoritsMenu_clicked()
{
    setText("Favorit Menu");
}

void MainWindow::on_pushAddDrink_clicked()
{
    setText("Add Drink Menu");
}

void MainWindow::on_buttonBalanceMenu_clicked()
{
    ui->pushBalanceMenu->show();
    dbDriver.putAccountBalance(ui->textInsertBalance->toPlainText(), accountPtr);
    ui->textInformation->setText("Konto Information: \nName: " + account.getName() + "\nBalance: " + QString::number(account.getBalance()));
}

void MainWindow::on_pushPut_clicked()
{
    // Set ID form textbox and the update
    // Should be written better than this
    account.setAccountId((ui->textId->toPlainText()).toInt());
    dbDriver.getAccount(QString::number(account.getAccountId()), accountPtr);
    account.setAccountId((ui->textId->toPlainText()).toInt());
    account.setBalance((ui->textInsertBalance->toPlainText()).toDouble());
    account.setName((ui->textInsertName->toPlainText()));

    qDebug() << "PUT NAME: " + account.getName();
    qDebug() << "PUT ID: " + QString::number(account.getAccountId());
    qDebug() << "PUT BALANCE: " + QString::number(account.getBalance());
    dbDriver.putAccount(&account);

    mainWindow();
}

void MainWindow::on_pushKontoMenu_clicked()
{
    setText("Konto Information");
    account.setAccountId((ui->textId->toPlainText()).toInt());
    dbDriver.getAccount(QString::number(account.getAccountId()), accountPtr);
    ui->textInformation->setText("Konto Information: \nName: " + account.getName() + "\nBalance: " + QString::number(account.getBalance()));
}

void MainWindow::on_pushGetAllKonto_clicked()
{
    makeAccountList(dbDriver.getAccountList());
    // Create an iterator of std::list
    std::list<Account>::iterator it;
    ui->textInformation->setText("");

    for (it = accountList.begin(); it != accountList.end(); it++)
    {
        // Access the object through iterator
        ui->textInformation->append("Name: " + it->getName() + "\n");
        qDebug() << it->getAccountId();
    }
}

void MainWindow::on_pushInsertName_clicked()
{
    account.setName(ui->textInsertName->toPlainText());
    account.setAccountId((ui->textId->toPlainText()).toInt());
    account.setBalance(0);
    qDebug() << "POST NAME: " + account.getName();
    qDebug() << "POST ID: " + QString::number(account.getAccountId());
    qDebug() << "POST BALANCE: " + QString::number(account.getBalance());
    dbDriver.postAccount(&account);
    //    ui->pushInsertName->hide();
    //    ui->textInsertName->hide();
    mainWindow();
}

void MainWindow::on_pushDelete_clicked()
{
    dbDriver.deleteAccount(ui->textId->toPlainText());
    mainWindow();
}

void MainWindow::on_pushIdBalance_clicked(){
    setText("Balance By ID");
    dbDriver.getAccountBalance(ui->textId->toPlainText(), accountPtr);
    ui->textInformation->setText("Konto Information: \nName: " + account.getName() + "\nBalance: " + QString::number(account.getBalance()));
}



// SECTION TO MAKE LIST OBJECTS
//-----------------------------------------------------------------------------------
void MainWindow::makeAccountList(QJsonArray accountJsonFormat)
{
    foreach (const QJsonValue &value, accountJsonFormat)
    {
        QJsonObject json_account_obj = value.toObject();
        // Make a account object to the accountList
        accountList.push_back(Account(json_account_obj["accountItemId"].toInt(),
                                      json_account_obj["name"].toString(),
                                      json_account_obj["balance"].toDouble()));
    }
}

void MainWindow::makeDrinkList(QJsonArray drinkJsonFormat)
{
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

void MainWindow::makeRecipetList(QJsonArray recipeJsonFormat)
{
    foreach (const QJsonValue &value, recipeJsonFormat)
    {
        QJsonObject json_recipe_obj = value.toObject();
        // Make a account object to the accountList
        //        accountList.push_back(Account(json_account_obj["recipeItemId"].toInt(),
        //                                        json_account_obj["ingredientItem"].ToObject(),
        //                                        json_account_obj["amount"].toDouble()));
    }
}

void MainWindow::makeContainerList(QJsonArray containerJsonFormat)
{
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

void MainWindow::makeIngredienttList(QJsonArray ingredientJsonFormat)
{
    foreach (const QJsonValue &value, ingredientJsonFormat)
    {
        QJsonObject json_ingredient_obj = value.toObject();
        // Make a account object to the accountList
        ingredientList.push_back(IngredientItem(json_ingredient_obj["IngredientItemId"].toInt(),
                                                json_ingredient_obj["Titel"].toString()));
    }
}

void MainWindow::setText(QString text)
{
    ui->textMenu->setText(text);
    ui->textMenu->setFontPointSize(36);
    ui->textMenu->setAlignment(Qt::AlignCenter);
}

// void MainWindow::on_GetAccountButton_clicked(){
//     account.setAccountId(1);
//     //account = dbDriver.getAccount(QString::number(account.getAccountId()));
//     makeAccountList(dbDriver.getAccountList());

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

// void MainWindow::on_PostAccountButton_clicked(){
//     account.setName("Duwe");
//     account.setAccountId(1);
//     account.setBalance(30000);
//     dbDriver.postAccount(&account);
// }
