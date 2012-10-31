/********************************************************************************
** Form generated from reading UI file 'corewidget.ui'
**
** Created: Tue Oct 30 21:54:45 2012
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoreForm
{
public:
    QGridLayout *centralGridLayout;
    QLabel *label;

    void setupUi(QWidget *CoreForm)
    {
        if (CoreForm->objectName().isEmpty())
            CoreForm->setObjectName(QString::fromUtf8("CoreForm"));
        CoreForm->resize(705, 243);
        centralGridLayout = new QGridLayout(CoreForm);
        centralGridLayout->setObjectName(QString::fromUtf8("centralGridLayout"));
        label = new QLabel(CoreForm);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);

        centralGridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(CoreForm);

        QMetaObject::connectSlotsByName(CoreForm);
    } // setupUi

    void retranslateUi(QWidget *CoreForm)
    {
        CoreForm->setWindowTitle(QApplication::translate("CoreForm", "Easy work v1.0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CoreForm", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203 Easy work", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CoreForm: public Ui_CoreForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COREWIDGET_H
