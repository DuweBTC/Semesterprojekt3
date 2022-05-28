#include "HTTP.h"
#include <QCoreApplication>
#include <QDebug>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QVariant>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include "mainwindow.h"

HTTP::HTTP()
{
}

std::list<Account> HTTP::getAccountList()
{
    std::list<Account> accountList;

    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    Account account_local;
    QJsonArray json_array;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    QString endpoint = "/Account";
    QNetworkRequest request(_url + endpoint);
    QNetworkReply *reply = mgr.get(request);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        json_array = jsonResponse.array();
        foreach (const QJsonValue &value, json_array)
            {
                QJsonObject json_account_obj = value.toObject();
                // Make a account object to the accountList
                accountList.push_back(Account(json_account_obj["accountItemId"].toInt(),
                                              json_account_obj["name"].toString(),
                                              json_account_obj["balance"].toDouble()));
            }

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return accountList;
}

bool HTTP::getAccount(QString id, Account *account)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    // Account account_local;

    // "quit()" thes event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
    const QString endpoint = "Account/";

    // the HTTP request
    QNetworkRequest req(_url + endpoint + id);
    qDebug() << "id: " + id;
    qDebug() << _url + endpoint + id;

    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        // Get respons as a object and put it in account pointer
        QJsonObject json_account_obj = jsonResponse.object();
        account->setAccountId(json_account_obj["accountItemId"].toInt());
        account->setName(json_account_obj["name"].toString());
        account->setBalance(json_account_obj["balance"].toDouble());

        // Debug
        qDebug() << "Get Id " + json_account_obj["accountItemId"].toString();
        qDebug() << "Get Name " + json_account_obj["name"].toString();
        qDebug() << "Get balance " + json_account_obj["balance"].toString();

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
        return false;
    }

    return true;
}

void HTTP::getAccountBalance(QString id, Account *account)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    // Account account_local;

    // "quit()" thes event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
    const QString endpoint = "Account/" + id + "/Balance";

    // the HTTP request
    QNetworkRequest req(_url + endpoint);
    qDebug() << _url + endpoint;

    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        account->setBalance(((QString)reply->readAll()).toDouble());

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }
}

void HTTP::postAccount(Account *account)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    QString endpoint = "Account/";
    QNetworkRequest request(_url + endpoint);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject jsonFormatAccount;
    jsonFormatAccount["accountItemId"] = QString::number(account->getAccountId());
    jsonFormatAccount["name"] = account->getName();
    jsonFormatAccount["balance"] = account->getBalance();
    qDebug() << "POST Id JSON: " + jsonFormatAccount["accountItemId"].toString();
    qDebug() << "POST Name JSON: " + jsonFormatAccount["name"].toString();
    qDebug() << "POST balance JSON: " + jsonFormatAccount["balance"].toString();

    QJsonDocument doc(jsonFormatAccount);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"Name\":\"account->getName()\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::putAccount(Account *account)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    const QString endpoint = "Account/";
    QString URL = _url + endpoint + QString::number(account->getAccountId());
    // const QUrl url(URL);
    QNetworkRequest request(URL);
    qDebug() << "id: " + QString::number(account->getAccountId());
    qDebug() << _url + endpoint + QString::number(account->getAccountId());

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject account_local;
    account_local["accountItemId"] = QString::number(account->getAccountId());
    account_local["name"] = account->getName();
    account_local["balance"] = account->getBalance();

    qDebug() << "Put: Name: " + account->getName() + " Balance " +
                    QString::number(account->getBalance()) + " Id: " + QString::number(account->getAccountId());

    QJsonDocument doc(account_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"key1\":\"value1\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->put(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::putAccountBalance(double amount, Account *account)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    const QString endpoint = "Account/";
    // This is a query to PUT in Balance
    QString URL = _url + endpoint + QString::number(account->getAccountId()) + "/Balance?amount=" +  QString::number(amount);
    QNetworkRequest request(URL);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Dummy object only use is to call function
    QJsonObject account_local;
    account_local["amount"] = account->getBalance();

    QJsonDocument doc(account_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"key1\":\"value1\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->put(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
                         if(reply->error() == QNetworkReply::NoError){
                             QString contents = QString::fromUtf8(reply->readAll());
                             qDebug() << contents;
                         }
                         else{
                             QString err = reply->errorString();
                             qDebug() << err;
                         }
                         reply->deleteLater(); });
}

void HTTP::deleteAccount(QString index)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QString endpoint = "Account/";
    QNetworkRequest request(_url + endpoint + index);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->deleteResource(request);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

QJsonArray HTTP::getRecipeList()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QJsonArray json_array;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    QString endpoint = "Recipe/";
    QNetworkRequest request(_url + endpoint);
    QNetworkReply *reply = mgr.get(request);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        json_array = jsonResponse.array();

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return json_array;
}

