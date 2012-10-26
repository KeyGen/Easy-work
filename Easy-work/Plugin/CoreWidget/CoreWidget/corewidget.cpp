#include "corewidget.h"

#include "ui_corewidget.h"
#include <QMenuBar>
#include <QWidget>
#include <QSize>

Q_EXPORT_PLUGIN(CoreWidgetClass);

CoreWidgetClass::CoreWidgetClass()
{
    startRegime = new QAction(tr("Выйти из режима"),this);
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
}

QWidget * CoreWidgetClass::getWidget() {

    menuBar = new QMenuBar();
    widget = new QWidget();
    ui = new Ui::CoreForm;
    ui->setupUi(widget);

    ui->centralGridLayout->setMenuBar(menuBar);

    for(int i = 0; i<listMenu.size(); i++)
    menuBar->addMenu(listMenu.at(i));

    return widget;
}

QSize CoreWidgetClass::getSize(){
    return widget->size();
}

void CoreWidgetClass::setMenuBar(QList <QMenu *> bar)
{
    listMenu = bar;

    if(!listMenu.isEmpty())
    listMenu.at(1)->addAction(startRegime);
}

void CoreWidgetClass::slGetWidget(){
    emit siGetWidget(getWidget());
}
