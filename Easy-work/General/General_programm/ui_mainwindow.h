/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Oct 17 20:57:27 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *start;
    QMenu *regime;
    QMenu *students;
    QMenu *setting;
    QMenu *help;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(505, 245);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 505, 21));
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
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(start->menuAction());
        menuBar->addAction(regime->menuAction());
        menuBar->addAction(students->menuAction());
        menuBar->addAction(setting->menuAction());
        menuBar->addAction(help->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
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
