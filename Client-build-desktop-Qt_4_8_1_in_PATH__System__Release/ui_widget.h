/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Fri Mar 8 19:39:48 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btnLocal;
    QPushButton *btnNetwork;
    QPushButton *btnScores;
    QLabel *lblTitle;
    QPushButton *btnHelp;
    QPushButton *btnExit;
    QPushButton *btnLoad;
    QLabel *lblTitle_2;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->resize(775, 375);
        Widget->setMaximumSize(QSize(775, 375));
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QString::fromUtf8(""));
        btnLocal = new QPushButton(Widget);
        btnLocal->setObjectName(QString::fromUtf8("btnLocal"));
        btnLocal->setGeometry(QRect(568, 141, 121, 31));
        QPalette palette;
        btnLocal->setPalette(palette);
        btnLocal->setMouseTracking(true);
        btnLocal->setFocusPolicy(Qt::NoFocus);
        btnLocal->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"    background:url(:/images/buttonsp.png) no-repeat right top;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background:url(:/images/buttonsp2.png) no-repeat right top;\n"
"} \n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background:url(:/images/buttonsp.png) no-repeat right top;\n"
"  border: 0px solid grey;\n"
"}"));
        btnLocal->setAutoRepeatDelay(300);
        btnLocal->setAutoDefault(false);
        btnLocal->setDefault(false);
        btnLocal->setFlat(true);
        btnNetwork = new QPushButton(Widget);
        btnNetwork->setObjectName(QString::fromUtf8("btnNetwork"));
        btnNetwork->setEnabled(false);
        btnNetwork->setGeometry(QRect(570, 171, 121, 31));
        btnNetwork->setFocusPolicy(Qt::NoFocus);
        btnNetwork->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"    background:url(:/images/buttonmp.png) no-repeat right top;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background:url(:/images/buttonmp2.png) no-repeat right top;\n"
"} \n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background:url(:/images/buttonmp.png) no-repeat right top;\n"
"  border: 0px solid grey;\n"
"}"));
        btnNetwork->setFlat(true);
        btnScores = new QPushButton(Widget);
        btnScores->setObjectName(QString::fromUtf8("btnScores"));
        btnScores->setGeometry(QRect(580, 229, 111, 35));
        btnScores->setFocusPolicy(Qt::NoFocus);
        btnScores->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"    background:url(:/images/buttonhs.png) no-repeat right top;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background:url(:/images/buttonhs2.png) no-repeat right top;\n"
"} \n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background:url(:/images/buttonhs.png) no-repeat right top;\n"
"  border: 0px solid grey;\n"
"}"));
        btnScores->setFlat(true);
        lblTitle = new QLabel(Widget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setGeometry(QRect(30, 2, 651, 161));
        lblTitle->setStyleSheet(QString::fromUtf8("background:url(:/images/game title.png) no-repeat top left;"));
        btnHelp = new QPushButton(Widget);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        btnHelp->setGeometry(QRect(604, 257, 101, 25));
        btnHelp->setFocusPolicy(Qt::NoFocus);
        btnHelp->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"    background:url(:/images/buttonct.png) no-repeat right top;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background:url(:/images/buttonct2.png) no-repeat right top;\n"
"} \n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background:url(:/images/buttonct.png) no-repeat right top;\n"
"  border: 0px solid grey;\n"
"}"));
        btnHelp->setFlat(true);
        btnExit = new QPushButton(Widget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(620, 283, 105, 31));
        btnExit->setFocusPolicy(Qt::NoFocus);
        btnExit->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"    background:url(:/images/buttonex.png) no-repeat right top;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background:url(:/images/buttonex2.png) no-repeat right top;\n"
"} \n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background:url(:/images/buttonex.png) no-repeat right top;\n"
"  border: 0px solid grey;\n"
"}"));
        btnExit->setFlat(true);
        btnLoad = new QPushButton(Widget);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setEnabled(false);
        btnLoad->setGeometry(QRect(574, 201, 121, 31));
        btnLoad->setFocusPolicy(Qt::NoFocus);
        btnLoad->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"    background:url(:/images/buttonlg.png) no-repeat right top;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background:url(:/images/buttonlg2.png) no-repeat right top;\n"
"} \n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background:url(:/images/buttonlg.png) no-repeat right top;\n"
"  border: 0px solid grey;\n"
"}"));
        btnLoad->setFlat(true);
        lblTitle_2 = new QLabel(Widget);
        lblTitle_2->setObjectName(QString::fromUtf8("lblTitle_2"));
        lblTitle_2->setGeometry(QRect(687, 147, 21, 165));
        lblTitle_2->setStyleSheet(QString::fromUtf8("background:url(:/images/bar.png) no-repeat top left;"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 775, 376));
        label->setStyleSheet(QString::fromUtf8("QWidget \n"
"{\n"
" background:url(:/images/backgrounde.png) no-repeat right top;\n"
"}\n"
""));
        label->raise();
        lblTitle->raise();
        btnLocal->raise();
        btnNetwork->raise();
        btnScores->raise();
        btnHelp->raise();
        btnExit->raise();
        btnLoad->raise();
        lblTitle_2->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Gate = Down", 0, QApplication::UnicodeUTF8));
        btnLocal->setText(QString());
        btnNetwork->setText(QString());
        btnScores->setText(QString());
        lblTitle->setText(QString());
        btnHelp->setText(QString());
        btnExit->setText(QString());
        btnLoad->setText(QString());
        lblTitle_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
