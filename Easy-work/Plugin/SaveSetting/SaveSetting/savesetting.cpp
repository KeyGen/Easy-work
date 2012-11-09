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

#include "savesetting.h"
#include <QMessageBox>
#include <QSettings>
#include <QAction>
#include <QApplication>
#include <QProcess>

Q_EXPORT_PLUGIN(SaveSettingClass)

SaveSettingClass::SaveSettingClass(){

    removeSetting = false;
    setting = new QSettings("KeyGen","Easy-work");
    actionRemoveSetting = new QAction(tr("Настройки по умолчанию"),this);

    connect(actionRemoveSetting,SIGNAL(triggered()),this,SLOT(deleteSetting()));
}

// Сохранение
void SaveSettingClass::saveSetting(QStringList value){

    if(!removeSetting)
        if(!value.isEmpty())
            setting->setValue(value.at(0),value);
}

// Запуск установки настроек
void SaveSettingClass::setSaveSetting(){

    QStringList keySetting = setting->allKeys();

    for(int i = 0; i<keySetting.size(); i++){
        emit sisetSaveSetting(setting->value(keySetting.at(i)).toStringList());
    }

    if(keySetting.isEmpty())
        emit sisetSaveSetting(keySetting);
}

void SaveSettingClass::deleteSetting(){

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText(tr("Вы уверены что хотите удалить все настройки приложения?"));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    if(msgBox.exec() == MessageYes){
        QStringList keySetting = setting->allKeys();

        for(int i = 0; i<keySetting.size(); i++)
            setting->remove(keySetting.at(i));

        removeSetting = true;

        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText(tr("Настройки будут удалены после перезагрузки приложения.\n\nВыполнить это сейчас?"));

        if(msgBox.exec() == MessageYes)
        {
            emit closeApplication();
            QProcess::startDetached(QApplication::applicationFilePath(), QStringList(), QApplication::applicationDirPath());
        }
    }
}
