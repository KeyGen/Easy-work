#include "corewidget.h"

#include "ui_corewidget.h"
#include <QWidget>
#include <QSize>

#include <QMenuBar>

Q_EXPORT_PLUGIN(CoreWidgetClass);

CoreWidgetClass::CoreWidgetClass() : ui(new Ui::CoreForm)
{
    widget = new QWidget();
    ui->setupUi(widget);
}

QSize CoreWidgetClass::getSize(){
    return widget->size();
}

void CoreWidgetClass::setMenuBar(QMenuBar *bar)
{
    ui->gridLayout->setMenuBar(bar);
}
