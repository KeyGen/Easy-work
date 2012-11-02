/********************************************************************************
** Form generated from reading UI file 'corewidget.ui'
**
** Created: Sat Nov 3 00:06:03 2012
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoreForm
{
public:
    QGridLayout *centralGridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QWidget *CoreForm)
    {
        if (CoreForm->objectName().isEmpty())
            CoreForm->setObjectName(QString::fromUtf8("CoreForm"));
        CoreForm->resize(705, 243);
        centralGridLayout = new QGridLayout(CoreForm);
        centralGridLayout->setObjectName(QString::fromUtf8("centralGridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralGridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(CoreForm);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);

        centralGridLayout->addWidget(label, 0, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralGridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        pushButton = new QPushButton(CoreForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        centralGridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(CoreForm);

        QMetaObject::connectSlotsByName(CoreForm);
    } // setupUi

    void retranslateUi(QWidget *CoreForm)
    {
        CoreForm->setWindowTitle(QApplication::translate("CoreForm", "Easy work beta", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CoreForm", "<html><head/><body><p>\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203 Easy work<br/><span style=\" font-size:14pt; font-style:italic;\">(\320\221\320\265\321\202\320\260 \320\262\320\265\321\200\321\201\320\270\321\217)</span></p><p><span style=\" font-size:14pt;\">\320\222 \320\277\321\200\320\276\320\265\320\272\321\202\320\265 \320\265\321\211\320\265 \320\274\320\275\320\276\320\263\320\276 \321\200\320\265\320\266\320\270\320\274\320\276\320\262.<br/>\320\225\321\201\321\202\321\214 \320\262\320\276\320\277\321\200\320\276\321\201\321\213, \320\277\320\270\321\210\320\270\321\202\320\265 KeyGenQt@gmail.com </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CoreForm", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CoreForm: public Ui_CoreForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COREWIDGET_H
