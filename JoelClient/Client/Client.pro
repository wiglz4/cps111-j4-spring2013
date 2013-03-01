#-------------------------------------------------
#
# Project created by QtCreator 2013-03-01T01:25:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    gamescreen.cpp \
    entitylabel.cpp

HEADERS  += widget.h \
    gamescreen.h \
    entitylabel.h

FORMS    += widget.ui \
    gamescreen.ui

RESOURCES += \
    resources.qrc
