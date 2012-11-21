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

#include "corewidget.h"
#include "ui_corewidget.h"

#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

#include <QResizeEvent>
#include <QPushButton>
#include <QMenuBar>
#include <QWidget>
#include <QRegion>
#include <QSize>

Q_EXPORT_PLUGIN(CoreWidgetClass)

CoreWidgetClass::CoreWidgetClass()
{
    startRegime = new QAction(tr("Выйти из режима"),this);
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
}

void CoreWidgetClass::readDB(){

    bool openBL = true;

    QSqlQuery query;
    if (!query.exec("SELECT * FROM mainWindow;")) {
        qDebug() << "Unable to execute query - exiting";
        openBL = false;
    }

    if(openBL){
        //Reading of the data
        QSqlRecord rec = query.record();

        QString id;
        QString contents;
        QString sizeContents;
        QString xContents;
        QString yContents;
        QString text;
        QString sizeText;
        QString xText;
        QString yText;
        QString imageWidth;
        QString imageHeight;
        QString xImage;
        QString yImage;
        QString stopWidgetWidth;
        QString stopWidgetHeight;
        QByteArray image;


        QPixmap pix;
        while (query.next()) {
            id =                query.value(rec.indexOf("id")).toString();
            contents =          query.value(rec.indexOf("contents")).toString();
            sizeContents =      query.value(rec.indexOf("sizeContents")).toString();
            xContents =         query.value(rec.indexOf("xContents")).toString();
            yContents =         query.value(rec.indexOf("yContents")).toString();
            text =              query.value(rec.indexOf("text")).toString();
            sizeText =          query.value(rec.indexOf("sizeText")).toString();
            xText =             query.value(rec.indexOf("xText")).toString();
            yText =             query.value(rec.indexOf("yText")).toString();
            imageWidth =        query.value(rec.indexOf("imageWidth")).toString();
            imageHeight =       query.value(rec.indexOf("imageHeight")).toString();
            xImage =            query.value(rec.indexOf("xImage")).toString();
            yImage =            query.value(rec.indexOf("yImage")).toString();
            stopWidgetWidth =   query.value(rec.indexOf("stopWidgetWidth")).toString();
            stopWidgetHeight =  query.value(rec.indexOf("stopWidgetHeight")).toString();
            image =             query.value(rec.indexOf("image")).toByteArray();
        }

        pix.loadFromData(image);
        pix.save("../share/EasyWork/Database/temp.png");

        QObject *objectTextOneContents = Root->findChild<QObject*>("objectTextOneContents");
        if(objectTextOneContents){
            objectTextOneContents->setProperty("text", contents);
            objectTextOneContents->setProperty("font.pixelSize", sizeContents);
            objectTextOneContents->setProperty("x", xContents);
            objectTextOneContents->setProperty("y", yContents);
        }

        QObject *objectTextOneText = Root->findChild<QObject*>("objectTextOneText");
        if(objectTextOneText){
            objectTextOneText->setProperty("text", text);
            objectTextOneText->setProperty("font.pixelSize", sizeText);
            objectTextOneText->setProperty("x", xText);
            objectTextOneText->setProperty("y", yText);
        }

        QObject *imageOne = Root->findChild<QObject*>("imageOne");
        if(imageOne){
            imageOne->setProperty("source", "../share/EasyWork/Database/temp.png");
            imageOne->setProperty("width", imageWidth);
            imageOne->setProperty("height", imageHeight);
            imageOne->setProperty("x", xImage);
            imageOne->setProperty("y", yImage);
        }

        widget->setMinimumHeight(stopWidgetHeight.toInt());
        widget->setMinimumWidth(stopWidgetWidth.toInt());
    }
}

void CoreWidgetClass::createConnection(QString path, QString name){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path + "/" + name);

    db.setUserName("user");

    if (!db.open()) {
        ;
    }
    else
        readDB();
}

QWidget * CoreWidgetClass::getWidget() {

    menuBar = new QMenuBar();
    widget = new QWidget();
    ui = new Ui::CoreForm;
    ui->setupUi(widget);

    //Включаем наш QML
    ui_d = new QDeclarativeView();
    ui_d->setSource(QUrl("qrc:/main.qml"));

    //Находим корневой элемент
    Root = ui_d->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент Qt_fun
    ui_d->rootContext()->setContextProperty("Qt_fun", this);

    ui->widgetQml->layout()->addWidget(ui_d);

    ui->centralGridLayout->setMenuBar(menuBar);

    for(int i = 0; i<listMenu.size(); i++)
    menuBar->addMenu(listMenu.at(i));

    createRegimeMenu();

    connect(widget,SIGNAL(destroyed()),this,SLOT(destroyedWidget()));
    disconnect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
    destroyedBL = false;

    createConnection();

    return widget;
}

void CoreWidgetClass::slResizeEvent (QResizeEvent * event){
    if(!destroyedBL){
        int width = event->size().width()-8;
        int height = event->size().height()-70;
        ui->widgetQml->setMask(setRoundedCorners(width,height,10,10,10,10));

        if(Root){
            Root->setProperty("width", QString::number(width+200));
            Root->setProperty("height", QString::number(height+200));
        }
    }
}

QRegion CoreWidgetClass::setRoundedCorners(int width, int height,
                                           int radius_tl,
                                           int radius_tr,
                                           int radius_bl,
                                           int radius_br){

    QRegion region(0, 0, width, height, QRegion::Rectangle);

    // top left
    QRegion round (0, 0, 2*radius_tl, 2*radius_tl, QRegion::Ellipse);
    QRegion corner(0, 0, radius_tl, radius_tl, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // top right
    round = QRegion(width-2*radius_tr, 0, 2*radius_tr, 2*radius_tr, QRegion::Ellipse);
    corner = QRegion(width-radius_tr, 0, radius_tr, radius_tr, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom right
    round = QRegion(width-2*radius_br, height-2*radius_br, 2*radius_br, 2*radius_br, QRegion::Ellipse);
    corner = QRegion(width-radius_br, height-radius_br, radius_br, radius_br, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom left
    round = QRegion(0, height-2*radius_bl, 2*radius_bl, 2*radius_bl, QRegion::Ellipse);
    corner = QRegion(0, height-radius_bl, radius_bl, radius_bl, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    return region;
}

void CoreWidgetClass::activationRegime(){
    startRegime->trigger();
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

void CoreWidgetClass::setRegimeMenu(QAction* action,const QIcon icon){
    listIconRegime << icon;
    listActionRegime << action;
}

void CoreWidgetClass::createRegimeMenu(){

    for(int i = 0; i<listActionRegime.size(); i++){
        QPushButton *regimePush = new QPushButton(listIconRegime.at(i), listActionRegime.at(i)->text());
        ui->layoutRegime->addWidget(regimePush);
        connect(regimePush,SIGNAL(clicked()),listActionRegime.at(i),SIGNAL(triggered()));
    }
}

void CoreWidgetClass::destroyedWidget(){
    destroyedBL = true;
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
}
