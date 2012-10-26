/********************************************************************************
** Form generated from reading UI file 'regimefile.ui'
**
** Created: Fri Oct 26 14:41:43 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIMEFILE_H
#define UI_REGIMEFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegimeFile
{
public:
    QGridLayout *centralGridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *RegimeFile)
    {
        if (RegimeFile->objectName().isEmpty())
            RegimeFile->setObjectName(QString::fromUtf8("RegimeFile"));
        RegimeFile->resize(668, 218);
        centralGridLayout = new QGridLayout(RegimeFile);
        centralGridLayout->setContentsMargins(4, 4, 4, 4);
        centralGridLayout->setObjectName(QString::fromUtf8("centralGridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        label = new QLabel(RegimeFile);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setMargin(0);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(RegimeFile);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(label_2);


        centralGridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(RegimeFile);

        QMetaObject::connectSlotsByName(RegimeFile);
    } // setupUi

    void retranslateUi(QWidget *RegimeFile)
    {
        RegimeFile->setWindowTitle(QApplication::translate("RegimeFile", "\320\240\320\265\320\266\320\270\320\274 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RegimeFile", "\320\237\321\200\320\276\320\261\320\265\320\273 = \321\201\321\202\320\260\321\200\321\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RegimeFile", "Enter = \321\201\321\202\320\276\320\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegimeFile: public Ui_RegimeFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIMEFILE_H
