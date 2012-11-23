#ifndef REGIMELESSON_GLOBAL_H
#define REGIMELESSON_GLOBAL_H

#include <QtCore/qglobal.h>

#include <QStringList>
#include <QtPlugin>

QT_BEGIN_NAMESPACE
//class QSize;
//class QMenuBar;
class QMenu;
//class QKeyEvent;
//class QResizeEvent;
class QIcon;
class QAction;
QT_END_NAMESPACE

class RegimeLesson : public QObject
{

public:
    virtual QString getVersion()        = 0;
    virtual QString getName()           = 0;
    virtual QWidget* getWidget()        = 0;
    virtual void setMenuBar(QList <QMenu *>) = 0;
    virtual QAction * getActionRegime() = 0;
    virtual const QIcon getIcon() = 0;

    virtual ~RegimeLesson() {}

public slots:
    virtual void slSetSaveSetting(QStringList) = 0;
    virtual void slCloseEvent () = 0;

signals:
    virtual void siSaveSetting(QStringList) = 0;
    virtual void siGetWidget(QWidget *) = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(RegimeLesson, "RegimeLesson/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // REGIMELESSON_GLOBAL_H
