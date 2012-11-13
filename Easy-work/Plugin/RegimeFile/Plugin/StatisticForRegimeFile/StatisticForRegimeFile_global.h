#ifndef STATISTICFORREGIMEFILE_GLOBAL_H
#define STATISTICFORREGIMEFILE_GLOBAL_H

#include <QStringList>
#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class StatisticForRegimeFile : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QAction *getAction()    = 0;

    virtual ~StatisticForRegimeFile() {}

public slots:
    virtual void setValue(QStringList)   = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(StatisticForRegimeFile, "StatisticForRegimeFile/RigimeFile/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // STATISTICFORREGIMEFILE_GLOBAL_H
