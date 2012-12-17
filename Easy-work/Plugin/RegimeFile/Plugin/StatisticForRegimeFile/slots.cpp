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

#include "statisticforregimefile.h"
#include "ui_statisticDialog.h"
#include <QMessageBox>
#include <QSqlQuery>

#include <QDir>

void StatisticForRegimeFileClass::setValue(QStringList value){

    if(createMDB)
        insertMDB(value);
}

void StatisticForRegimeFileClass::exec(){

    if(createMDB)
        readMDB();

    dialogStatistic->exec();
}

void StatisticForRegimeFileClass::connectDB(){
    createMDB = createConnection();
}

void StatisticForRegimeFileClass::setActiveItemWidget(int clicked){
    activeHeder = clicked;
    ui->deleteStatistic->setEnabled(true);
}

void StatisticForRegimeFileClass::deleteStatisticAll(){

    if(ui->tableWidget->rowCount()){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(tr("Вы уверены что хотите удалить всю базу данных?"));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        if(msgBox.exec() == 16384){

            bool openBL = true;
            QSqlQuery query;
            if (!query.exec("SELECT * FROM statistic;")) {
                qDebug() << "Unable to execute query - exiting";
                openBL = false;
            }

            if(openBL){

                QString strF = "DELETE FROM statistic";

                if (!query.exec(strF)) {
                    qDebug() << "Unable to do delete opeation";
                }
                else{
                    for(int i = ui->tableWidget->rowCount(); i>=0; i--)
                        ui->tableWidget->removeRow(i);
                }
            }
        }
    }
}

void StatisticForRegimeFileClass::deleteStatistic(){

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText(tr("Вы уверены что хотите удалить: ") + ui->tableWidget->verticalHeaderItem(activeHeder)->text() + "?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    if(msgBox.exec() == 16384){

        bool openBL = true;

        QSqlQuery query;
        if (!query.exec("SELECT * FROM statistic;")) {
            qDebug() << "Unable to execute query - exiting";
            openBL = false;
        }

        if(openBL){

            QString strF = "DELETE FROM statistic WHERE value='"
                    + ui->tableWidget->item(activeHeder,ui->tableWidget->columnCount()-1)->text() +
                    "' AND date_time='"
                    + ui->tableWidget->verticalHeaderItem(activeHeder)->text() +
                    "'";

            qDebug() << strF;

            if (!query.exec(strF)) {
                qDebug() << "Unable to do delete opeation";
            }
            else{
                ui->tableWidget->removeRow(activeHeder);
                ui->deleteStatistic->setEnabled(false);
            }
        }
    }
}
