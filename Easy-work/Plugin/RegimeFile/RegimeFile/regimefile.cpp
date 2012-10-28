/**
 * Easy work - writed by KeyGen 2012
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

#include "regimefile.h"
#include "ui_regimefile.h"
#include <QKeyEvent>
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

void RigimeFileClass::slKeyPressEvent (QKeyEvent *event){

    if(event->text().contains(*regExpWord)||event->text() == " "){
        centralAdministration(event->text().at(0));
    }
}

void RigimeFileClass::centralAdministration(QChar inputWord){

    if(!ui->labelInput->text().isEmpty()){
        if(ui->labelInput->text().at(0) == inputWord)
        {
            ui->labelShow->setText(ui->labelShow->text() + QString(inputWord));
            ui->labelInput->setText(ui->labelInput->text().right(ui->labelInput->text().size() - 1));

            if(ui->labelInput->text().isEmpty())
                qDebug() << "Конец текста";
        }
        else
        {
            qDebug() << "error";
        }
    }
    else
    {
        qDebug() << "Конец";
    }
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
    ui->labelInput->setText(workerText);
    ui->labelShow->clear();
}

// 1761
