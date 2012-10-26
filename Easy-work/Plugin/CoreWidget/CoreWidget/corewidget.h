#ifndef COREWIDGET_H
#define COREWIDGET_H

#include "CoreWidget_global.h"

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
    virtual QWidget * getWidget()   { return widget; }
    virtual QSize getSize();
    virtual void setMenuBar(QMenuBar *);

    virtual ~CoreWidgetClass() {}

private:
    QWidget *widget;
    Ui::CoreForm *ui;
};

#endif // COREWIDGET_H
