/********************************************************************************
** Form generated from reading UI file 'statisticDialog.ui'
**
** Created: Wed Nov 21 11:24:50 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICDIALOG_H
#define UI_STATISTICDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_statisticDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *deleteStatistic;
    QPushButton *deleteAllStatistic;
    QPushButton *close;
    QTableWidget *tableWidget;

    void setupUi(QDialog *statisticDialog)
    {
        if (statisticDialog->objectName().isEmpty())
            statisticDialog->setObjectName(QString::fromUtf8("statisticDialog"));
        statisticDialog->resize(545, 333);
        gridLayout = new QGridLayout(statisticDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        deleteStatistic = new QPushButton(statisticDialog);
        deleteStatistic->setObjectName(QString::fromUtf8("deleteStatistic"));
        deleteStatistic->setEnabled(false);

        gridLayout->addWidget(deleteStatistic, 2, 0, 1, 1);

        deleteAllStatistic = new QPushButton(statisticDialog);
        deleteAllStatistic->setObjectName(QString::fromUtf8("deleteAllStatistic"));

        gridLayout->addWidget(deleteAllStatistic, 2, 1, 1, 1);

        close = new QPushButton(statisticDialog);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(close, 2, 2, 1, 1);

        tableWidget = new QTableWidget(statisticDialog);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(391, 0));
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragEnabled(false);
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(99);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 3);


        retranslateUi(statisticDialog);
        QObject::connect(close, SIGNAL(clicked()), statisticDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(statisticDialog);
    } // setupUi

    void retranslateUi(QDialog *statisticDialog)
    {
        statisticDialog->setWindowTitle(QApplication::translate("statisticDialog", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        deleteStatistic->setText(QApplication::translate("statisticDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        deleteAllStatistic->setText(QApplication::translate("statisticDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("statisticDialog", "\320\222\321\213\320\271\321\202\320\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("statisticDialog", "\320\236\321\210\320\270\320\261\320\272\320\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("statisticDialog", "\320\235\320\260\320\277\320\265\321\207\320\260\321\202\320\260\320\275\320\275\320\276", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("statisticDialog", "\320\222\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("statisticDialog", "\320\227\320\275/\320\274\320\270\320\275", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class statisticDialog: public Ui_statisticDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICDIALOG_H