Recipe HTTP::getRecipe(QString id)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    Recipe recipe_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
    const QString endpoint = "Recipe/";

    // the HTTP request
    QNetworkRequest req(_url + endpoint + id);
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject json_recipe_obj = jsonResponse.object();
        QJsonObject json_recipeIngredient_obj = json_recipe_obj.value("ingredient").toObject();
        // QJsonObject json_account_obj = json_obj.value("place").toObject();
        // debug
        qDebug() << json_recipe_obj["recipeItemId"].toInt();
        qDebug() << json_recipe_obj["amount"].toDouble();
        qDebug() << json_recipeIngredient_obj["ingredientItemID"].toString();
        qDebug() << json_recipeIngredient_obj["titel"].toString();


        recipe_local.setRecipeItemId(json_recipe_obj["recipeItemId"].toInt());
        recipe_local.setIngredient(IngredientItem(json_recipeIngredient_obj["ingredientItemId"].toInt(), json_recipeIngredient_obj["titel"].toString()));
        recipe_local.setAmount(json_recipe_obj["amount"].toDouble());

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return recipe_local;
}

void HTTP::postRecipe(Recipe *recipe)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    QString endpoint = "Recipe/";
    QNetworkRequest request(_url + endpoint);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject recipe_local;
    QJsonObject ingredientJSON;
    recipe_local["recipeItemId"] = recipe->getRecipeItemId();
    recipe_local["amount"] = recipe->getAmount();
    ingredientJSON["ingredientItemId"] = (recipe->getIngredient()).getIngredientItemId();
    ingredientJSON["titel"] = (recipe->getIngredient().getTitel());
    recipe_local["ingredient"] = ingredientJSON;



    QJsonDocument doc(recipe_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"Name\":\"account->getName()\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::putRecipe(Recipe *recipe)
{

    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    QString endpoint = "Recipe/";
    QNetworkRequest request(_url + endpoint + QString::number(recipe->getRecipeItemId()));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject recipe_local;
    QJsonObject ingredientJSON;
    recipe_local["recipeItemId"] = recipe->getRecipeItemId();
    recipe_local["amount"] = recipe->getAmount();
    ingredientJSON["ingredientItemId"] = (recipe->getIngredient()).getIngredientItemId();
    ingredientJSON["titel"] = (recipe->getIngredient().getTitel());
    recipe_local["ingredient"] = ingredientJSON;

    QJsonDocument doc(recipe_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"key1\":\"value1\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->put(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::deleteRecipe(QString index)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    QString endpoint = "Recipe/";
    QNetworkRequest request(_url + endpoint + index);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->deleteResource(request);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

std::list<DrinkItem> HTTP::getDrinkList()
{
    std::list<DrinkItem> drinkList;
    QEventLoop eventLoop;
    QJsonArray json_array;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    QString endpoint = "Drink/";
    QNetworkRequest request(_url + endpoint);
    QNetworkReply *reply = mgr.get(request);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();
        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        json_array = jsonResponse.array();

        foreach (const QJsonValue &value, json_array)
            {
                QJsonObject json_drink_obj = value.toObject();
                // Make a account object to the accountList

                drinkList.push_back(DrinkItem(json_drink_obj["titel"].toString(),
                                    json_drink_obj["drinkItemId"].toInt(),
                                    json_drink_obj["description"].toString(),
                                    json_drink_obj["price"].toDouble()

                        ));
            }

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }
    return drinkList;
}

DrinkItem HTTP::getDrink(QString id)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    DrinkItem drink_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request

    const QString endpoint = "Drink/";
    QNetworkRequest req(_url + endpoint + id);
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject json_drink_obj = jsonResponse.object();

        // QJsonObject json_account_obj = json_obj.value("place").toObject();
        qDebug() << json_drink_obj["titel"].toString();
        qDebug() << json_drink_obj["drinkItemId"].toInt();
        qDebug() << json_drink_obj["description"].toString();
        qDebug() << json_drink_obj["price"].toDouble();

        drink_local.setTitel(json_drink_obj["titel"].toString());
        drink_local.setDrinkId(json_drink_obj["drinkItemId"].toInt());
        drink_local.setDescription(json_drink_obj["description"].toString());
        drink_local.setPrice(json_drink_obj["price"].toDouble());

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return drink_local;
}

void HTTP::postDrink(DrinkItem *drink)
{
    // Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    QString endpoint = "Drink/";
    QNetworkRequest request(_url + endpoint);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject drink_local;
    drink_local["titel"] = drink->getTitel();
    drink_local["drinkItemId"] = drink->getDrinkId();
    drink_local["description"] = drink->getDescription();
    drink_local["price"] = drink->getPrice();

    QJsonDocument doc(drink_local);
    QByteArray data = doc.toJson();
    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::putDrink(DrinkItem *drink)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    QString URL = _url + "Drink/" + QString::number(drink->getDrinkId());
    //  the HTTP request
    const QUrl url(URL);
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject drink_local;
    drink_local["titel"] = drink->getTitel();
    drink_local["drinkItemId"] = drink->getDrinkId();
    drink_local["description"] = drink->getDescription();
    drink_local["price"] = drink->getPrice();

    QJsonDocument doc(drink_local);
    QByteArray data = doc.toJson();
    QNetworkReply *reply = mgr->put(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::deleteDrink(QString index)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    QString const URL = _url + "Drink/" + index;
    const QUrl url(URL);
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->deleteResource(request);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

QJsonArray HTTP::getIngredientList()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QJsonArray json_array;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    QString endpoint = "Ingredient/";
    QNetworkRequest request(_url + endpoint);
    QNetworkReply *reply = mgr.get(request);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        json_array = jsonResponse.array();

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return json_array;
}

IngredientItem HTTP::getIngredient(QString id)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    IngredientItem ingredient_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    const QString endpoint = "Ingredient/";
    QNetworkRequest request(_url + endpoint + id);
    QNetworkReply *reply = mgr.get(request);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();
        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject json_ingredient_obj = jsonResponse.object();
        ingredient_local.setIngredientItemId(json_ingredient_obj["ingredientItemId"].toInt());
        ingredient_local.setTitel(json_ingredient_obj["titel"].toString());

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return ingredient_local;
}

void HTTP::postIngredient(IngredientItem *Ingredient)
{
    // "quit()" the event-loop, when the network request "finished()"
    // Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    const QString endpoint = "Ingredient/";
    QNetworkRequest request(_url + endpoint);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject ingredient_local;
    ingredient_local["IngredientItemId"] = Ingredient->getIngredientItemId();
    ingredient_local["Titel"] = Ingredient->getTitel();

    QJsonDocument doc(ingredient_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"Name\":\"account->getName()\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::putIngredient(IngredientItem *ingredient)
{

    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    ;
    const QString endpoint = "Ingredient/";
    QNetworkRequest request(_url + endpoint + QString::number(ingredient->getIngredientItemId()));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject ingredient_local;
    ingredient_local["IngredientItemId"] = ingredient->getIngredientItemId();
    ingredient_local["Titel"] = ingredient->getTitel();

    QJsonDocument doc(ingredient_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"key1\":\"value1\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->put(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::deleteIngredient(QString index)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    const QString endpoint = "Ingredient/";
    QNetworkRequest request(_url + endpoint + index);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->deleteResource(request);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

QJsonArray HTTP::getContainerList()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QJsonArray json_array;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    const QString endpoint = "Container/";
    QNetworkRequest request(_url + endpoint);
    QNetworkReply *reply = mgr.get(request);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        json_array = jsonResponse.array();

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return json_array;
}

ContainerItem HTTP::getContainer(QString id)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    ContainerItem container_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    const QString endpoint = "Container/";
    QNetworkRequest req(_url + endpoint + id);
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {
        QString strReply = (QString)reply->readAll();
        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject json_container_obj = jsonResponse.object();
        QJsonObject json_ingredient_obj = json_container_obj.value("ingredient").toObject();
        qDebug() << json_container_obj["containerItemId"].toString();
        qDebug() << json_container_obj["place"].toInt();

        container_local.setContainerId(json_container_obj["containerItemId"].toInt());
        container_local.setPlace(json_container_obj["place"].toInt());
        container_local.setIngredient(IngredientItem(json_ingredient_obj["ingredientItemId"].toInt(),
                                                        json_ingredient_obj["titel"].toString()));


        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return container_local;
}

void HTTP::postContainer(ContainerItem *container)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    const QString endpoint = "Container/";
    QNetworkRequest request(_url + endpoint);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject container_local;
    QJsonObject ingredientJSON;
    container_local["containerItemId"] = container->getContainerId();
    container_local["place"] = container->getPlace();
    ingredientJSON["ingredientItemId"] = (container->getIngredient()).getIngredientItemId();
    ingredientJSON["titel"] = (container->getIngredient().getTitel());
    container_local["ingredient"] = ingredientJSON;

    QJsonDocument doc(container_local);
    QByteArray data = doc.toJson();
    qDebug() << container_local;
    // or
    // QByteArray data("{\"Name\":\"account->getName()\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::putContainer(ContainerItem *container)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    const QString endpoint = "Container/";
    QNetworkRequest request(_url + endpoint + QString::number(container->getContainerId()));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject container_local;
    QJsonObject ingredientJSON;
    container_local["containerItemId"] = container->getContainerId();
    container_local["place"] = container->getPlace();
    ingredientJSON["ingredientItemId"] = (container->getIngredient()).getIngredientItemId();
    ingredientJSON["titel"] = (container->getIngredient().getTitel());
    container_local["ingredient"] = ingredientJSON;


    QJsonDocument doc(container_local);
    QByteArray data = doc.toJson();
    // or
    // QByteArray data("{\"key1\":\"value1\",\"key2\":\"value2\"}");
    QNetworkReply *reply = mgr->put(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}

void HTTP::deleteContainer(QString index)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    const QString endpoint = "Container/";
    QNetworkRequest request(_url + endpoint + index);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->deleteResource(request);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
                     {
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
        reply->deleteLater(); });
}
