/********************************************************************************
** Form generated from reading UI file 'scorescreen.ui'
**
** Created: Fri Mar 1 02:57:50 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORESCREEN_H
#define UI_SCORESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ScoreWindow
{
public:
    QPushButton *btnDone;

    void setupUi(QDialog *ScoreWindow)
    {
        if (ScoreWindow->objectName().isEmpty())
            ScoreWindow->setObjectName(QString::fromUtf8("ScoreWindow"));
        ScoreWindow->resize(228, 352);
        btnDone = new QPushButton(ScoreWindow);
        btnDone->setObjectName(QString::fromUtf8("btnDone"));
        btnDone->setGeometry(QRect(61, 310, 105, 35));
        btnDone->setStyleSheet(QString::fromUtf8("background:url(:/images/button.png) no-repeat right top"));
        btnDone->setAutoDefault(false);
        btnDone->setFlat(true);

        retranslateUi(ScoreWindow);

        QMetaObject::connectSlotsByName(ScoreWindow);
    } // setupUi

    void retranslateUi(QDialog *ScoreWindow)
    {
        ScoreWindow->setWindowTitle(QApplication::translate("ScoreWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        btnDone->setText(QApplication::translate("ScoreWindow", "Done", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScoreWindow: public Ui_ScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORESCREEN_H
