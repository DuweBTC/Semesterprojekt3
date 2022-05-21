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

Account DatabaseDriver::getAccount()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    Account account_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://127.0.0.1:8080/")));
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
            QJsonObject json_account_obj = value.toObject();
            // QJsonObject json_account_obj = json_obj.value("place").toObject();
            qDebug() << json_account_obj["AccountId"].toString();
            qDebug() << json_account_obj["Name"].toString();
            qDebug() << json_account_obj["Balance"].toDouble();
            // Account account_local(json_accont_obj["AccountId"].toString(),json_account_obj["AccountId"].toString(), json_account_obj["Balance"].toDouble() );
            account_local.setAccountId(json_account_obj["AccountId"].toString());
            account_local.setName(json_account_obj["Name"].toString());
            account_local.setBalance(json_account_obj["Balance"].toDouble());
        }

        delete reply;
    }
    else
    {
        // failure
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }

    return account_local;
}

void DatabaseDriver::postAccount(Account *account)
{
    // "quit()" the event-loop, when the network request "finished()"
    // Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/"));
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject account_local;
    account_local["Name"] = account->getName();
    account_local["Balance"] = account->getBalance();
    account_local["AccountId"] = account->getAccountId();

    QJsonDocument doc(account_local);
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
    int id = 5;
    QString URL = "http://127.0.0.1:8080/";
    // URL +=  + id.toString();
    //  the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/2"));
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

    QString const URL = "http://127.0.0.1:8080/" + index;

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

Recipe DatabaseDriver::getRecipe()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    Recipe recipe_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://127.0.0.1:8080/")));
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
            QJsonObject json_recipe_obj = value.toObject();
            // QJsonObject json_account_obj = json_obj.value("place").toObject();
            qDebug() << json_recipe_obj["RecipeItemId"].toInt();
            qDebug() << json_recipe_obj["Amount"].toDouble();
            // Account account_local(json_accont_obj["AccountId"].toString(),json_account_obj["AccountId"].toString(), json_account_obj["Balance"].toDouble() );
            recipe_local.setRecipeItemId(json_recipe_obj["RecipeItemId"].toInt());
            recipe_local.setAmount(json_recipe_obj["Amount"].toDouble());
        }

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
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/"));
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
    int id = 5;
    QString URL = "http://127.0.0.1:8080/";
    // URL +=  + id.toString();
    //  the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/2"));
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

    QString const URL = "http://127.0.0.1:8080/" + index;

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

DrinkItem DatabaseDriver::getDrink()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    DrinkItem drink_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://127.0.0.1:8080/")));
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
            QJsonObject json_drink_obj = value.toObject();
            // QJsonObject json_account_obj = json_obj.value("place").toObject();
            qDebug() << json_drink_obj["Titel"].toString();
            qDebug() << json_drink_obj["DrinkId"].toInt();
            qDebug() << json_drink_obj["Description"].toString();
            qDebug() << json_drink_obj["Price"].toDouble();
            // Account account_local(json_accont_obj["AccountId"].toString(),json_account_obj["AccountId"].toString(), json_account_obj["Balance"].toDouble() );
            drink_local.setTitel(json_drink_obj["RecipeItemId"].toString());
            drink_local.setDrinkId(json_drink_obj["Amount"].toInt());
            drink_local.setDescription(json_drink_obj["Amount"].toString());
            drink_local.setPrice(json_drink_obj["Amount"].toDouble());
        }

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
    // "quit()" the event-loop, when the network request "finished()"
    // Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/"));
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject drink_local;
    drink_local["Titel"] = drink->getTitel();
    drink_local["DrinkId"] = drink->getDrinkId();
    drink_local["Description"] = drink->getDescription();
    drink_local["Price"] = drink->getPrice();

    QJsonDocument doc(drink_local);
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

void DatabaseDriver::putDrink(DrinkItem *drink)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    int id = 5;
    QString URL = "http://127.0.0.1:8080/";
    // URL +=  + id.toString();
    //  the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/2"));
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject drink_local;
    drink_local["Titel"] = drink->getTitel();
    drink_local["DrinkId"] = drink->getDrinkId();
    drink_local["Description"] = drink->getDescription();
    drink_local["Price"] = drink->getPrice();

    QJsonDocument doc(drink_local);
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

void DatabaseDriver::deleteDrink(QString index)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QString const URL = "http://127.0.0.1:8080/" + index;

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

IngredientItem DatabaseDriver::getIngredient()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    IngredientItem ingredient_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://127.0.0.1:8080/")));
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
            // QJsonObject json_account_obj = json_obj.value("place").toObject();
            qDebug() << json_ingredient_local_obj["IngredientItemId"].toInt();
            qDebug() << json_ingredient_local_obj["Titel"].toString();

            // Account account_local(json_accont_obj["AccountId"].toString(),json_account_obj["AccountId"].toString(), json_account_obj["Balance"].toDouble() );
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
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/"));
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

void DatabaseDriver::putIngredient(IngredientItem *Ingredient)
{
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    int id = 5;
    QString URL = "http://127.0.0.1:8080/";
    // URL +=  + id.toString();
    //  the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/2"));
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject ingredient_local;
    ingredient_local["IngredientItemId"] = Ingredient->getIngredientItemId();
    ingredient_local["Titel"] = Ingredient->getTitel();

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

    QString const URL = "http://127.0.0.1:8080/" + index;

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

ContainerItem DatabaseDriver::getContainer()
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    ContainerItem container_local;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(QUrl(QString("http://127.0.0.1:8080/")));
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
            QJsonObject json_container_local_obj = value.toObject();
            // QJsonObject json_account_obj = json_obj.value("place").toObject();
            qDebug() << json_container_local_obj["ContainerId"].toString();
            qDebug() << json_container_local_obj["Place"].toInt();

            // Account account_local(json_accont_obj["AccountId"].toString(),json_account_obj["AccountId"].toString(), json_account_obj["Balance"].toDouble() );
            container_local.setContainerId(json_container_local_obj["ContainerId"].toString());
            container_local.setPlace(json_container_local_obj["Place"].toInt());
        }

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
    // "quit()" the event-loop, when the network request "finished()"
    // Account account_local;
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/"));
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
    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager *mgr = new QNetworkAccessManager;
    // QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    int id = 5;
    QString URL = "http://127.0.0.1:8080/";
    // URL +=  + id.toString();
    //  the HTTP request
    const QUrl url(QStringLiteral("http://127.0.0.1:8080/2"));
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

    QString const URL = "http://127.0.0.1:8080/" + index;

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
