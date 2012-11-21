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

#include "update.h"
#include "ui_update_dialog.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

#include <QProgressDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QTimer>
#include <QAction>
#include <QDate>
#include <QFile>
#include <QDir>

Q_EXPORT_PLUGIN(UpdateClass)

UpdateClass::UpdateClass(): ui(new Ui::UpdateDialog)
{
    dialogUpdate = new QDialog;
    ui->setupUi(dialogUpdate);

    showDialogSettings = new QAction(tr("Обновление"),this);
    connect(showDialogSettings,SIGNAL(triggered()),this,SLOT(dialogExec()));

    updateOneDay = tr("Каждый день");
    updateOneWeek = tr("Раз в неделю");
    updateOneMonth = tr("Раз в месяц");

    QStringList examinationDate;
    examinationDate << updateOneDay;
    examinationDate << updateOneWeek;
    examinationDate << updateOneMonth;

    ui->comboBoxTime->addItems(examinationDate);
    ui->updateOn->setChecked(true);

    connect(ui->updateOn,SIGNAL(toggled(bool)),ui->groupBox,SLOT(setEnabled(bool)));
    connect(ui->save,SIGNAL(clicked()),this,SLOT(dialogSave()));
    connect(ui->close,SIGNAL(clicked()),this,SLOT(dialogNotSave()));
    connect(dialogUpdate,SIGNAL(rejected()),this,SLOT(dialogNotSave()));
    connect(ui->examinationUpdate,SIGNAL(clicked()),this,SLOT(slBoolCheckForUpdates()));
    connect(ui->examinationUpdate,SIGNAL(clicked()),this,SLOT(slCheckForUpdates()));

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));

    clickCheckForUpdates = false;
    boolSlCheckForUpdates = true;
    downloadDisk = false;
    setPath();

    progress = new QProgressDialog();
    progress->setWindowTitle(tr("Обновление"));
}
void UpdateClass::downloadProgress(qint64 change,qint64 size){

    if(progress->maximum() != size){
        disconnect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
        boolSlCheckForUpdates = false;
        progress->setMaximum(size);
        progress->setLabelText(tr("\n\nЗагрузка обновлений.\n\nРазмер: ") + QString::number((int)size/1000) + " kb.");
        connect(progress,SIGNAL(canceled()),this,SLOT(stopDownload()));
        connect(progress,SIGNAL(rejected()),this,SLOT(stopDownload()));
        connect(progress,SIGNAL(canceled()),progress,SLOT(close()));
        connect(progress,SIGNAL(rejected()),progress,SLOT(close()));
        progress->exec();
    }
    if(progress->isVisible())
    progress->setValue(change);
}

void UpdateClass::stopDownload(){
    disconnect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(downloadProgress(qint64,qint64)));
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    reply->abort();
    boolSlCheckForUpdates = true;
}

void UpdateClass::slBoolCheckForUpdates(){
    clickCheckForUpdates = true;
}

void UpdateClass::setPath(QString pathHttpF, QString pathTempF){
    pathHttp = pathHttpF;
    pathTemp = pathTempF;
}

void UpdateClass::dialogNotSave(){

    if(!dateSaveDialog.isEmpty()){
        if(!saveDialog){
            ui->updateOff->setChecked(dateSaveDialog.at(0).toInt());
            ui->updateOn->setChecked(dateSaveDialog.at(1).toInt());
            ui->comboBoxTime->setCurrentIndex(ui->comboBoxTime->findText(dateSaveDialog.at(2)));
        }
        saveDialog = false;
        dateSaveDialog.clear();
        dialogUpdate->close();
    }
}

void UpdateClass::dialogSave(){
    saveDialog = true;
    dialogUpdate->close();
}

void UpdateClass::dialogExec(){

    dateSaveDialog << QString::number((int)ui->updateOff->isChecked());
    dateSaveDialog << QString::number((int)ui->updateOn->isChecked());
    dateSaveDialog << ui->comboBoxTime->currentText();

    dialogUpdate->exec();
}

void UpdateClass::slCheckForUpdates(){
    {
        if(boolSlCheckForUpdates)
            checkForUpdates();
        boolSlCheckForUpdates = false;
    }
}

void UpdateClass::checkForUpdates(){
    manager->get(QNetworkRequest(QUrl(pathHttp)));
}

void UpdateClass::replyFinished(QNetworkReply* networkReply){

    if(networkReply->size()){
        if(WriteFile(networkReply)){
            QString newVersion = findVersion(ReadFile());

            if(ui->showObtainableVersion->text() != newVersion)
                ui->showObtainableVersion->setText(newVersion);
            if(ui->showInstallVersion->text() != newVersion){
                updateEasyWork();
            }
            else{
                if(clickCheckForUpdates){
                    QMessageBox msgBox;
                    msgBox.setWindowTitle(tr("Информация"));
                    msgBox.setIcon(QMessageBox::Information);
                    msgBox.setText(tr("Установлена последняя версия"));
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                }
                writeDate();
                clickCheckForUpdates = false;
                boolSlCheckForUpdates = true;
            }
        }
    }
}

