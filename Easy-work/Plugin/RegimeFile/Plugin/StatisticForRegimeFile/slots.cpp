#include "statisticforregimefile.h"
#include "ui_statisticDialog.h"
#include <QMessageBox>
#include <QSqlQuery>

//#include <QDialog>
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

            QDir dir(pathMDB);

            if(!dir.entryList().isEmpty()){

                dir.remove(nameMDB);

                for(int i = ui->tableWidget->rowCount(); i>=0; i--)
                    ui->tableWidget->removeRow(i);

                createConnection();
            }
            else
                qDebug() << "Not found dir";
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
