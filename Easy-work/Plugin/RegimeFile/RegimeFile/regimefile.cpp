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
#include "ui_infoPrint.h"

#include <QKeyEvent>
#include <QMenuBar>
#include <QDialog>
#include <QWidget>
#include <QTimer>
#include <QIcon>
#include <QTime>
#include <QSize>

Q_EXPORT_PLUGIN(RigimeFileClass);

RigimeFileClass::RigimeFileClass() : uiDialog (new Ui::InfoPrint)
{
    dialog = new QDialog;
    uiDialog->setupUi(dialog);

    calculateTime = new QTime;

    pathPlugin = "Plugins/PluginsRegimeFile";

    destroyedBL = true;
    startBL = false;

    workerText = "Вы можете загрузить внешний файл в меню \"Режим файла\"";

    menuRegimeFile = new QMenu(tr("Режим файла"));
    startRegime = new QAction(tr("Режим файла"),this);

    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    loadPlugins(pathPlugin);
}

QIcon RigimeFileClass::getIcon(){
    return QIcon(":/icon");
}

void RigimeFileClass::slResizeEvent (QResizeEvent * event){

    saveSizeLabelInputAndShow.setHeight(event->size().height()-33);
    saveSizeLabelInputAndShow.setWidth(event->size().width()-14);

    if(!destroyedBL)
    {
        if(ui->labelInput->width() == 0){
            ui->labelStart->setMaximumSize(saveSizeLabelInputAndShow);
        }
        else {
            ui->labelInput->setMaximumWidth(saveSizeLabelInputAndShow.width()/2);
            ui->labelShow->setMaximumWidth(saveSizeLabelInputAndShow.width()/2);
            ui->labelStart->setMaximumSize(saveSizeLabelInputAndShow);
        }
    }

}

void RigimeFileClass::siKeyboardLanguageChange(){
    if(startBL)
        if(!ui->labelInput->text().isEmpty())
            emit siGetWord(ui->labelInput->text().at(0));
}

void RigimeFileClass::slKeyPressEvent (QKeyEvent *event){

    if(!destroyedBL){
        if(startBL){
            if(event->key() != 16777220){ // 16777220 - Enter
                if(!event->text().isEmpty())
                    centralAdministration(event->text().at(0));
            }
            else{
                stopPrint();
            }
        }
        else{
            if(event->key() == Qt::Key_Space){
                startPrint();
            }
        }
    }
}

void RigimeFileClass::slKeyReleaseEvent(QKeyEvent *event){

    if(!destroyedBL)
        if(event->key() == Qt::Key_Shift)
            if(!ui->labelInput->text().isEmpty())
                emit siGetWord(ui->labelInput->text().at(0));
}

void RigimeFileClass::startPrint(){

    startBL = true;
    ui->labelInput->setText(workerText);
    ui->labelStart->close();

    if(!ui->labelInput->text().isEmpty())
        emit siGetWord(ui->labelInput->text().at(0));

    calculateCorrectly = 0;
    calculateError = 0;

    ////////////////////////////////////////////
    ui->labelInput->setMaximumWidth(saveSizeLabelInputAndShow.width()/2);
    ui->labelInput->setMinimumWidth(10);
    ui->labelShow->setMaximumWidth(saveSizeLabelInputAndShow.width()/2);
    ui->labelShow->setMinimumWidth(10);
    ////////////////////////////////////////////

    calculateTime->start();
}

void RigimeFileClass::stopPrint(){

    emit stopLesson();
    startBL = false;
    ui->labelInput->clear();
    ui->labelShow->clear();

    ////////////////////////////////////////////
    ui->labelInput->setMaximumWidth(0);
    ui->labelInput->setMinimumWidth(0);
    ui->labelShow->setMaximumWidth(0);
    ui->labelShow->setMinimumWidth(0);
    ////////////////////////////////////////////

    ui->labelStart->show();

    uiDialog->inputCorrectly->setText(QString::number(calculateCorrectly,10));
    uiDialog->inputError->setText(QString::number(calculateError,10));
    uiDialog->inputTime->setText(QString::number((calculateTime->elapsed()/1000.0)));
    uiDialog->inputSign->setText(QString::number((calculateCorrectly/(calculateTime->elapsed()/1000.0))*60.0));

    dialog->exec();
}

void RigimeFileClass::centralAdministration(QChar inputWord){

    if(!ui->labelInput->text().isEmpty()){
        if(ui->labelInput->text().at(0) == inputWord)
        {
            ui->labelShow->setText(ui->labelShow->text() + QString(inputWord));
            ui->labelInput->setText(ui->labelInput->text().right(ui->labelInput->text().size() - 1));

            if(ui->labelInput->text().isEmpty()){
                stopPrint();
            }
            else
                emit siGetWord(ui->labelInput->text().at(0));

            calculateCorrectly++;
        }
        else
        {
            labelSetStyleSheetError();
            calculateError++;
            emit siGetWord(ui->labelInput->text().at(0));
        }
    }
    else
    {
        stopPrint();
    }
}

void RigimeFileClass::labelSetStyleSheetDefault(){
    ui->labelInput->setStyleSheet("border-color: black; border-width: 2px 2px 2px 0px;");
    ui->labelShow->setStyleSheet("border-color: black; border-width: 2px 0px 2px 2px;");
}

void RigimeFileClass::labelSetStyleSheetError(){

    ui->labelInput->setStyleSheet("border-color: red; border-width: 3px 3px 3px 0px;");
    ui->labelShow->setStyleSheet("border-color: red; border-width: 3px 0px 3px 3px;");

    QTimer::singleShot(200, this, SLOT(labelSetStyleSheetDefault()));
}

RigimeFileClass::~RigimeFileClass(){
    delete ui;
}

QWidget * RigimeFileClass::getWidget() {

    menuBar = new QMenuBar();
    widget = new QWidget();
    destroyedBL = false;
    ui = new Ui::RegimeFile;

    ui->setupUi(widget);

    for(int i = 0; i<listMenu.size(); i++){
        if(i == 2)
            menuBar->addMenu(menuRegimeFile);
        menuBar->addMenu(listMenu.at(i));
    }

    ui->gridLayout->setMenuBar(menuBar);

    ////////////////////////////////////////////
    ui->labelStart->setMaximumSize(saveSizeLabelInputAndShow);
    ui->labelStart->setMinimumSize(0,0);

    ui->labelInput->setMaximumWidth(0);
    ui->labelInput->setMinimumWidth(0);
    ui->labelShow->setMaximumWidth(0);
    ui->labelShow->setMinimumWidth(0);
    ////////////////////////////////////////////

    connect(widget,SIGNAL(destroyed()),this,SLOT(destroyedWidget()));
    disconnect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    return widget;
}

void RigimeFileClass::destroyedWidget(){
    emit stopLesson();
    startBL = false;
    destroyedBL = true;
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
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

void RigimeFileClass::setWorkerText(QString workerTextTemp) {
    workerText = workerTextTemp;
    ui->labelInput->setText(workerText);
    ui->labelShow->clear();
}
