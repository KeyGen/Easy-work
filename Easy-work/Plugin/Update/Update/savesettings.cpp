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

void UpdateClass::saveSetting(){

    QStringList listSaveSettings;
    listSaveSettings << "Update";

    listSaveSettings << QString::number((int)ui->updateOff->isChecked());
    listSaveSettings << QString::number((int)ui->updateOn->isChecked());
    listSaveSettings << ui->comboBoxTime->currentText();
    listSaveSettings << ui->showInstallVersion->text();
    listSaveSettings << ui->showObtainableVersion->text();

    emit siSaveSetting(listSaveSettings);
}

void UpdateClass::slSetSaveSetting(QStringList setValue){

    if(!setValue.isEmpty()){
        if(setValue.at(0) == "Update"){
            ui->updateOff->setChecked(setValue.at(1).toInt());
            ui->updateOn->setChecked(setValue.at(2).toInt());
            ui->comboBoxTime->setCurrentIndex(ui->comboBoxTime->findText(setValue.at(3)));
            ui->showInstallVersion->setText(setValue.at(4));
            ui->showObtainableVersion->setText(setValue.at(5));
        }
    }
}

void UpdateClass::slCloseEvent(){
    saveSetting();
}
