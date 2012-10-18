/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Oct 18 22:13:26 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *showText;
    QLabel *inputText;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *start;
    QMenu *regime;
    QMenu *students;
    QMenu *setting;
    QMenu *help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(761, 167);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        showText = new QLabel(page);
        showText->setObjectName(QString::fromUtf8("showText"));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        showText->setFont(font);
        showText->setStyleSheet(QString::fromUtf8(""));
        showText->setFrameShape(QFrame::NoFrame);
        showText->setScaledContents(false);
        showText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        showText->setMargin(0);
        showText->setIndent(0);

        horizontalLayout->addWidget(showText);

        inputText = new QLabel(page);
        inputText->setObjectName(QString::fromUtf8("inputText"));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        inputText->setFont(font1);
        inputText->setStyleSheet(QString::fromUtf8(""));
        inputText->setFrameShape(QFrame::NoFrame);
        inputText->setScaledContents(false);
        inputText->setMargin(0);
        inputText->setIndent(0);

        horizontalLayout->addWidget(inputText);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(80);

        gridLayout_2->addWidget(progressBar, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 761, 21));
        start = new QMenu(menuBar);
        start->setObjectName(QString::fromUtf8("start"));
        regime = new QMenu(menuBar);
        regime->setObjectName(QString::fromUtf8("regime"));
        students = new QMenu(menuBar);
        students->setObjectName(QString::fromUtf8("students"));
        setting = new QMenu(menuBar);
        setting->setObjectName(QString::fromUtf8("setting"));
        help = new QMenu(menuBar);
        help->setObjectName(QString::fromUtf8("help"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(start->menuAction());
        menuBar->addAction(regime->menuAction());
        menuBar->addAction(students->menuAction());
        menuBar->addAction(setting->menuAction());
        menuBar->addAction(help->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        showText->setText(QApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\265\321\200\320\265\320\274\320\265\320\275\321\202 \321\201 \321\200\320\260\320\267", 0, QApplication::UnicodeUTF8));
        inputText->setText(QApplication::translate("MainWindow", "\321\200\321\213\320\262\320\276\320\274 \321\202\320\265\320\272\321\201\321\202\320\260...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        start->setTitle(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", 0, QApplication::UnicodeUTF8));
        regime->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274\321\213", 0, QApplication::UnicodeUTF8));
        students->setTitle(QApplication::translate("MainWindow", "\320\243\321\207\320\265\320\275\320\270\320\272\320\270", 0, QApplication::UnicodeUTF8));
        setting->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        help->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
