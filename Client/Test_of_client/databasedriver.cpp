#include "databasedriver.h"
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

DatabaseDriver::DatabaseDriver()
{
}

QJsonArray DatabaseDriver::getAccountList()
{
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

Account* DatabaseDriver::getAccount(QString id, Account *account)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    //Account account_local;

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
        qDebug() << "Get Id " +json_account_obj["accountItemId"].toString();
        qDebug() << "Get Name " + json_account_obj["name"].toString();
        qDebug() << "Get balance " + json_account_obj["balance"].toString();

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return account;
}

void DatabaseDriver::getAccountBalance(QString id, Account *account)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    //Account account_local;

    // "quit()" thes event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
    const QString endpoint = "Account/" + id + "/Balance";

    // the HTTP request
    QNetworkRequest req(_url + endpoint );
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

void DatabaseDriver::postAccount(Account *account)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    QString endpoint = "Account/";
    QNetworkRequest request(_url + endpoint);


    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject jsonFormatAccount;
    jsonFormatAccount["accountItemId"] = QString::number(account->getAccountId());
    jsonFormatAccount["name"] = account->getName();
    jsonFormatAccount["balance"] = account->getBalance();
    qDebug() << "POST Id JSON: " +jsonFormatAccount["accountItemId"].toString();
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

void DatabaseDriver::putAccount(Account *account)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    const QString endpoint = "Account/";
    QString URL = _url + endpoint + QString::number(account->getAccountId());
    //const QUrl url(URL);
    QNetworkRequest request(URL);
    qDebug() << "id: " + QString::number(account->getAccountId());
    qDebug() << _url + endpoint + QString::number(account->getAccountId());

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject account_local;
    account_local["accountItemId"] = QString::number(account->getAccountId());
    account_local["name"] = account->getName();
    account_local["balance"] = account->getBalance();

    qDebug() << "Put: Name: " + account->getName() + " Balance " +
                QString::number(account->getBalance()) + " Id: "
                + QString::number(account->getAccountId());

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


void DatabaseDriver::putAccountBalance(QString amount, Account *account)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    const QString endpoint = "Account/";

    QString URL = _url + endpoint + QString::number(account->getAccountId()) + "/" + amount;

    //const QUrl url(URL);
    QNetworkRequest request(URL);
    qDebug() << "id: " + QString::number(account->getAccountId());
    qDebug() << _url + endpoint + QString::number(account->getAccountId());

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject account_local;
    account_local["accountItemId"] = QString::number(account->getAccountId());
    account_local["name"] = account->getName();
    account_local["balance"] = amount;

    qDebug() << "Put: Name: " + account->getName() + " Balance " +
                    QString::number(account->getBalance()) + " Id: "
                    + QString::number(account->getAccountId());

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

void DatabaseDriver::deleteAccount(QString index)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QString endpoint = "Account/";
    QNetworkRequest request(_url + endpoint + index );

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

QJsonArray DatabaseDriver::getRecipeList()
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

Recipe DatabaseDriver::getRecipe(QString id)
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

        QJsonArray json_array = jsonResponse.array();
        QJsonObject json_recipe_obj = QJsonValue(json_array).toObject();
        // QJsonObject json_account_obj = json_obj.value("place").toObject();
        qDebug() << json_recipe_obj["RecipeItemId"].toInt();
        qDebug() << json_recipe_obj["Amount"].toDouble();

        recipe_local.setRecipeItemId(json_recipe_obj["RecipeItemId"].toInt());
        recipe_local.setAmount(json_recipe_obj["Amount"].toDouble());

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

void DatabaseDriver::postRecipe(Recipe *recipe)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    QString endpoint = "Recipe/";
    QNetworkRequest request(_url + endpoint);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject recipe_local;
    recipe_local["RecipeItemId"] = recipe->getRecipeItemId();
    recipe_local["Amount"] = recipe->getAmount();

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

