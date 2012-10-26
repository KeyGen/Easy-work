#include "regimefile.h"
#include "ui_regimefile.h"
#include <QMenuBar>
#include <QWidget>
#include <QSize>

Q_EXPORT_PLUGIN(RigimeFileClass);

RigimeFileClass::RigimeFileClass()
{
    pathPlugin = "../Plugin/RegimeFile/readyPlugins";

    workerText = "Этот текст будет отображаться когда не загружен ни какой другой";

    menuRegimeFile = new QMenu(tr("Режим файла"));
    startRegime = new QAction(tr("Режим файла"),this);

    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    loadPlugins(pathPlugin);
}

RigimeFileClass::~RigimeFileClass(){
    delete ui;
}

QWidget * RigimeFileClass::getWidget() {

    menuBar = new QMenuBar();
    widget = new QWidget();
    ui = new Ui::RegimeFile;

    ui->setupUi(widget);

    for(int i = 0; i<listMenu.size(); i++){
        if(i == 2)
            menuBar->addMenu(menuRegimeFile);
        menuBar->addMenu(listMenu.at(i));
    }

    ui->centralGridLayout->setMenuBar(menuBar);

    return widget;
}

QSize RigimeFileClass::getSize(){
    return widget->size();
}

void RigimeFileClass::setMenuBar(QList <QMenu *> bar)
{
    listMenu = bar;

    if(!listMenu.isEmpty())
    {
        listMenu.at(1)->addAction(startRegime);
    }
}

void RigimeFileClass::slGetWidget(){

    emit siGetWidget(getWidget());
}

void RigimeFileClass::setWorkerText(QString workerTextTemp)
{
    workerText = workerTextTemp;
    ui->label_2->setText(workerText);
}
