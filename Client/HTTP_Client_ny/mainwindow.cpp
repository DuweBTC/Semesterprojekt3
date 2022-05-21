#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AccountButton(){
    account = dbDriver.getAccount();

}

void MainWindow::RecipeButton()
{
    recipe = dbDriver.getRecipe();
}

void MainWindow::DrinkButton()
{
    drinkItem = dbDriver.getDrink();
}

void MainWindow::IngredientButton()
{
    ingredientItem = dbDriver.getIngredient();
}

void MainWindow::ContainerButton()
{
    containerItem = dbDriver.getContainer();
}
