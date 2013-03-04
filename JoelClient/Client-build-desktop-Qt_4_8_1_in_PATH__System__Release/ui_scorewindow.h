/********************************************************************************
** Form generated from reading UI file 'scorewindow.ui'
**
** Created: Mon Mar 4 05:01:31 2013
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ScoreWindow
{
public:
    QLabel *lblTitle;
    QFrame *line;
    QFrame *line_2;

    void setupUi(QDialog *ScoreWindow)
    {
        if (ScoreWindow->objectName().isEmpty())
            ScoreWindow->setObjectName(QString::fromUtf8("ScoreWindow"));
        ScoreWindow->resize(250, 400);
        ScoreWindow->setStyleSheet(QString::fromUtf8("background-color:#43553a;"));
        lblTitle = new QLabel(ScoreWindow);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setGeometry(QRect(40, 0, 180, 40));
        lblTitle->setStyleSheet(QString::fromUtf8("background:url(:/images/highscores.png) no-repeat top left"));
        line = new QFrame(ScoreWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-90, 30, 431, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(ScoreWindow);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 330, 251, 20));
        line_2->setStyleSheet(QString::fromUtf8(""));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(ScoreWindow);

        QMetaObject::connectSlotsByName(ScoreWindow);
    } // setupUi

    void retranslateUi(QDialog *ScoreWindow)
    {
        ScoreWindow->setWindowTitle(QApplication::translate("ScoreWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        lblTitle->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScoreWindow: public Ui_ScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWINDOW_H
