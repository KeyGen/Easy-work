#ifndef REGIMEFILE_H
#define REGIMEFILE_H

#include "RegimeFile_global.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

namespace Ui {
class RegimeFile;
}

class RigimeFileClass : public RigimeFile
{
    Q_OBJECT Q_INTERFACES(RigimeFile)

public:
    RigimeFileClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Regime File"; }
    virtual QWidget * getWidget();
    virtual QSize getSize();
    virtual void setMenuBar(QList <QMenu *>);

    virtual ~RigimeFileClass();

private:
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuRegimeFile;
    QAction *startRegime;
    Ui::RegimeFile *ui;
    QList <QMenu *> listMenu;
    QString pathPlugin;
    QString workerText;

private:
     void loadPlugins(const QString dir);

private slots:
    void slGetWidget();
    void setWorkerText(QString);

signals:
    void siGetWidget(QWidget *);
};

#endif // REGIMEFILE_H
