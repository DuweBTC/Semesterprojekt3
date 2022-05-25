#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    run();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run()
{

    //    ui->pushAddDrink->hide();
    //    ui->pushBalanceMenu->hide();
    //    ui->pushFavoritsMenu->hide();
    //    ui->pushKatalogMenu->hide();
    //    ui->pushKontoMenu->hide();
    // ui->TextBalance->hide();

    for (;;){
    setText("Scan Card");
    // Initializes list object for latter use
    //drinkList =
    //    makeDrinkList(dbDriver.getDrinkList());
    //    makeContainerList(dbDriver.getContainerList());

    // We have to make a event loop or idk how, but have a funktion to scan student card
    // Initializes the RFID here

    startscreen();
    }
}

// Event Scan card
//-------------------------------------------------------------------------------------
int MainWindow::startscreen()
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


            qDebug() << accountPtr->getName();

            // If there is no exiting account of that ID call window for new user
            // Else call main window
            if (!(dbDriver.getAccount(QString::number(cardValue), accountPtr)) )
            {
                newUserWindow();
            }

            mainWindow();
            state = CARD;
        }
    }

    return cardValue;
}


// Event New User
//------------------------------------------------------------------------------------
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
    on_pushGetAccount_clicked();
}

// Events for Main
//------------------------------------------------------------------------------------
void MainWindow::on_pushMainMenu_clicked()
{
    mainWindow();
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
        ui->pushGetAccountBalance->show();
        ui->pushFavoritsMenu->show();
        ui->pushGetDrink->show();
        ui->pushGetAccount->show();
    }
}


void MainWindow::on_pushFavoritsMenu_clicked()
{
    setText("Favorit Menu");
    account.getFavorits();
    std::list<DrinkItem>::iterator it;
    ui->textInformation->setText("");

    for (it = account.getFavorits().begin(); it != account.getFavorits().end(); it++)
    {
        // Access the object through iterator
        ui->textInformation->append("Drink: " + it->getTitel() + "\n" +
                                    "\nPrice: " + QString::number(it->getPrice()) +
                                    "\n Description: " + it->getDescription() +
                                    "\n Ingredients: "
                                    );
        qDebug() << it->getTitel();
    }
}


// Events for Account
//------------------------------------------------------------------------------------

// GET Account
void MainWindow::on_pushGetAccount_clicked()
{
    setText("Konto Information");
    account.setAccountId((ui->textId->toPlainText()).toInt());
    dbDriver.getAccount(QString::number(account.getAccountId()), accountPtr);
    ui->textInformation->setText("Konto Information: \nName: " + account.getName() + "\nBalance: " + QString::number(account.getBalance()));
}

// GET ALL Accounts
void MainWindow::on_pushGetAllAccount_clicked()
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

// GET Account Balance
void MainWindow::on_pushGetAccountBalance_clicked()
{
    setText("Balance By ID");
    dbDriver.getAccountBalance(ui->textId->toPlainText(), accountPtr);
    ui->textInformation->setText("Konto Information: \nName: " + account.getName() + "\nBalance: " + QString::number(account.getBalance()));
}

// POST Account
void MainWindow::on_pushPostAccount_clicked()
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


// PUT Account Balance
void MainWindow::on_pushPutAccountBalance_clicked()
{
    setText("Change Balance");
    dbDriver.getAccount(ui->textId->toPlainText(), accountPtr);
    qDebug() << "Change balance button " + ui->textInsertBalance->toPlainText();
    dbDriver.putAccountBalance((ui->textInsertBalance->toPlainText()).toDouble(), accountPtr);
    ui->textInformation->setText("Konto Information: \nName: " + account.getName() + "\nBalance: " + QString::number(account.getBalance()));
}

// PUT Account
void MainWindow::on_pushPutAccount_clicked()
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

// DELETE Account
void MainWindow::on_pushDeleteAccount_clicked()
{
    dbDriver.deleteAccount(ui->textId->toPlainText());
    mainWindow();
}

// Add drink to Favorits
void MainWindow::on_pushAddFavorits_clicked(){
    dbDriver.getAccount(QString::number(account.getAccountId()), accountPtr);
    account.addFavorits(drinkItem);
    dbDriver.putAccount(accountPtr);
}

// Delete Drink from Favorits
void MainWindow::on_pushDeleteFavorits_clicked(){
    dbDriver.getAccount(QString::number(account.getAccountId()), accountPtr);
    account.deleteFavorits(drinkItem);
    dbDriver.putAccount(accountPtr);
}