void UpdateClass::updateEasyWork(){
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Обновления"));
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText(tr("Доступна новая версия. Обновить сейчас?"));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    if(msgBox.exec() == MessageYes){
        disconnect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
        connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedFile(QNetworkReply*)));
        reply = manager->get(QNetworkRequest(QUrl(pathHttp + "/" + fileName)));
        connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(downloadProgress(qint64,qint64)));
    }
    else{
        boolSlCheckForUpdates = true;
        writeDate();
    }
}
void UpdateClass::replyFinishedFile(QNetworkReply* networkReply){

    if(networkReply->size()){
        connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
        disconnect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedFile(QNetworkReply*)));

        if(progress->maximum() == networkReply->size()){

            if(!downloadDisk){
                QFile file(pathTemp + "/" + fileName);
                if(file.open(QIODevice::WriteOnly)){
                    file.write(networkReply->readAll());
                    file.close();
                }
                else{
                    qDebug() << tr("Проблема с правами доступа? update.cpp 148");
                }
            }
            else{

                QFile file(pathTemp + "/" + updateDisk.first());
                if(file.open(QIODevice::WriteOnly)){
                    file.write(networkReply->readAll());
                    file.close();
                    updateDisk.removeOne(updateDisk.first());
                }
                else{
                    qDebug() << tr("Проблема с правами доступа? update.cpp 148");
                }
            }

                if(updateDisk.isEmpty()){
                    progress->close();
                    ui->save->click();
                    emit siUdate(pathTemp + "/" + fileName);
                    writeDate();
                    emit closeApplication();
                    downloadDisk = false;
                }
                else{
                    downloadDisk = true;
                    reply = manager->get(QNetworkRequest(QUrl(pathHttp + "/" + updateDisk.first())));
                    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedFile(QNetworkReply*)));
                    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(downloadProgress(qint64,qint64)));
                }
        }

        progress->setMaximum(0);
    }
}

QString UpdateClass::findVersion(QString html){

    QString versionRutracker;

    #ifdef Q_OS_WIN32
        QString findKeyFileName = "Скачать для Windows: <A HREF=\"";
        QString findKeyVersion = "_v";
        QChar stopChar = 'e';
        QString findPak = "disk";

        int tempIndex = 0;
        for(int i = 0; i<html.size(); i++){
            if(html.indexOf(findPak,i) == -1)
                break;

            if(tempIndex != html.indexOf(findPak,i)){
                tempIndex = html.indexOf(findPak,i);
                QString disk;
                for(int i = tempIndex; html.at(i) != '<'&&html.at(i) != '\"'; i++){
                    disk += html.at(i);
                }

                if(!updateDisk.contains(disk)){
                    updateDisk << disk;
                }
            }
        }

    #endif

    #ifdef Q_OS_LINUX
        QString findKeyFileName = "Скачать для Linux: <A HREF=\"";
        QString findKeyVersion = "rk_";
        QChar stopChar = '_';
    #endif

    for(int i =html.indexOf(findKeyFileName,Qt::CaseInsensitive); html.at(i)!='>'; i++)
        versionRutracker += html.at(i);

    versionRutracker.chop(1);

    fileName = versionRutracker.right(versionRutracker.size()-findKeyFileName.size());
    versionRutracker.clear();

    qDebug() << tr("Найден файл:") << fileName;
    qDebug() << tr("Дополнительые файлы:") << updateDisk;

    for(int i = fileName.indexOf(findKeyVersion)+findKeyVersion.size(); fileName.at(i) != stopChar; i++)
        versionRutracker += fileName.at(i);

    #ifdef Q_OS_WIN32
        versionRutracker.chop(1);
    #endif

    qDebug() << tr("Найдена версия:") << versionRutracker;
    return versionRutracker;
}

bool UpdateClass::WriteFile(QNetworkReply * networkReply){

    QFile file(pathTemp + "/temp");
    if(file.open(QIODevice::WriteOnly)){
        file.write(networkReply->readAll());
        file.close();
        return true;
    }
    else{
        qDebug() << tr("Проблема с правами доступа? update.cpp 124");
        return false;
    }
}

QString UpdateClass::ReadFile(QString newCodec){

    QString readFileStr;
    QFile read_file(pathTemp + "/temp");

    if(read_file.open(QIODevice::ReadOnly))
    {
        QTextStream out(&read_file);
        out.setCodec(newCodec.toAscii());
        readFileStr = out.readAll();

        read_file.close();

        QDir dir;
        dir.remove(pathTemp + "/temp");

        return readFileStr;
    }
    else
        qDebug() << tr("Проблема с правами доступа? update.cpp 124");

    return "";
}

void UpdateClass::StartCheckForUpdates(QString dateUpdate){

    if(ui->updateOn->isChecked()){
        if(dateUpdate.isEmpty()){
            QTimer::singleShot(2000, this, SLOT(slCheckForUpdates()));
        }
        else{
            QStringList listDate = dateUpdate.split(".");
            QDate dateSistem;
            QDate dateUpdateD(listDate.at(0).toInt(),listDate.at(1).toInt(),listDate.at(2).toInt());

            if(ui->comboBoxTime->currentText() == updateOneDay){
                if(dateSistem.currentDate().day()>dateUpdateD.day())
                    QTimer::singleShot(2000, this, SLOT(slCheckForUpdates()));
            }
            else if(ui->comboBoxTime->currentText() == updateOneWeek){
                if(dateSistem.currentDate().weekNumber()>dateUpdateD.weekNumber())
                    QTimer::singleShot(2000, this, SLOT(slCheckForUpdates()));
            }
            else if(ui->comboBoxTime->currentText() == updateOneMonth){
                if(dateSistem.currentDate().month()>dateUpdateD.month())
                    QTimer::singleShot(2000, this, SLOT(slCheckForUpdates()));
            }
        }
    }
}

void UpdateClass::writeDate(){
    QDate dateSistem;
    dateUpdate = dateSistem.currentDate().toString("yyyy.MM.dd");
}
