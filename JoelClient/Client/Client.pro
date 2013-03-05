#-------------------------------------------------
#
# Project created by QtCreator 2013-03-01T01:25:39
#
#-------------------------------------------------

QT       += core gui
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    gamescreen.cpp \
    entitylabel.cpp \
    scorewindow.cpp

HEADERS  += widget.h \
    gamescreen.h \
    entitylabel.h \
    scorewindow.h

FORMS    += widget.ui \
    gamescreen.ui \
    scorewindow.ui

RESOURCES += \
    resources.qrc