// Events for Ingredient
//------------------------------------------------------------------------------------
void MainWindow::on_pushGetIngredient_clicked(){
    setText("Get Ingredient");
    ingredientItem.setIngredientItemId((ui->textId->toPlainText()).toInt());

    ingredientItem = dbDriver.getIngredient(QString::number(ingredientItem.getIngredientItemId()));
    ui->textInformation->setText("Ingredient Information: \nName: " + ingredientItem.getTitel()
                                 + "\nID: " + QString::number(ingredientItem.getIngredientItemId()));
}

void MainWindow::on_pushPostIngredient_clicked(){
    setText("Post Ingredient");
    ingredientItem.setIngredientItemId((ui->textId->toPlainText()).toInt());
    ingredientItem.setTitel(ui->textInsertName->toPlainText());
    dbDriver.postIngredient(&ingredientItem);
}

void MainWindow::on_pushPutIngredient_clicked(){
    setText("Put Ingredient");
    ingredientItem.setIngredientItemId((ui->textId->toPlainText()).toInt());
    ingredientItem.setTitel(ui->textInsertName->toPlainText());
    dbDriver.putIngredient(&ingredientItem);
}

void MainWindow::on_pushDeleteIngredient_clicked(){
    setText("Delete Ingredient");
    ingredientItem.setIngredientItemId((ui->textId->toPlainText()).toInt());
    dbDriver.putIngredient(&ingredientItem);
}

void MainWindow::on_pushGetAllIngredient_clicked(){
    makeIngredientList(dbDriver.getIngredientList());
    // Create an iterator of std::list
    std::list<IngredientItem>::iterator it;
    ui->textInformation->setText("");

    for (it = ingredientList.begin(); it != ingredientList.end(); it++)
    {
        // Access the object through iterator
        ui->textInformation->append("Name: " + it->getTitel() + "\n");
        qDebug() << it->getTitel();
    }
}


// Events for Recipe
//------------------------------------------------------------------------------------
void MainWindow::on_pushGetRecipe_clicked(){
    setText("Get Recipe");
    getRecipe();
}

void MainWindow::on_pushPostRecipe_clicked(){
    setText("Post Recipe");

    recipe.setRecipeItemId((recipeList.size() + 1));
    recipe.setAmount((ui->textInsertName->toPlainText()).toDouble());
    recipe.setIngredient(IngredientItem((ingredientList.size() + 1), ui->textInsertName->toPlainText()));
    dbDriver.postRecipe(&recipe);
}

void MainWindow::on_pushPutRecipe_clicked(){
    setText("Put Recipe");
    recipe.setRecipeItemId((ui->textId->toPlainText()).toInt());
    recipe.setIngredient(IngredientItem((ingredientList.size() + 1), ui->textInsertName->toPlainText()));
    dbDriver.putIngredient(&ingredientItem);
}

void MainWindow::on_pushDeleteRecipe_clicked(){
    setText("Delete Recipe");
    recipe.setRecipeItemId((ui->textId->toPlainText()).toInt());
    dbDriver.putRecipe(&recipe);
}

void MainWindow::on_pushGetAllRecipe_clicked(){
    makeRecipeList(dbDriver.getRecipeList());

    // Create an iterator of std::list
    std::list<Recipe>::iterator it;
    ui->textInformation->setText("");

    for (it = recipeList.begin(); it != recipeList.end(); it++)
    {
        // Access the object through iterator
        ui->textInformation->append("Name: " + (it->getIngredient()).getTitel() + "\n");
        qDebug() << it->getAmount();
    }
}

// Events for Container
//------------------------------------------------------------------------------------
void MainWindow::on_pushGetContainer_clicked(){
    /*setText("Get Ingredient");
    ingredientItem.setIngredientItemId((ui->textId->toPlainText()).toInt());

    ingredientItem = dbDriver.getIngredient(QString::number(ingredientItem.getIngredientItemId()));
    ui->textInformation->setText("Ingredient Information: \nName: " + ingredientItem.getTitel()
                                 + "\nID: " + QString::number(ingredientItem.getIngredientItemId()));*/
    setText("Get Container");
    containerItem.setContainerId((ui->textId->toPlainText()).toInt());

    ContainerItem containerTemp = dbDriver.getContainer(QString::number(containerItem.getContainerId()));
    containerItem = containerTemp;

    //containerItem = dbDriver.getContainer(QString::number(containerItem.getContainerId()));
    ui->textInformation->setText("Container information: \nName: " + QString::number(containerItem.getContainerId()));

}

void MainWindow::on_pushPostContainer_clicked(){
    setText("Post Container");
    containerItem.setContainerId((ui->textId->toPlainText()).toInt());
    containerItem.setPlace((ui->textInsertName->toPlainText()).toInt());
    dbDriver.postContainer(&containerItem);

}

void MainWindow::on_pushPutContainer_clicked(){
    setText("Put Container");
    containerItem.setContainerId((ui->textId->toPlainText()).toInt());
    containerItem.setPlace((ui->textInsertName->toPlainText()).toInt());
    containerItem.setIngredient(IngredientItem((containerItem.getIngredient().getIngredientItemId()), ui->textInsertName->toPlainText()));
    dbDriver.putIngredient(&ingredientItem);
}

