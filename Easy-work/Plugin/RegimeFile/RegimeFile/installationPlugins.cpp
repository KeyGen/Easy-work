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

#include "regimefile.h"

//-- Интерфейсы плагинов --//
#include "OpenFile_global.h"
#include "StatisticForRegimeFile_global.h"
//-------------------------//

#include <QPluginLoader>
#include <QMessageBox>
#include <QMenu>
#include <QDir>

bool RigimeFileClass::loadPlugins(QString pathPlugin) {

    #ifdef Q_OS_WIN32
        QString enlargement = ".dll";  // Для Windows
        QString prefix = "";
    #endif

    #ifdef Q_OS_LINUX
        QString enlargement = ".so";   // Для Linux
        QString prefix = "lib";
    #endif

    QStringList readPluginsName;
    readPluginsName << "OpenFile";
    readPluginsName << "StatisticForRegimeFile";

    for(int i = 0; i < readPluginsName.size(); i++){
        QDir findPlugin(pathPlugin);

        if(findPlugin.entryList().contains(prefix + readPluginsName.at(i) + enlargement)){
            QPluginLoader loader(pathPlugin + "/" + prefix + readPluginsName.at(i) + enlargement);

            if (loader.isLoaded())
            {
                qDebug() << QString("%1: %2 %3.")
                            .arg("Plugin file")
                            .arg(readPluginsName.at(i))
                            .arg(QObject::tr("is already loaded"));
                continue;
            }

            if (loader.load() == false)
            {
                qDebug() << QString("%1 %2\n%3: %4")
                            .arg(QObject::tr("Can't load a plugin"))
                            .arg(readPluginsName.at(i)).arg(QObject::tr("error"))
                            .arg(loader.errorString());
            }
            else
            {
                QObject * obj = loader.instance();

                if (OpenFile * plugin = qobject_cast<OpenFile *>(obj))
                {
                    openFile = plugin;
                    menuRegimeFile->addAction(plugin->getAction());
                    connect(plugin,SIGNAL(siSetNewText(QString)),this,SLOT(setWorkerText(QString)));
                    connect(plugin,SIGNAL(activatedOpenFile()),this,SLOT(stopPrint()));
                }
                else if (StatisticForRegimeFile * plugin = qobject_cast<StatisticForRegimeFile *>(obj))
                {
                    installationsStatisticForRegimeFile(plugin);
                }
            }
        }
        else{
            return controlLoadPlugin(readPluginsName.at(i));
        }
    }

    return true;
}

bool RigimeFileClass::controlLoadPlugin(QString LoadPlugin){

    QStringList listFindPlugin;

    listFindPlugin << "OpenFile";

    if(listFindPlugin.contains(LoadPlugin)){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(tr("Not found plugin: ") + LoadPlugin + tr("    \nРежим файла не доступен."));
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.exec();
        return false;
    }
    else
        return true;
}

void RigimeFileClass::installationsStatisticForRegimeFile(StatisticForRegimeFile * plugin){

    menuRegimeFile->addAction(plugin->getAction());

    connect(this,SIGNAL(siDBOpen()),plugin,SLOT(connectDB()));
    connect(this,SIGNAL(siGetDateValue(QStringList)),plugin,SLOT(setValue(QStringList)));
}
