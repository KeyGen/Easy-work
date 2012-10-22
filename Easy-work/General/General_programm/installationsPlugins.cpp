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

#include "mainwindow.h"
#include "ui_mainwindow.h"

// Интерфейсы плагинов
#include "what_is_global.h"
#include "style_css_global.h"
#include "regime_outward_file_global.h"
#include "keyboard_global.h"
//

#include <QPluginLoader>
#include <QDir>

void MainWindow::loadPlugins(const QString dir) {

    const QDir pluginsDir(dir);

    QStringList filter;
    filter << "*.so";   // Для Linux
    filter << "*.dll";  // Для Windows

    foreach (QString fileName, pluginsDir.entryList(filter, QDir::Files))
    {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));

        if (loader.isLoaded())
        {
            qDebug() << QString("%1: %2 %3.").arg("Plugin file").arg(fileName).arg(QObject::tr("is already loaded"));
            continue;
        }

        if (loader.load() == false)
        {
            qDebug() << QString("%1 %2\n%3: %4").arg(QObject::tr("Can't load a plugin"))
                .arg(fileName).arg(QObject::tr("error"))
                .arg(loader.errorString());
        }
        else
        {
            QObject * obj = loader.instance();

            if (WhatIs * plugin = qobject_cast<WhatIs *>(obj))
            {
                installationsWhatIs(plugin);
            }
            else if(Keyboard *pluginKeyboard = qobject_cast<Keyboard *>(obj))
            {
                installationsKeyboard(pluginKeyboard);
            }
            else if(StyleCSS *pluginCSS = qobject_cast<StyleCSS *>(obj))
            {
                installationsStyleCSS(pluginCSS);
            }
            else if(RegimeFile *pluginRFile = qobject_cast<RegimeFile *>(obj))
            {
                installationsRegimeFile(pluginRFile);
            }

        }
    }
}


// Знагрузка найденных плагинов:
// WhatIs класс создает окно с инфо о программе
void MainWindow::installationsWhatIs(WhatIs * plugin){

    ui->help->addAction(plugin->getAction());
}

// StyleCSS класс осуществляет загрузку стилий
void MainWindow::installationsStyleCSS(StyleCSS * plugin){

    ui->setting->addMenu(plugin->getMenu());

    connect(plugin,SIGNAL(getStyle(QString)),this,SLOT(setStyleSheet(QString)));

    if(!keyboard.isEmpty()){
        connect(plugin,SIGNAL(getStyle(QString)),keyboard.at(0),SLOT(setStyleSheet(QString)));
        keyboard.at(0)->setStyleSheet(plugin->getStandardStyleSheet());
    }

    this->setStyleSheet(plugin->getStandardStyleSheet());
}

// RegimeFile класс режима файла (печать слепым метод. внешнего файла)
void MainWindow::installationsRegimeFile(RegimeFile * plugin){

    ui->regime->addAction(plugin->getActions());
}

// Keyborad класс клавиатуры отображение клавиш
void MainWindow::installationsKeyboard(Keyboard * plugin){

    ui->setting->addMenu(plugin->getMenu());

    keyboard << plugin;

    connect(this,SIGNAL(rejected()),plugin,SLOT(close()));
    connect(this,SIGNAL(traceMoveWindow(QPoint)),plugin,SLOT(setQPoinParent(QPoint)));
    connect(this,SIGNAL(traceSizeWindow(QSize)),plugin,SLOT(setQSizeParent(QSize)));
    connect(this,SIGNAL(tracePressKeyboard(QKeyEvent*,bool)),plugin,SLOT(pressKeyboard(QKeyEvent*,bool)));
}
