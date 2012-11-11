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

#include "core.h"

void Core::saveSetting(){

    QStringList listSaveSettings;
    listSaveSettings << "Core";

    listSaveSettings << QString::number(QMainWindow::width());
    listSaveSettings << QString::number(QMainWindow::height());

    emit siSaveSetting(listSaveSettings);
}

void Core::slSetSaveSetting(QStringList setValue){

    if(!setValue.isEmpty()){
        if(setValue.at(0) == "Core"){
            QMainWindow::resize(setValue.at(1).toInt(),setValue.at(2).toInt());
        }
    }
}