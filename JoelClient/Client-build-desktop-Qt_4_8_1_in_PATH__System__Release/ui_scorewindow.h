/********************************************************************************
** Form generated from reading UI file 'scorewindow.ui'
**
** Created: Mon Mar 4 21:13:11 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREWINDOW_H
#define UI_SCOREWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ScoreWindow
{
public:

    void setupUi(QDialog *ScoreWindow)
    {
        if (ScoreWindow->objectName().isEmpty())
            ScoreWindow->setObjectName(QString::fromUtf8("ScoreWindow"));
        ScoreWindow->resize(250, 400);

        retranslateUi(ScoreWindow);

        QMetaObject::connectSlotsByName(ScoreWindow);
    } // setupUi

    void retranslateUi(QDialog *ScoreWindow)
    {
        ScoreWindow->setWindowTitle(QApplication::translate("ScoreWindow", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScoreWindow: public Ui_ScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWINDOW_H
