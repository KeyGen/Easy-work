#ifndef WHAT_IS_GLOBAL_H
#define WHAT_IS_GLOBAL_H

#include <QtCore/qglobal.h>

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QDialog;
class QAction;
QT_END_NAMESPACE

class WhatIs : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QAction* getAction()    = 0;
    virtual void renameAction(QString)   = 0;

    virtual ~WhatIs() {}

public slots:
    virtual void exec() = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(WhatIs, "info.programm/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // WHAT_IS_GLOBAL_H
