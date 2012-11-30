/********************************************************************************
** Form generated from reading UI file 'regimeLesson.ui'
**
** Created: Fri Nov 30 21:34:00 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIMELESSON_H
#define UI_REGIMELESSON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormRegimeLesson
{
public:
    QGridLayout *gridLayout_2;
    QWidget *coreGridWidget;
    QGridLayout *gridLayout;
    QWidget *gridWidget;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *inputPassvord;
    QWidget *widgetQmlLesson;
    QGridLayout *widgetQml;
    QLabel *labelStart;
    QWidget *printWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelShow;
    QLabel *labelInput;

    void setupUi(QWidget *FormRegimeLesson)
    {
        if (FormRegimeLesson->objectName().isEmpty())
            FormRegimeLesson->setObjectName(QString::fromUtf8("FormRegimeLesson"));
        FormRegimeLesson->resize(670, 211);
        gridLayout_2 = new QGridLayout(FormRegimeLesson);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        coreGridWidget = new QWidget(FormRegimeLesson);
        coreGridWidget->setObjectName(QString::fromUtf8("coreGridWidget"));
        coreGridWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(coreGridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridWidget = new QWidget(coreGridWidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setStyleSheet(QString::fromUtf8("QWidget#gridWidget\n"
"{ background: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5, \n"
"				stop:0 #9C9C9C, \n"
"				stop:0.5 #E8E8E8, \n"
"				stop:1 #9C9C9C);\n"
"\n"
"    border: solid black;\n"
"    border-width: 2px 2px 2px 2px;\n"
"    border-radius: 15px;\n"
"    color: black;\n"
"    font: bold;\n"
"    font-size: 16px;\n"
"}"));
        gridLayout_3 = new QGridLayout(gridWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        comboBox = new QComboBox(gridWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(200, 0));

        gridLayout_3->addWidget(comboBox, 0, 1, 1, 1);

        pushButton = new QPushButton(gridWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(120, 0));
        pushButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(pushButton, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        inputPassvord = new QLineEdit(gridWidget);
        inputPassvord->setObjectName(QString::fromUtf8("inputPassvord"));
        inputPassvord->setEchoMode(QLineEdit::Password);
        inputPassvord->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(inputPassvord, 1, 1, 1, 1);


        gridLayout->addWidget(gridWidget, 0, 0, 1, 1);

        widgetQmlLesson = new QWidget(coreGridWidget);
        widgetQmlLesson->setObjectName(QString::fromUtf8("widgetQmlLesson"));
        widgetQmlLesson->setMouseTracking(false);
        widgetQml = new QGridLayout(widgetQmlLesson);
        widgetQml->setObjectName(QString::fromUtf8("widgetQml"));
        labelStart = new QLabel(widgetQmlLesson);
        labelStart->setObjectName(QString::fromUtf8("labelStart"));
        labelStart->setFrameShape(QFrame::Box);
        labelStart->setAlignment(Qt::AlignCenter);

        widgetQml->addWidget(labelStart, 1, 0, 1, 1);

        printWidget = new QWidget(widgetQmlLesson);
        printWidget->setObjectName(QString::fromUtf8("printWidget"));
        horizontalLayout = new QHBoxLayout(printWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 1);
        labelShow = new QLabel(printWidget);
        labelShow->setObjectName(QString::fromUtf8("labelShow"));
        labelShow->setFrameShape(QFrame::Box);
        labelShow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelShow);

        labelInput = new QLabel(printWidget);
        labelInput->setObjectName(QString::fromUtf8("labelInput"));
        labelInput->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(labelInput);


        widgetQml->addWidget(printWidget, 1, 1, 1, 1);


        gridLayout->addWidget(widgetQmlLesson, 1, 0, 1, 1);


        gridLayout_2->addWidget(coreGridWidget, 0, 0, 1, 1);


        retranslateUi(FormRegimeLesson);

        QMetaObject::connectSlotsByName(FormRegimeLesson);
    } // setupUi

    void retranslateUi(QWidget *FormRegimeLesson)
    {
        FormRegimeLesson->setWindowTitle(QApplication::translate("FormRegimeLesson", "\320\240\320\265\320\266\320\270\320\274 \321\203\321\200\320\276\320\272\320\276\320\262", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("FormRegimeLesson", "\320\224\320\260\320\273\321\210\320\265", 0, QApplication::UnicodeUTF8));
        labelStart->setText(QApplication::translate("FormRegimeLesson", "\320\237\321\200\320\276\320\261\320\265\320\273 - \320\275\320\260\321\207\320\260\321\202\321\214 \321\203\321\200\320\276\320\272,       Enter - \321\201\321\202\320\276\320\277 \n"
"Backspace - \320\262\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \320\262\321\213\320\261\320\276\321\203 \321\203\321\200\320\276\320\272\320\260 \n"
"Esc    -    \320\262\320\265\321\200\320\275\321\203\321\202\321\201\321\217  \320\272  \320\262\321\213\320\261\320\276\321\200\321\203  \321\203\321\207\320\265\320\275\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        labelShow->setText(QString());
        labelInput->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormRegimeLesson: public Ui_FormRegimeLesson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIMELESSON_H
