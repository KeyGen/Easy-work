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
#include <QDesktopServices>

#include <QResizeEvent>
#include <QPushButton>
#include <QMenuBar>
#include <QWidget>
#include <QRegion>
#include <QSize>
#include <QTimer>

Q_EXPORT_PLUGIN(CoreWidgetClass)

CoreWidgetClass::CoreWidgetClass()
{
    startRegime = new QAction(tr("Выйти из режима"),this);
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    stopChangeText = true;
    posTextForQml = 0;

    textForQml << tr("<center><b>Добро пожаловать в программу Easy work!</b><br><i>(beta 0.4.1)</i></center>");

    textForQml << tr("<center>"
                  "Программа предназначена для, тренировки, изучения, <br>слепого метода печати."
                  "</center>");

    textForQml << tr("<center>"
                  "В меню режимы вы найдете режим для обучения. На данный<br>"
                  "момент имеется один режим - \"Режим файла\", в котором<br>"
                  "можно загрузить внешний файл для печати. "
                  "</center>");

    textForQml << tr("<center>"
                     "<b>Доступны следующие раскладки клавиатуры</b>:<br>"
                     "<span style=\" font-size:8pt;\">English<br>"
                     "Русский<br>"
                     "Український<br>"
                     "Беларускі<br>"
                     "Deutsch<br>"
                     "Italiano<br>"
                     "საქარფვედოს</span></center>");

    textForQml << tr("<center>"
                     "<b>В планах</b>:<br>"
                     "В ближайше время думаю заняться переводом приложения<br>"
                     "на английский, подкорректирую обновления."
                     "</center>");


    textForQml << tr("<center>"
                     "<b>Связь</b>:<br>"
                     "<span style=\" font-size:14pt;\">"
                     "Поддержка: нашли баг пишите: <a HREF=\"https://github.com/KeyGen/Easy-work/issues?state=open\">Lssues</a><br>"
                     "Официальный сайт: <a HREF=\"https://github.com/KeyGen/Easy-work/wiki\">Easy work</a><br>"
                     "Email: KeyGenQt@gmail.com"
                     "</span>");

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
    ui->widgetQml->setMinimumSize(850,150);

    ui->centralGridLayout->setMenuBar(menuBar);

    for(int i = 0; i<listMenu.size(); i++)
    menuBar->addMenu(listMenu.at(i));

    createRegimeMenu();

    connect(widget,SIGNAL(destroyed()),this,SLOT(destroyedWidget()));
    disconnect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    // Достум из С++ к qml
    QObject *rect = Root->findChild<QObject*>("qmlOneText");
    if(rect)
        rect->setProperty("text", textForQml.at(posTextForQml));

    if(!saveSizeQml.isEmpty()){
        int width = saveSizeQml.width()-8;
        int height = saveSizeQml.height()-70;
        if(Root){
            Root->setProperty("width", QString::number(width+200));
            Root->setProperty("height", QString::number(height+40));
        }
        ui->widgetQml->setMask(setRoundedCorners(width,height,10,10,10,10));
    }

    QTimer::singleShot(60000, this, SLOT(timerChangeText()));

    destroyedBL = false;

    return widget;
}

void CoreWidgetClass::goToSite(QString site){
    QDesktopServices::openUrl(QUrl(site));
}

void CoreWidgetClass::timerChangeText(){

    if(!destroyedBL){

        if(stopChangeText){
            followingText();

            if(Root->property("state").toString() == "shift")
                Root->setProperty("state","normal");
            else
                Root->setProperty("state","shift");
        }

        if(!stopChangeText)
            stopChangeText = true;

        QTimer::singleShot(60000, this, SLOT(timerChangeText()));
    }
}

void CoreWidgetClass::setStopChangeText(){
    stopChangeText = false;
}

void CoreWidgetClass::slResizeEvent (QResizeEvent * event){

    saveSizeQml = event->size();

    if(!destroyedBL){
        int width = event->size().width()-8;
        int height = event->size().height()-70;
        ui->widgetQml->setMask(setRoundedCorners(width,height,10,10,10,10));

        if(Root){
            Root->setProperty("width", QString::number(width+200));
            Root->setProperty("height", QString::number(height+100));
        }
    }
}

void CoreWidgetClass::followingText(){
    posTextForQml++;

    if(posTextForQml>=textForQml.size())
        posTextForQml = 0;

    QString nameObject;

    if(posTextForQml%2)
        nameObject = "qmlTwoText";
    else
        nameObject = "qmlOneText";

    // Достум из С++ к qml
    QObject *rect = Root->findChild<QObject*>(nameObject);
    if(rect)
        rect->setProperty("text", textForQml.at(posTextForQml));
}

void CoreWidgetClass::precedingText(){
    posTextForQml--;

    if(posTextForQml<0)
        posTextForQml = textForQml.size()-1;

    QString nameObject;

    if(posTextForQml%2)
        nameObject = "qmlTwoText";
    else
        nameObject = "qmlOneText";

    // Достум из С++ к qml
    QObject *rect = Root->findChild<QObject*>(nameObject);
    if(rect)
        rect->setProperty("text", textForQml.at(posTextForQml));
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

void CoreWidgetClass::getFocus(){
    emit siFocus();
}

void CoreWidgetClass::destroyedWidget(){
    destroyedBL = true;
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
}
