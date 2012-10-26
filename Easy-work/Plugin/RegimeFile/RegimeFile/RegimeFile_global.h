#ifndef REGIMEFILE_GLOBAL_H
#define REGIMEFILE_GLOBAL_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QSize;
class QMenuBar;
class QMenu;
QT_END_NAMESPACE

class RigimeFile : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QWidget* getWidget()    = 0;
    virtual QSize getSize()         = 0;
    virtual void setMenuBar(QList <QMenu *>) = 0;

    virtual ~RigimeFile() {}

signals:
    virtual void siGetWidget(QWidget *) = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(RigimeFile, "RigimeFile/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // REGIMEFILE_GLOBAL_H
