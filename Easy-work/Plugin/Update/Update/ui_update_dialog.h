/********************************************************************************
** Form generated from reading UI file 'update_dialog.ui'
**
** Created: Wed Nov 21 23:03:53 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_DIALOG_H
#define UI_UPDATE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *save;
    QPushButton *close;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *showInstallVersion;
    QLabel *label_2;
    QLabel *showObtainableVersion;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *showExamination;
    QComboBox *comboBoxTime;
    QPushButton *examinationUpdate;
    QWidget *widgetTemp;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *updateOff;
    QRadioButton *updateOn;

    void setupUi(QDialog *UpdateDialog)
    {
        if (UpdateDialog->objectName().isEmpty())
            UpdateDialog->setObjectName(QString::fromUtf8("UpdateDialog"));
        UpdateDialog->resize(451, 202);
        gridLayout = new QGridLayout(UpdateDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        save = new QPushButton(UpdateDialog);
        save->setObjectName(QString::fromUtf8("save"));
        save->setMinimumSize(QSize(88, 0));

        gridLayout->addWidget(save, 3, 2, 1, 1);

        close = new QPushButton(UpdateDialog);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(88, 0));

        gridLayout->addWidget(close, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(251, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        groupBox = new QGroupBox(UpdateDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        showInstallVersion = new QLabel(groupBox);
        showInstallVersion->setObjectName(QString::fromUtf8("showInstallVersion"));

        horizontalLayout->addWidget(showInstallVersion);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        showObtainableVersion = new QLabel(groupBox);
        showObtainableVersion->setObjectName(QString::fromUtf8("showObtainableVersion"));

        horizontalLayout->addWidget(showObtainableVersion);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 2);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 2, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        showExamination = new QLabel(groupBox);
        showExamination->setObjectName(QString::fromUtf8("showExamination"));

        horizontalLayout_2->addWidget(showExamination);

        comboBoxTime = new QComboBox(groupBox);
        comboBoxTime->setObjectName(QString::fromUtf8("comboBoxTime"));
        comboBoxTime->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(comboBoxTime);

        examinationUpdate = new QPushButton(groupBox);
        examinationUpdate->setObjectName(QString::fromUtf8("examinationUpdate"));
        examinationUpdate->setMinimumSize(QSize(131, 0));
        examinationUpdate->setMaximumSize(QSize(131, 16777215));

        horizontalLayout_2->addWidget(examinationUpdate);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 0, 1, 2);


        gridLayout->addWidget(groupBox, 2, 0, 1, 4);

        widgetTemp = new QWidget(UpdateDialog);
        widgetTemp->setObjectName(QString::fromUtf8("widgetTemp"));
        horizontalLayout_3 = new QHBoxLayout(widgetTemp);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        updateOff = new QRadioButton(widgetTemp);
        updateOff->setObjectName(QString::fromUtf8("updateOff"));
        updateOff->setCheckable(true);
        updateOff->setChecked(false);

        horizontalLayout_3->addWidget(updateOff);

        updateOn = new QRadioButton(widgetTemp);
        updateOn->setObjectName(QString::fromUtf8("updateOn"));

        horizontalLayout_3->addWidget(updateOn);


        gridLayout->addWidget(widgetTemp, 0, 0, 1, 4);


        retranslateUi(UpdateDialog);

        QMetaObject::connectSlotsByName(UpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateDialog)
    {
        UpdateDialog->setWindowTitle(QApplication::translate("UpdateDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("UpdateDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("UpdateDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("UpdateDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UpdateDialog", "<b>\320\243\321\201\321\202\320\275\320\276\320\262\320\273\320\265\320\275\320\260 \320\262\320\265\321\200\321\201\320\270\321\217:</b>", 0, QApplication::UnicodeUTF8));
        showInstallVersion->setText(QApplication::translate("UpdateDialog", "0.4.1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UpdateDialog", "<b>\320\224\320\276\321\201\321\202\321\203\320\277\320\275\320\260 \320\262\320\265\321\200\321\201\320\270\321\217:</b>", 0, QApplication::UnicodeUTF8));
        showObtainableVersion->setText(QApplication::translate("UpdateDialog", "<html><head/><body><p>\320\275\320\265\321\202 \320\264\320\260\320\275\320\275\321\213\321\205</p></body></html>", 0, QApplication::UnicodeUTF8));
        showExamination->setText(QApplication::translate("UpdateDialog", "<b>\320\237\321\200\320\276\320\262\320\265\321\200\321\217\321\202\321\214</b>:", 0, QApplication::UnicodeUTF8));
        examinationUpdate->setText(QApplication::translate("UpdateDialog", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\201\320\265\320\271\321\207\320\260\321\201", 0, QApplication::UnicodeUTF8));
        updateOff->setText(QApplication::translate("UpdateDialog", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        updateOn->setText(QApplication::translate("UpdateDialog", "\320\237\321\200\320\276\320\262\320\265\321\200\321\217\321\202\321\214 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UpdateDialog: public Ui_UpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_DIALOG_H
