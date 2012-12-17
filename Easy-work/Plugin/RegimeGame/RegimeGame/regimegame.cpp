/**
 * Easy work - краткое описание на английском
 * Copyright (C) 2012 KeyGen <KeyGenQt@gmail.com>
 * https://github.com/KeyGen/Easy-work/wiki
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "regimegame.h"
#include "ui_formGame.h"
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QKeyEvent>


#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QDesktopServices>

Q_EXPORT_PLUGIN(RegimeGameClass)


RegimeGameClass::RegimeGameClass(){

    startRegime = new QAction(tr("Режим игруха"),this);

    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    destroyedBL = true;
    menuRegimeGame = new QMenu(tr("Режим игры"));

}

QWidget* RegimeGameClass::getWidget(){
    destroyedBL = false;

    menuBar = new QMenuBar();
    widget = new QWidget();
    ui = new Ui::Regime;
    ui->setupUi(widget);

    //Включаем наш QML
    ui_d = new QDeclarativeView();
    ui_d->setSource(QUrl("qrc:/mainGame"));

    //Находим корневой элемент
    Root = ui_d->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент Qt_fun
    ui_d->rootContext()->setContextProperty("Qt_fun", this);

    ui->widgetQml->layout()->addWidget(ui_d);

    for(int i = 0; i<listMenu.size(); i++)
    menuBar->addMenu(listMenu.at(i));

    for(int i = 0; i<listMenu.size(); i++){
        if(i == 2)
            menuBar->addMenu(menuRegimeGame);
        menuBar->addMenu(listMenu.at(i));
    }

    ui->gridLayout->setMenuBar(menuBar);

    QList<QAction*> listAction;
    listAction = listMenu.at(1)->actions();
    for(int i = 0; i<listAction.size(); i++){
        if(i == 0)
            listAction.at(i)->setVisible(true);
        else
            listAction.at(i)->setVisible(false);
    }

    if(!saveSize.isEmpty()){
        if(Root){
            Root->setProperty("width", QString::number(saveSize.width()));
            Root->setProperty("height", QString::number(saveSize.height()));
        }
    }

    connect(widget,SIGNAL(destroyed()),this,SLOT(destroyedWidget()));
    disconnect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    return widget;
}

void RegimeGameClass::slGetWidget(){
    emit siGetWidget(getWidget());
}

void RegimeGameClass::destroyedWidget(){
    destroyedBL = true;
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
}

void RegimeGameClass::setMenuBar(QList <QMenu *> bar){
    listMenu = bar;
    if(!listMenu.isEmpty()){
        listMenu.at(1)->addAction(startRegime);
    }
}

const QIcon RegimeGameClass::getIcon(){
    const QIcon *ico = new QIcon(":/iconGame");
    return *ico;
}

void RegimeGameClass::slResizeEvent (QResizeEvent * event){

    saveSize.setWidth(event->size().width()+392);
    saveSize.setHeight(event->size().height()+166);

    if(!destroyedBL){
        if(Root){

            Root->setProperty("width", QString::number(ui->widgetQml->width()+400));
            Root->setProperty("height", QString::number(ui->widgetQml->height()+200));
        }
    }
}