void DatabaseDriver::putRecipe(Recipe *recipe)
{

    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    QString endpoint = "Recipe/";
    QNetworkRequest request(_url + endpoint + QString::number(recipe->getRecipeItemId()));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject recipe_local;
    recipe_local["RecipeItemId"] = recipe->getRecipeItemId();
    recipe_local["Amount"] = recipe->getAmount();

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

void DatabaseDriver::deleteRecipe(QString index)
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

QJsonArray DatabaseDriver::getDrinkList()
{
    QEventLoop eventLoop;
    QJsonArray json_array;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

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

DrinkItem DatabaseDriver::getDrink(QString id)
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

        QJsonArray json_array = jsonResponse.array();

        QJsonObject json_drink_obj = QJsonValue(json_array).toObject();
        // QJsonObject json_account_obj = json_obj.value("place").toObject();
        qDebug() << json_drink_obj["Titel"].toString();
        qDebug() << json_drink_obj["DrinkId"].toInt();
        qDebug() << json_drink_obj["Description"].toString();
        qDebug() << json_drink_obj["Price"].toDouble();

        drink_local.setTitel(json_drink_obj["RecipeItemId"].toString());
        drink_local.setDrinkId(json_drink_obj["Amount"].toInt());
        drink_local.setDescription(json_drink_obj["Amount"].toString());
        drink_local.setPrice(json_drink_obj["Amount"].toDouble());

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

void DatabaseDriver::postDrink(DrinkItem *drink)
{
    // Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    QString endpoint = "Drink/";
    QNetworkRequest request(_url + endpoint);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject drink_local;
    drink_local["Titel"] = drink->getTitel();
    drink_local["DrinkId"] = drink->getDrinkId();
    drink_local["Description"] = drink->getDescription();
    drink_local["Price"] = drink->getPrice();

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

void DatabaseDriver::putDrink(DrinkItem *drink)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    QString URL = _url + "Drink/" + QString::number(drink->getDrinkId());
    //  the HTTP request
    const QUrl url(URL);
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject drink_local;
    drink_local["Titel"] = drink->getTitel();
    drink_local["DrinkId"] = drink->getDrinkId();
    drink_local["Description"] = drink->getDescription();
    drink_local["Price"] = drink->getPrice();

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

void DatabaseDriver::deleteDrink(QString index)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    QString const URL = _url + "/Drink" + index;
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

QJsonArray DatabaseDriver::getIngredientList()
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

IngredientItem DatabaseDriver::getIngredient(QString id)
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

        QJsonArray json_array = jsonResponse.array();

        foreach (const QJsonValue &value, json_array)
        {
            QJsonObject json_ingredient_local_obj = value.toObject();
            ingredient_local.setIngredientItemId(json_ingredient_local_obj["IngredientItemId"].toInt());
            ingredient_local.setTitel(json_ingredient_local_obj["Titel"].toString());
        }

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

void DatabaseDriver::postIngredient(IngredientItem *Ingredient)
{
    // "quit()" the event-loop, when the network request "finished()"
    // Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    const QString endpoint = "Ingredient/";
    QNetworkRequest request(_url + endpoint );

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

void DatabaseDriver::putIngredient(IngredientItem *ingredient)
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

void DatabaseDriver::deleteIngredient(QString index)
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

QJsonArray DatabaseDriver::getContainerList()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QJsonArray json_array;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    const QString endpoint = "Container/";
    QNetworkRequest request(_url + endpoint );
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

ContainerItem DatabaseDriver::getContainer(QString id)
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

        QJsonArray json_array = jsonResponse.array();

        QJsonObject json_container_local_obj = QJsonValue(json_array).toObject();
        // QJsonObject json_account_obj = json_obj.value("place").toObject();
        qDebug() << json_container_local_obj["ContainerId"].toString();
        qDebug() << json_container_local_obj["Place"].toInt();

        container_local.setContainerId(json_container_local_obj["ContainerId"].toInt());
        container_local.setPlace(json_container_local_obj["Place"].toInt());

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

void DatabaseDriver::postContainer(ContainerItem *container)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    const QString endpoint = "Container/";
    QNetworkRequest request(_url + endpoint );

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject container_local;
    container_local["ContainerId"] = container->getContainerId();
    container_local["Place"] = container->getPlace();

    QJsonDocument doc(container_local);
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

void DatabaseDriver::putContainer(ContainerItem *container)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    const QString endpoint = "Container/";
    QNetworkRequest request(_url + endpoint + QString::number(container->getContainerId()));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject container_local;
    container_local["ContainerId"] = container->getContainerId();
    container_local["Place"] = container->getPlace();

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

void DatabaseDriver::deleteContainer(QString index)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    const QString endpoint = "Container/";
    QNetworkRequest request(_url + endpoint + index );

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
