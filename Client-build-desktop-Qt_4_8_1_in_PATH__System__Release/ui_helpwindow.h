/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created: Fri Mar 8 23:43:51 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QString::fromUtf8("HelpWindow"));
        HelpWindow->resize(775, 375);
        HelpWindow->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(HelpWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 0, 681, 141));
        label_3->setStyleSheet(QString::fromUtf8("background:url(:/images/controls.png) no-repeat top left"));
        label = new QLabel(HelpWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(680, 148, 21, 90));
        label->setStyleSheet(QString::fromUtf8("background:url(:/images/bar.png) no-repeat top left;"));
        label_2 = new QLabel(HelpWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(58, 88, 174, 108));
        label_2->setStyleSheet(QString::fromUtf8("background:url(:/images/WASD2.png) no-repeat top left;"));
        label_4 = new QLabel(HelpWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(58, 218, 174, 111));
        label_4->setStyleSheet(QString::fromUtf8("background:url(:/images/ARROWS.png) no-repeat top left;"));
        label_5 = new QLabel(HelpWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(8, 184, 461, 46));
        label_5->setStyleSheet(QString::fromUtf8("background:url(:/images/directions 1.png) no-repeat top left;"));
        label_6 = new QLabel(HelpWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(-16, 204, 461, 46));
        label_6->setStyleSheet(QString::fromUtf8("background:url(:/images/directions 2.png) no-repeat top left;"));
        label_2->raise();
        label_3->raise();
        label->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();

        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QWidget *HelpWindow)
    {
        HelpWindow->setWindowTitle(QApplication::translate("HelpWindow", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
