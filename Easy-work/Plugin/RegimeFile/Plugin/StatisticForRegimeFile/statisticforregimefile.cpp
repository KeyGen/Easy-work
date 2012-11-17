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

#include "statisticforregimefile.h"
#include "ui_statisticDialog.h"

#include <QTableWidgetItem>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QAction>
#include <QDialog>
#include <QDir>

Q_EXPORT_PLUGIN(StatisticForRegimeFileClass)

StatisticForRegimeFileClass::StatisticForRegimeFileClass() : ui(new Ui::statisticDialog)
{
    dialogStatistic = new QDialog;
    ui->setupUi(dialogStatistic);

    createMDB = createConnection();

    showStatistic = new QAction(tr("Статистика"),this);
    connect(showStatistic,SIGNAL(triggered()),this,SLOT(exec()));
    connect(ui->deleteStatistic,SIGNAL(clicked()),this,SLOT(deleteStatistic()));
    connect(ui->deleteAllStatistic,SIGNAL(clicked()),this,SLOT(deleteStatisticAll()));
}

bool StatisticForRegimeFileClass::createConnection(QString path, QString name)
{
    pathMDB = path;
    nameMDB = name;

    QDir dir(pathMDB);

    if(!dir.exists()){
        QDir create;
        create.mkpath(pathMDB);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path + "/" + name);

    db.setUserName("user");

    if (!db.open()) {
        QMessageBox::critical(0, tr("Cannot open database"),
            tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;
    QString   str  = "CREATE TABLE statistic ( "
            "date_time  VARCHAR(20), "
            "error VARCHAR(10), "
            "print VARCHAR(10), "
            "time  VARCHAR(20), "
            "value VARCHAR(10)      "
            ");";

    if (!query.exec(str)) {
        ;//qDebug() << "Unable to create a table";
    }

    return true;
}

void StatisticForRegimeFileClass::readMDB(){

    bool openBL = true;

    QSqlQuery query;
    if (!query.exec("SELECT * FROM statistic;")) {
        qDebug() << "Unable to execute query - exiting";
        openBL = false;
    }

    if(openBL){
        //Reading of the data
        QSqlRecord rec     = query.record();

        QStringList readDateTime;
        QStringList readError;
        QStringList readPrint;
        QStringList readTime;
        QStringList readValue;

        while (query.next()) {
            readDateTime << query.value(rec.indexOf("date_time")).toString();
            readError << query.value(rec.indexOf("error")).toString();
            readPrint << query.value(rec.indexOf("print")).toString();
            readTime << query.value(rec.indexOf("time")).toString();
            readValue << query.value(rec.indexOf("value")).toString();
        }

        QHash<QString, QStringList> hashValue;

        hashValue.insert("date_time",readDateTime);
        hashValue.insert("error",readError);
        hashValue.insert("print",readPrint);
        hashValue.insert("time",readTime);
        hashValue.insert("value",readValue);

        createTableVerticalHeader(hashValue);
    }
}

void StatisticForRegimeFileClass::createTableVerticalHeader(QHash<QString,QStringList> hashValue){

    QStringList readDateTime = hashValue.take("date_time");

    if(!readDateTime.isEmpty()){
        ui->tableWidget->setRowCount(readDateTime.size());
        ui->tableWidget->setVerticalHeaderLabels(readDateTime);

        connect(ui->tableWidget->verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(setActiveItemWidget(int)));

        QTableWidgetItem* ptwi = 0;
        QStringList key;
        key << "error";
        key << "print";
        key << "time";
        key << "value";

        for (int i = 0; i < key.size(); ++i){
            QStringList readValueHash = hashValue.value(key.at(i));
            for (int j = 0; j < readDateTime.size(); ++j){
                ptwi = new QTableWidgetItem(readValueHash.at(j));
                ui->tableWidget->setItem(j, i, ptwi);
            }
        }
    }
}

void StatisticForRegimeFileClass::insertMDB(QStringList value){

    if(value.size() == 5){
        bool openBL = true;

        QSqlQuery query;
        if (!query.exec("SELECT * FROM statistic;")) {
            qDebug() << "Unable to execute query - exiting";
            openBL = false;
        }

        if(openBL){

            //Adding some information
            QString str;
            QString strF =
                    "INSERT INTO  statistic (date_time, error, print, time, value) "
                    "VALUES('%1', '%2', '%3', '%4', '%5');";

            str = strF.arg(value.at(0))
                        .arg(value.at(1))
                             .arg(value.at(2))
                                  .arg(value.at(3))
                                       .arg(value.at(4));

            if (!query.exec(str)) {
                qDebug() << "Unable to do insert opeation";
            }
        }
    }
}
