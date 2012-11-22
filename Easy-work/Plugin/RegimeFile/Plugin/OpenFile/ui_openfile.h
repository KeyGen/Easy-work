/********************************************************************************
** Form generated from reading UI file 'openfile.ui'
**
** Created: Wed Nov 21 11:24:54 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENFILE_H
#define UI_OPENFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogOpenFile
{
public:
    QGridLayout *gridLayout_2;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBoxCodec;
    QPushButton *pushSave;
    QPushButton *pushClose;
    QTextBrowser *textOutwardShow;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelpathfile;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditPath;
    QPushButton *pushOutwordFile;
    QLabel *labelpositioncursor;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *boxPositionInText;
    QSlider *sliderPositionInText;

    void setupUi(QDialog *DialogOpenFile)
    {
        if (DialogOpenFile->objectName().isEmpty())
            DialogOpenFile->setObjectName(QString::fromUtf8("DialogOpenFile"));
        DialogOpenFile->resize(482, 435);
        gridLayout_2 = new QGridLayout(DialogOpenFile);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridWidget = new QWidget(DialogOpenFile);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBoxCodec = new QComboBox(gridWidget);
        comboBoxCodec->setObjectName(QString::fromUtf8("comboBoxCodec"));

        horizontalLayout_3->addWidget(comboBoxCodec);

        pushSave = new QPushButton(gridWidget);
        pushSave->setObjectName(QString::fromUtf8("pushSave"));

        horizontalLayout_3->addWidget(pushSave);

        pushClose = new QPushButton(gridWidget);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        horizontalLayout_3->addWidget(pushClose);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        textOutwardShow = new QTextBrowser(gridWidget);
        textOutwardShow->setObjectName(QString::fromUtf8("textOutwardShow"));
        textOutwardShow->setReadOnly(true);
        textOutwardShow->setAcceptRichText(true);
        textOutwardShow->setOpenLinks(false);

        gridLayout->addWidget(textOutwardShow, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelpathfile = new QLabel(gridWidget);
        labelpathfile->setObjectName(QString::fromUtf8("labelpathfile"));

        verticalLayout_2->addWidget(labelpathfile);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEditPath = new QLineEdit(gridWidget);
        lineEditPath->setObjectName(QString::fromUtf8("lineEditPath"));

        horizontalLayout_2->addWidget(lineEditPath);

        pushOutwordFile = new QPushButton(gridWidget);
        pushOutwordFile->setObjectName(QString::fromUtf8("pushOutwordFile"));

        horizontalLayout_2->addWidget(pushOutwordFile);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        labelpositioncursor = new QLabel(gridWidget);
        labelpositioncursor->setObjectName(QString::fromUtf8("labelpositioncursor"));

        verticalLayout_3->addWidget(labelpositioncursor);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        boxPositionInText = new QSpinBox(gridWidget);
        boxPositionInText->setObjectName(QString::fromUtf8("boxPositionInText"));

        horizontalLayout_5->addWidget(boxPositionInText);

        sliderPositionInText = new QSlider(gridWidget);
        sliderPositionInText->setObjectName(QString::fromUtf8("sliderPositionInText"));
        sliderPositionInText->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(sliderPositionInText);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_2->addWidget(gridWidget, 0, 0, 1, 1);


        retranslateUi(DialogOpenFile);

        QMetaObject::connectSlotsByName(DialogOpenFile);
    } // setupUi

    void retranslateUi(QDialog *DialogOpenFile)
    {
        DialogOpenFile->setWindowTitle(QApplication::translate("DialogOpenFile", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        pushSave->setText(QApplication::translate("DialogOpenFile", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DialogOpenFile", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        textOutwardShow->setHtml(QApplication::translate("DialogOpenFile", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelpathfile->setText(QApplication::translate("DialogOpenFile", "<b>\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \321\204\320\260\320\271\320\273:</b>", 0, QApplication::UnicodeUTF8));
        pushOutwordFile->setText(QApplication::translate("DialogOpenFile", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        labelpositioncursor->setText(QApplication::translate("DialogOpenFile", "<b>\320\237\320\276\320\267\320\270\321\206\320\270\321\217 \320\272\321\203\321\200\321\201\320\276\321\200\320\260:</b>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogOpenFile: public Ui_DialogOpenFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENFILE_H
