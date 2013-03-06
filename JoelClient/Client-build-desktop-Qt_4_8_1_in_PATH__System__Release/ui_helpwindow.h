/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created: Tue Mar 5 19:59:38 2013
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QFrame *line;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_3;

    void setupUi(QWidget *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QString::fromUtf8("HelpWindow"));
        HelpWindow->resize(350, 300);
        HelpWindow->setStyleSheet(QString::fromUtf8("background-color:#43553a;"));
        line = new QFrame(HelpWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 40, 331, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(HelpWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 80, 141, 71));
        label->setAutoFillBackground(false);
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/WASD.png")));
        label->setScaledContents(true);
        plainTextEdit = new QPlainTextEdit(HelpWindow);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(160, 80, 171, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setLineWidth(0);
        plainTextEdit->setBackgroundVisible(false);
        label_2 = new QLabel(HelpWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 180, 141, 71));
        label_2->setAutoFillBackground(false);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/ARROWKEYS.png")));
        label_2->setScaledContents(true);
        plainTextEdit_2 = new QPlainTextEdit(HelpWindow);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(160, 180, 191, 79));
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        plainTextEdit_2->setFrameShape(QFrame::NoFrame);
        plainTextEdit_2->setLineWidth(0);
        plainTextEdit_2->setBackgroundVisible(false);
        label_3 = new QLabel(HelpWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 10, 91, 31));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/hep.png")));
        plainTextEdit_2->raise();
        line->raise();
        label->raise();
        plainTextEdit->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QWidget *HelpWindow)
    {
        HelpWindow->setWindowTitle(QApplication::translate("HelpWindow", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        plainTextEdit->setPlainText(QApplication::translate("HelpWindow", "Use WASD to move your hero around the screen.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        plainTextEdit_2->setPlainText(QApplication::translate("HelpWindow", "Use the arrow keys to move the screen around.", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
