/********************************************************************************
** Form generated from reading UI file 'corewidget.ui'
**
** Created: Thu Dec 6 13:35:53 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COREWIDGET_H
#define UI_COREWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoreForm
{
public:
    QGridLayout *centralGridLayout;
    QHBoxLayout *layoutRegime;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widgetQml;
    QGridLayout *gridLayout;

    void setupUi(QWidget *CoreForm)
    {
        if (CoreForm->objectName().isEmpty())
            CoreForm->setObjectName(QString::fromUtf8("CoreForm"));
        CoreForm->resize(705, 243);
        centralGridLayout = new QGridLayout(CoreForm);
        centralGridLayout->setObjectName(QString::fromUtf8("centralGridLayout"));
        layoutRegime = new QHBoxLayout();
        layoutRegime->setObjectName(QString::fromUtf8("layoutRegime"));

        centralGridLayout->addLayout(layoutRegime, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralGridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralGridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        widgetQml = new QWidget(CoreForm);
        widgetQml->setObjectName(QString::fromUtf8("widgetQml"));
        widgetQml->setEnabled(true);
        widgetQml->setMouseTracking(false);
        widgetQml->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5, stop:0 black, stop:0.5 black, stop:1 black);\n"
"border-radius: 0px;\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;"));
        gridLayout = new QGridLayout(widgetQml);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        centralGridLayout->addWidget(widgetQml, 0, 0, 1, 3);


        retranslateUi(CoreForm);

        QMetaObject::connectSlotsByName(CoreForm);
    } // setupUi

    void retranslateUi(QWidget *CoreForm)
    {
        CoreForm->setWindowTitle(QApplication::translate("CoreForm", "Easy work", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CoreForm: public Ui_CoreForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COREWIDGET_H
