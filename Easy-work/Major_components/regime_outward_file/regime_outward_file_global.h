#ifndef REGIME_OUTWARD_FILE_GLOBAL_H
#define REGIME_OUTWARD_FILE_GLOBAL_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class RegimeFile : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QAction* getActions()   = 0;

    virtual ~RegimeFile() {}
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(RegimeFile, "regime.outward.file.programm/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // REGIME_OUTWARD_FILE_GLOBAL_H
