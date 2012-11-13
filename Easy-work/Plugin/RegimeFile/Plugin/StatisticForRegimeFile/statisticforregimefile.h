#ifndef STATISTICFORREGIMEFILE_H
#define STATISTICFORREGIMEFILE_H

#include "StatisticForRegimeFile_global.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
class QDialog;
QT_END_NAMESPACE

namespace Ui {
class statisticDialog;
}

class StatisticForRegimeFileClass : public StatisticForRegimeFile
{
    Q_OBJECT Q_INTERFACES(StatisticForRegimeFile)

public:
    StatisticForRegimeFileClass();

    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Statistic for Regime File"; }
    virtual QAction * getAction()   { return showStatistic; }

    virtual ~StatisticForRegimeFileClass() {}

public slots:
    virtual void setValue(QStringList);

private slots:
    void exec();
    void setActiveItemWidget(int);
    void deleteStatisticAll();
    void deleteStatistic();

private:
    bool createConnection(QString path = "mdb", QString name = "statisticForRegimeFile.mdb");
    void readMDB();
    void insertMDB(QStringList value);
    void createTableVerticalHeader(QHash<QString,QStringList>);

private:
    Ui::statisticDialog *ui;
    QDialog *dialogStatistic;
    bool createMDB;
    QAction *showStatistic;
    int activeHeder;
    QString pathMDB;
    QString nameMDB;
};

#endif // STATISTICFORREGIMEFILE_H
