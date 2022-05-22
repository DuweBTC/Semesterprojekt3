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

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://localhost:5123/Account/")));
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        json_array = jsonResponse.array();

        //        foreach (const QJsonValue &value, json_array)
        //        {
        //            QJsonObject json_account_obj = value.toObject();
        //            // QJsonObject json_account_obj = json_obj.value("place").toObject();
        //            qDebug() << json_account_obj["accountItemId"].toInt();
        //            qDebug() << json_account_obj["name"].toString();
        //            qDebug() << json_account_obj["balance"].toDouble();

        //            // Set the variables on local Account
        //            account_local.setAccountId(json_account_obj["accountItemId"].toInt());
        //            account_local.setName(json_account_obj["name"].toString());
        //            account_local.setBalance(json_account_obj["balance"].toDouble());
        //        }

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
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError)
    {

        QString strReply = (QString)reply->readAll();

        // parse json
        qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonArray json_array = jsonResponse.array();
        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_account_obj = value.toObject();

            // QJsonObject json_account_obj = json_obj.value("place").toObject();
            qDebug() << json_account_obj["accountItemId"].toString();
            qDebug() << json_account_obj["name"].toString();
            qDebug() << json_account_obj["balance"].toDouble();
            // Account account_local(json_accont_obj["AccountId"].toString(),json_account_obj["AccountId"].toString(), json_account_obj["Balance"].toDouble() );
            account->setAccountId(json_account_obj["accountItemId"].toInt());
            account->setName(json_account_obj["name"].toString());
            account->setBalance(json_account_obj["balance"].toDouble());
        }
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

void DatabaseDriver::postAccount(Account *account)
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager;

    // the HTTP request
    const QUrl url(QStringLiteral("http://localhost:5123/Account"));
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject jsonFormatAccount;
    jsonFormatAccount["AccountId"] = account->getAccountId();
    jsonFormatAccount["Name"] = account->getName();
    jsonFormatAccount["Balance"] = account->getBalance();

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
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QString URL = "http://localhost:5123/Account/" + QString::number(account->getAccountId());
    //  the HTTP request
    const QUrl url(URL);
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject account_local;
    account_local["Name"] = account->getName();
    account_local["Balance"] = account->getBalance();
    account_local["AccountId"] = account->getAccountId();

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

    QString const URL = "http://localhost:5123/Account/" + index;

    // the HTTP request
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

QJsonArray DatabaseDriver::getRecipeList()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QJsonArray json_array;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://localhost:5123/Recipe/")));
    QNetworkReply *reply = mgr.get(req);
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
    // "quit()" the event-loop, when the network request "finished()"
    // Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    const QUrl url(QStringLiteral("http://localhost:5123/Recipe/"));
    QNetworkRequest request(url);

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
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QString URL = "http://localhost:5123/Recipe/" + QString::number(recipe->getRecipeItemId());
    //  the HTTP request
    const QUrl url(URL);
    QNetworkRequest request(url);

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
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QString const URL = "http://localhost:5123/Recipe/" + index;

    // the HTTP request
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

QJsonArray DatabaseDriver::getDrinkList()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QJsonArray json_array;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://localhost:5123/Drink/")));
    QNetworkReply *reply = mgr.get(req);
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

    // the HTTP request
    const QUrl url(QStringLiteral("http://localhost:5123/Drink/"));
    QNetworkRequest request(url);

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
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QString const URL = _url + "/Drink" + index;

    // the HTTP request
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

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://localhost:5123/Ingredient/")));
    QNetworkReply *reply = mgr.get(req);
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

    // the HTTP request
    const QString endpoint = "Ingredient/";
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

    // the HTTP request
    const QUrl url(QStringLiteral("http://localhost:5123/Ingredient/"));
    QNetworkRequest request(url);

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
    QString URL = "http://localhost:5123/Ingredient/" + QString::number(ingredient->getIngredientItemId());
    //  the HTTP request
    const QUrl url(URL);
    QNetworkRequest request(url);

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

    QString const URL = "http://localhost:5123/Ingredient/" + index;

    // the HTTP request
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

QJsonArray DatabaseDriver::getContainerList()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QJsonArray json_array;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://localhost:5123/Container/")));
    QNetworkReply *reply = mgr.get(req);
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

    // the HTTP request
    const QUrl url(QStringLiteral("http://localhost:5123/Container/"));
    QNetworkRequest request(url);

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

    QString URL = _url + "/Container/" + QString::number(container->getContainerId());
    //  the HTTP request
    const QUrl url(URL);
    QNetworkRequest request(url);

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

    QString const URL = _url + "Container/" + index;

    // the HTTP request
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
