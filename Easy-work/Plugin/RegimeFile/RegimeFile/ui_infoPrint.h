/********************************************************************************
** Form generated from reading UI file 'infoPrint.ui'
**
** Created: Mon Nov 5 16:12:34 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOPRINT_H
#define UI_INFOPRINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_InfoPrint
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelError;
    QFrame *line;
    QLabel *inputError;
    QPushButton *Ok;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelCorrectly;
    QFrame *line_2;
    QLabel *inputCorrectly;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelTime;
    QFrame *line_3;
    QLabel *inputTime;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelSign;
    QFrame *line_4;
    QLabel *inputSign;

    void setupUi(QDialog *InfoPrint)
    {
        if (InfoPrint->objectName().isEmpty())
            InfoPrint->setObjectName(QString::fromUtf8("InfoPrint"));
        InfoPrint->resize(519, 178);
        gridLayout = new QGridLayout(InfoPrint);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelError = new QLabel(InfoPrint);
        labelError->setObjectName(QString::fromUtf8("labelError"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        labelError->setFont(font);

        horizontalLayout->addWidget(labelError);

        line = new QFrame(InfoPrint);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        inputError = new QLabel(InfoPrint);
        inputError->setObjectName(QString::fromUtf8("inputError"));
        inputError->setFont(font);

        horizontalLayout->addWidget(inputError);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        Ok = new QPushButton(InfoPrint);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(Ok, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(156, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(156, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelCorrectly = new QLabel(InfoPrint);
        labelCorrectly->setObjectName(QString::fromUtf8("labelCorrectly"));
        labelCorrectly->setFont(font);

        horizontalLayout_2->addWidget(labelCorrectly);

        line_2 = new QFrame(InfoPrint);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        inputCorrectly = new QLabel(InfoPrint);
        inputCorrectly->setObjectName(QString::fromUtf8("inputCorrectly"));
        inputCorrectly->setFont(font);

        horizontalLayout_2->addWidget(inputCorrectly);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelTime = new QLabel(InfoPrint);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setFont(font);

        horizontalLayout_3->addWidget(labelTime);

        line_3 = new QFrame(InfoPrint);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        inputTime = new QLabel(InfoPrint);
        inputTime->setObjectName(QString::fromUtf8("inputTime"));
        inputTime->setFont(font);

        horizontalLayout_3->addWidget(inputTime);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelSign = new QLabel(InfoPrint);
        labelSign->setObjectName(QString::fromUtf8("labelSign"));
        labelSign->setFont(font);

        horizontalLayout_5->addWidget(labelSign);

        line_4 = new QFrame(InfoPrint);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_4);

        inputSign = new QLabel(InfoPrint);
        inputSign->setObjectName(QString::fromUtf8("inputSign"));
        inputSign->setFont(font);

        horizontalLayout_5->addWidget(inputSign);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 3);


        retranslateUi(InfoPrint);
        QObject::connect(Ok, SIGNAL(clicked()), InfoPrint, SLOT(close()));

        QMetaObject::connectSlotsByName(InfoPrint);
    } // setupUi

    void retranslateUi(QDialog *InfoPrint)
    {
        InfoPrint->setWindowTitle(QApplication::translate("InfoPrint", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\203\321\200\320\276\320\272\320\265", 0, QApplication::UnicodeUTF8));
        labelError->setText(QApplication::translate("InfoPrint", "\320\236\321\210\320\270\320\261\320\276\320\272:", 0, QApplication::UnicodeUTF8));
        inputError->setText(QString());
        Ok->setText(QApplication::translate("InfoPrint", "Ok", 0, QApplication::UnicodeUTF8));
        labelCorrectly->setText(QApplication::translate("InfoPrint", "\320\237\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276 \320\275\320\260\320\261\321\200\320\260\320\275\320\276:", 0, QApplication::UnicodeUTF8));
        inputCorrectly->setText(QString());
        labelTime->setText(QApplication::translate("InfoPrint", "\320\227\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\275\320\276\320\265 \320\262\321\200\320\265\320\274\321\217 (\321\201\320\265\320\272):", 0, QApplication::UnicodeUTF8));
        inputTime->setText(QString());
        labelSign->setText(QApplication::translate("InfoPrint", "\320\227\320\275\320\260\320\272\320\276\320\262 \320\267\320\260 \320\274\320\270\320\275\321\203\321\202\321\203 :", 0, QApplication::UnicodeUTF8));
        inputSign->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InfoPrint: public Ui_InfoPrint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOPRINT_H
