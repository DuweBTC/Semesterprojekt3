#-------------------------------------------------
#
# Project created by QtCreator 2022-05-26T16:22:43
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPiClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    Containeritem.cpp \
    Drinkitem.cpp \
    HTTP.cpp \
    Ingredientitem.cpp \
    Recipe.cpp \
    account.cpp \
    adddrinkmenu.cpp \
    balancemenu.cpp \
    drinksmenu.cpp \
    favorit.cpp \
    kontoinformation.cpp \
    main.cpp \
    mainwindow.cpp \
    newuser.cpp \
    startup.cpp

HEADERS += \
    Containeritem.h \
    Drinkitem.h \
    HTTP.h \
    Ingredientitem.h \
    Recipe.h \
    account.h \
    adddrinkmenu.h \
    balancemenu.h \
    drinksmenu.h \
    favorit.h \
    kontoinformation.h \
    mainwindow.h \
    newuser.h \
    startup.h

FORMS += \
    adddrinkmenu.ui \
    balancemenu.ui \
    drinksmenu.ui \
    favorit.ui \
    kontoinformation.ui \
    mainwindow.ui \
    newuser.ui \
    startup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/$${TARGET}
!isEmpty(target.path): INSTALLS += target
