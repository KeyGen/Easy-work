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

#include "update.h"
#include "ui_update_dialog.h"

#include <QAction>

Q_EXPORT_PLUGIN(UpdateClass)

UpdateClass::UpdateClass(): ui(new Ui::UpdateDialog)
{
    dialogUpdate = new QDialog;
    ui->setupUi(dialogUpdate);

    showDialogSettings = new QAction(tr("Обновление"),this);
    connect(showDialogSettings,SIGNAL(triggered()),this,SLOT(dialogExec()));

    QString updateOneDay = tr("Каждый день");
    QString updateOneWeek = tr("Раз в неделю");
    QString updateOneMonth = tr("Раз в месяц");

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
