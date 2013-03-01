/********************************************************************************
** Form generated from reading UI file 'gamescreen.ui'
**
** Created: Fri Mar 1 02:57:50 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCREEN_H
#define UI_GAMESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameScreen
{
public:
    QWidget *wdgtPicture;
    QFrame *lineTop;
    QFrame *linebottom;
    QFrame *lineLeft;
    QFrame *lineRight;

    void setupUi(QWidget *gameScreen)
    {
        if (gameScreen->objectName().isEmpty())
            gameScreen->setObjectName(QString::fromUtf8("gameScreen"));
        gameScreen->resize(800, 600);
        wdgtPicture = new QWidget(gameScreen);
        wdgtPicture->setObjectName(QString::fromUtf8("wdgtPicture"));
        wdgtPicture->setGeometry(QRect(20, 20, 760, 560));
        wdgtPicture->setAutoFillBackground(false);
        wdgtPicture->setStyleSheet(QString::fromUtf8("background-image: url(:/images/mapsm.png)"));
        lineTop = new QFrame(gameScreen);
        lineTop->setObjectName(QString::fromUtf8("lineTop"));
        lineTop->setGeometry(QRect(0, 0, 800, 20));
        lineTop->setFrameShadow(QFrame::Plain);
        lineTop->setLineWidth(20);
        lineTop->setFrameShape(QFrame::HLine);
        linebottom = new QFrame(gameScreen);
        linebottom->setObjectName(QString::fromUtf8("linebottom"));
        linebottom->setGeometry(QRect(0, 580, 800, 20));
        linebottom->setFrameShadow(QFrame::Plain);
        linebottom->setLineWidth(20);
        linebottom->setFrameShape(QFrame::HLine);
        lineLeft = new QFrame(gameScreen);
        lineLeft->setObjectName(QString::fromUtf8("lineLeft"));
        lineLeft->setGeometry(QRect(0, 0, 20, 600));
        lineLeft->setFrameShadow(QFrame::Plain);
        lineLeft->setLineWidth(20);
        lineLeft->setFrameShape(QFrame::VLine);
        lineRight = new QFrame(gameScreen);
        lineRight->setObjectName(QString::fromUtf8("lineRight"));
        lineRight->setGeometry(QRect(780, 10, 20, 600));
        lineRight->setFrameShadow(QFrame::Plain);
        lineRight->setLineWidth(20);
        lineRight->setFrameShape(QFrame::VLine);

        retranslateUi(gameScreen);

        QMetaObject::connectSlotsByName(gameScreen);
    } // setupUi

    void retranslateUi(QWidget *gameScreen)
    {
        gameScreen->setWindowTitle(QApplication::translate("gameScreen", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gameScreen: public Ui_gameScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCREEN_H
