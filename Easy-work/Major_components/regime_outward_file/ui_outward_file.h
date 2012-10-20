/********************************************************************************
** Form generated from reading UI file 'outward_file.ui'
**
** Created: Sat Oct 20 19:28:46 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTWARD_FILE_H
#define UI_OUTWARD_FILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTextBrowser *textOutwardShow;
    QLabel *labelpathfile;
    QLineEdit *lineEditPath;
    QPushButton *pushOutwordFile;
    QLabel *labelTimer;
    QTimeEdit *boxEditTimer;
    QSlider *sliderTimer;
    QLabel *labelpositioncursor;
    QSlider *sliderPositionInText;
    QSpinBox *boxPositionInText;
    QPushButton *pushSave;
    QPushButton *pushClose;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(492, 403);
        textOutwardShow = new QTextBrowser(Dialog);
        textOutwardShow->setObjectName(QString::fromUtf8("textOutwardShow"));
        textOutwardShow->setGeometry(QRect(4, 164, 481, 201));
        labelpathfile = new QLabel(Dialog);
        labelpathfile->setObjectName(QString::fromUtf8("labelpathfile"));
        labelpathfile->setGeometry(QRect(7, 4, 471, 20));
        lineEditPath = new QLineEdit(Dialog);
        lineEditPath->setObjectName(QString::fromUtf8("lineEditPath"));
        lineEditPath->setGeometry(QRect(4, 30, 381, 23));
        pushOutwordFile = new QPushButton(Dialog);
        pushOutwordFile->setObjectName(QString::fromUtf8("pushOutwordFile"));
        pushOutwordFile->setGeometry(QRect(390, 30, 91, 24));
        labelTimer = new QLabel(Dialog);
        labelTimer->setObjectName(QString::fromUtf8("labelTimer"));
        labelTimer->setGeometry(QRect(7, 58, 471, 20));
        boxEditTimer = new QTimeEdit(Dialog);
        boxEditTimer->setObjectName(QString::fromUtf8("boxEditTimer"));
        boxEditTimer->setGeometry(QRect(4, 84, 91, 23));
        sliderTimer = new QSlider(Dialog);
        sliderTimer->setObjectName(QString::fromUtf8("sliderTimer"));
        sliderTimer->setGeometry(QRect(117, 84, 361, 23));
        sliderTimer->setOrientation(Qt::Horizontal);
        labelpositioncursor = new QLabel(Dialog);
        labelpositioncursor->setObjectName(QString::fromUtf8("labelpositioncursor"));
        labelpositioncursor->setGeometry(QRect(7, 111, 471, 20));
        sliderPositionInText = new QSlider(Dialog);
        sliderPositionInText->setObjectName(QString::fromUtf8("sliderPositionInText"));
        sliderPositionInText->setGeometry(QRect(117, 137, 361, 23));
        sliderPositionInText->setOrientation(Qt::Horizontal);
        boxPositionInText = new QSpinBox(Dialog);
        boxPositionInText->setObjectName(QString::fromUtf8("boxPositionInText"));
        boxPositionInText->setGeometry(QRect(4, 137, 91, 23));
        pushSave = new QPushButton(Dialog);
        pushSave->setObjectName(QString::fromUtf8("pushSave"));
        pushSave->setGeometry(QRect(295, 370, 91, 24));
        pushClose = new QPushButton(Dialog);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setGeometry(QRect(390, 370, 91, 24));

        retranslateUi(Dialog);
        QObject::connect(pushClose, SIGNAL(clicked()), Dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        labelpathfile->setText(QApplication::translate("Dialog", "<b>\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \321\204\320\260\320\271\320\273:</b>", 0, QApplication::UnicodeUTF8));
        pushOutwordFile->setText(QApplication::translate("Dialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        labelTimer->setText(QApplication::translate("Dialog", "<b>\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \321\202\320\260\320\271\320\274\320\265\321\200\320\260:</b>", 0, QApplication::UnicodeUTF8));
        labelpositioncursor->setText(QApplication::translate("Dialog", "<b>\320\237\320\276\320\267\320\270\321\206\320\270\321\217 \320\272\321\203\321\200\321\201\320\276\321\200\320\260:</b>", 0, QApplication::UnicodeUTF8));
        pushSave->setText(QApplication::translate("Dialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("Dialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTWARD_FILE_H
