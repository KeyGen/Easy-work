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

#include "keyboard.h"
#include <QDialog>

void KeyboardClass::saveSetting(){

    QStringList listSaveSettings;
    listSaveSettings << "Keyboard";

    listSaveSettings << QString::number(dialog->width());
    listSaveSettings << QString::number(dialog->height());
    listSaveSettings << QString::number((int)BLShowDialog);

    emit siSaveSetting(listSaveSettings);
}

void KeyboardClass::slSetSaveSetting(QStringList setValue){

    if(!setValue.isEmpty()){
        if(setValue.at(0) == "Keyboard"){
            dialog->resize(setValue.at(1).toInt(),setValue.at(2).toInt());
            BLShowDialog = setValue.at(3).toInt();
        }
    }

    if(BLShowDialog)
    show();
}
