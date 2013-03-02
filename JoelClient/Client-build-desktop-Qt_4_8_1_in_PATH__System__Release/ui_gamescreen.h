/********************************************************************************
** Form generated from reading UI file 'gamescreen.ui'
**
** Created: Sat Mar 2 17:41:34 2013
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
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameScreen
{
public:

    void setupUi(QWidget *gameScreen)
    {
        if (gameScreen->objectName().isEmpty())
            gameScreen->setObjectName(QString::fromUtf8("gameScreen"));
        gameScreen->resize(800, 600);

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
