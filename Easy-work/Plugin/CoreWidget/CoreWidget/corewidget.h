#ifndef COREWIDGET_H
#define COREWIDGET_H

#include "CoreWidget_global.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

namespace Ui {
class CoreForm;
}

class CoreWidgetClass : public CoreWidget
{
    Q_OBJECT Q_INTERFACES(CoreWidget)

public:
    CoreWidgetClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Core Widget"; }
    virtual QWidget * getWidget();
    virtual QSize getSize();
    virtual void setMenuBar(QList <QMenu *>);

    virtual ~CoreWidgetClass() { delete ui; }

private:
    QWidget *widget;
    QMenuBar *menuBar;
    QAction *startRegime;
    Ui::CoreForm *ui;
    QList <QMenu *> listMenu;

private slots:
    void slGetWidget();

signals:
    void siGetWidget(QWidget *);
};

#endif // COREWIDGET_H