void MainWindow::on_pushDeleteContaier_clicked(){
    setText("Delete Container");
    containerItem.setContainerId((ui->textId->toPlainText()).toInt());
    dbDriver.putContainer(&containerItem);
}

void MainWindow::on_pushGetAllContainer_clicked(){
    makeContainerList(dbDriver.getContainerList());

    // Create an iterator of std::list
    std::list<ContainerItem>::iterator it;
    ui->textInformation->setText("");

    for (it = containerList.begin(); it != containerList.end(); it++)
    {
        // Access the object through iterator
        ui->textInformation->append("Place: " + QString::number(it->getPlace()) +
                                    "\nIngredient: " + (it->getIngredient()).getTitel() +
                                    "\nIngredient id :" + QString::number((it->getIngredient()).getIngredientItemId())
                                    );
        qDebug() << QString::number(it->getPlace());
    }
}

// Events for Drink
//------------------------------------------------------------------------------------



void MainWindow::on_pushGetDrink_clicked()
{
    setText("Add Drink Menu");
}

void MainWindow::on_pushGetAllDrink_clicked()
{
    setText("Drinks");
}

void MainWindow::on_pushPostDrink_clicked(){
    setText("Post Drink");
    drinkItem.setDrinkId((ui->textId->toPlainText()).toInt());
    drinkItem.setDescription((ui->textInsertName->toPlainText()));
    drinkItem.setTitel((ui->textInsertName->toPlainText()));
    drinkItem.setPrice((ui->textInsertBalance->toPlainText()).toInt());
    dbDriver.postDrink(&drinkItem);
}

void MainWindow::on_pushPutDrink_clicked(){
    setText("Put Drink");
    drinkItem.setDrinkId((ui->textId->toPlainText()).toInt());
    drinkItem.setDescription((ui->textInsertName->toPlainText()));
    drinkItem.setTitel(ui->textInsertName->toPlainText());
    drinkItem.setPrice((ui->textInsertBalance->toPlainText()).toInt());
    drinkItem.setRecipe(recipe);
    dbDriver.putDrink(&drinkItem);
}

void MainWindow::on_pushDeleteDrink_clicked(){
    setText("Delete Container");
    drinkItem.setDrinkId((ui->textId->toPlainText()).toInt());
    dbDriver.putDrink(&drinkItem);
}

// GET Recipe
//-------------------------------------------------------------------------------------
void MainWindow::getRecipe(){
    recipe.setRecipeItemId((ui->textId->toPlainText()).toInt());
    recipe = dbDriver.getRecipe(QString::number(recipe.getRecipeItemId()));
    ui->textInformation->setText("Recipe Information: \nId: " + QString::number(recipe.getRecipeItemId())
                             + "\nAmount: " + QString::number(recipe.getAmount()) +
                             "\nIngredient titel: " + (recipe.getIngredient()).getTitel()
                             + "\nIngredient id:" +
                             QString::number((recipe.getIngredient()).getIngredientItemId()));
}

// SECTION TO MAKE LIST OBJECTS
//-----------------------------------------------------------------------------------
void MainWindow::makeAccountList(QJsonArray accountJsonFormat)
{
    accountList.clear();
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
    drinkList.clear();
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

void MainWindow::makeRecipeList(QJsonArray recipeJsonFormat)
{
    recipeList.clear();
    foreach (const QJsonValue &value, recipeJsonFormat)
    {
        // Make a account object to the accountList

        QJsonObject json_recipe_obj = value.toObject();
        QJsonObject json_recipeIngredient_obj = json_recipe_obj.value("ingredient").toObject();
        // Make a account object to the accountList
        recipe.setRecipeItemId(json_recipe_obj["recipeItemId"].toInt());
        recipe.setIngredient(IngredientItem(json_recipeIngredient_obj["ingredientItemId"].toInt(), json_recipeIngredient_obj["titel"].toString()));
        recipe.setAmount(json_recipe_obj["amount"].toDouble());
        qDebug() << "Recipe list " + QString::number(recipe.getRecipeItemId());
        qDebug() << "Recipe list " + QString::number(recipe.getAmount());
        qDebug() << "Recipe list " + QString::number((recipe.getIngredient()).getIngredientItemId());
        qDebug() << "Recipe list " + (recipe.getIngredient()).getTitel();
        recipeList.push_back(recipe);

    }
}

void MainWindow::makeContainerList(QJsonArray containerJsonFormat)
{
    containerList.clear();
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

void MainWindow::makeIngredientList(QJsonArray ingredientJsonFormat)
{
    ingredientList.clear();
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
