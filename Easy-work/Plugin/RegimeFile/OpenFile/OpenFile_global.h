#ifndef OPENFILE_GLOBAL_H
#define OPENFILE_GLOBAL_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class OpenFile : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QAction * getAction()   = 0;
    virtual ~OpenFile() {}

signals:
    virtual void siSetNewText(QString)  = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(OpenFile, "OpenFile/RigimeFile/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // OPENFILE_GLOBAL_H
