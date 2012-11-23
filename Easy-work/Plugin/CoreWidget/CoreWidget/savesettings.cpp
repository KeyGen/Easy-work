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

void CoreWidgetClass::saveSetting(){

    QStringList listSaveSettings;
    listSaveSettings << "CoreWidget";

    listSaveSettings << QString::number(saveSizeQml.width());
    listSaveSettings << QString::number(saveSizeQml.height());

    emit siSaveSetting(listSaveSettings);
}

void CoreWidgetClass::slSetSaveSetting(QStringList setValue){

    if(!setValue.isEmpty()){
        if(setValue.at(0) == "CoreWidget"){
            if(!setValue.at(1).isEmpty()){
                saveSizeQml.setWidth(setValue.at(1).toInt());
                saveSizeQml.setHeight(setValue.at(2).toInt());
            }
        }
    }
}

void CoreWidgetClass::slCloseEvent(){
    saveSetting();
}
