#-------------------------------------------------
#
# Project created by QtCreator 2013-02-28T17:25:04
#
#-------------------------------------------------

QT       += core gui
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        serverwindow.cpp \
    world.cpp \
    towershot.cpp \
    tower.cpp \
    Stats.cpp \
    plch.cpp \
    minion.cpp \
    game.cpp \
    counter.cpp \
    core.cpp \
    user.cpp \
    unit.cpp

HEADERS  += serverwindow.h \
    world.h \
    unit.h \
    towershot.h \
    tower.h \
    Stats.h \
    plch.h \
    minion.h \
    game.h \
    Entity.h \
    counter.h \
    core.h \
    user.h

FORMS    += serverwindow.ui
