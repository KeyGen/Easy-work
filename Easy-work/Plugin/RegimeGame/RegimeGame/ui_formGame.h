/********************************************************************************
** Form generated from reading UI file 'formGame.ui'
**
** Created: Wed Dec 12 15:41:55 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGAME_H
#define UI_FORMGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Regime
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetQml;
    QGridLayout *gridLayout_2;

    void setupUi(QWidget *Regime)
    {
        if (Regime->objectName().isEmpty())
            Regime->setObjectName(QString::fromUtf8("Regime"));
        Regime->resize(720, 223);
        gridLayout = new QGridLayout(Regime);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widgetQml = new QWidget(Regime);
        widgetQml->setObjectName(QString::fromUtf8("widgetQml"));
        gridLayout_2 = new QGridLayout(widgetQml);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout->addWidget(widgetQml, 1, 0, 1, 1);


        retranslateUi(Regime);

        QMetaObject::connectSlotsByName(Regime);
    } // setupUi

    void retranslateUi(QWidget *Regime)
    {
        Regime->setWindowTitle(QApplication::translate("Regime", "Easy work Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Regime: public Ui_Regime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAME_H
