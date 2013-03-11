/********************************************************************************
** Form generated from reading UI file 'scorewindow.ui'
**
** Created: Mon Mar 11 09:25:18 2013
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
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ScoreWindow
{
public:
    QLabel *lblTitle;
    QLabel *lblTitle_2;

    void setupUi(QDialog *ScoreWindow)
    {
        if (ScoreWindow->objectName().isEmpty())
            ScoreWindow->setObjectName(QString::fromUtf8("ScoreWindow"));
        ScoreWindow->resize(775, 375);
        ScoreWindow->setStyleSheet(QString::fromUtf8("QWidget \n"
"{\n"
"	background-image: url(:/images/backgrounde.png);\n"
"}\n"
"\n"
""));
        lblTitle = new QLabel(ScoreWindow);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setEnabled(true);
        lblTitle->setGeometry(QRect(50, 0, 661, 151));
        lblTitle->setStyleSheet(QString::fromUtf8("background:url(:/images/high scores.png) no-repeat top left"));
        lblTitle_2 = new QLabel(ScoreWindow);
        lblTitle_2->setObjectName(QString::fromUtf8("lblTitle_2"));
        lblTitle_2->setEnabled(true);
        lblTitle_2->setGeometry(QRect(680, 148, 21, 90));
        lblTitle_2->setStyleSheet(QString::fromUtf8("background:url(:/images/bar.png) no-repeat top left;"));

        retranslateUi(ScoreWindow);

        QMetaObject::connectSlotsByName(ScoreWindow);
    } // setupUi

    void retranslateUi(QDialog *ScoreWindow)
    {
        ScoreWindow->setWindowTitle(QApplication::translate("ScoreWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        lblTitle->setText(QString());
        lblTitle_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScoreWindow: public Ui_ScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWINDOW_H
