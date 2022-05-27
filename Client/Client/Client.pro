QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Containeritem.cpp \
    Drinkitem.cpp \
    Ingredientitem.cpp \
    Recipe.cpp \
    account.cpp \
    adddrinkmenu.cpp \
    balancemenu.cpp \
    databasedriver.cpp \
    drinksmenu.cpp \
    kontoinformation.cpp \
    main.cpp \
    mainwindow.cpp \
    newuser.cpp \
    startup.cpp

HEADERS += \
    Containeritem.h \
    Drinkitem.h \
    Ingredientitem.h \
    Recipe.h \
    account.h \
    adddrinkmenu.h \
    balancemenu.h \
    databasedriver.h \
    drinksmenu.h \
    kontoinformation.h \
    mainwindow.h \
    newuser.h \
    startup.h

FORMS += \
    adddrinkmenu.ui \
    balancemenu.ui \
    drinksmenu.ui \
    kontoinformation.ui \
    mainwindow.ui \
    newuser.ui \
    startup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
