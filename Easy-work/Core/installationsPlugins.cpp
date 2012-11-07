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

//-- Интерфейсы плагинов --//
#include "CoreWidget_global.h"
#include "RegimeFile_global.h"
#include "Keyboard_global.h"
#include "Style_global.h"
#include "what_is_global.h"
//-------------------------//

#include <QPluginLoader>
#include <QMenu>
#include <QDir>

void Core::loadPlugins(QString pathPlugin) {

    #ifdef Q_OS_WIN32
        QString enlargement = ".dll";  // Для Windows
        QString prefix = "";
    #endif

    #ifdef Q_OS_LINUX
        QString enlargement = ".so";   // Для Linux
        QString prefix = "lib";
    #endif

    QStringList readPluginsName;
    readPluginsName << "CoreWidget";
    readPluginsName << "Keyboard";
    readPluginsName << "RegimeFile";
    readPluginsName << "Style";
    readPluginsName << "what_is";

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

                if (CoreWidget * plugin = qobject_cast<CoreWidget *>(obj))
                {
                    installationsCoreWidget(plugin);
                }
                else if(Keyboard * plugin = qobject_cast<Keyboard *>(obj))
                {
                    if(plugin->loadPlugins(pathPlugin))
                        installationsKeyboard(plugin);
                }
                else if(RigimeFile * plugin = qobject_cast<RigimeFile *>(obj))
                {
                    if(plugin->loadPlugins(pathPlugin))
                        installationsRigimeFile(plugin);
                }
                else if(Style * plugin = qobject_cast<Style *>(obj))
                {
                    installationsStyle(plugin);
                }
                else if (WhatIs * plugin = qobject_cast<WhatIs *>(obj))
                {
                    installationsWhatIs(plugin);
                }
            }
        }
        else{
            controlLoadPlugin(readPluginsName.at(i));
        }
    }

    coreWidget->activationRegime();

    if(loadKeyboard)
    keyboard->show();
}

// Знагрузка найденных плагинов:
void Core::installationsCoreWidget(CoreWidget * plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    coreWidget = plugin;
    coreWidget->setMenuBar(coreMenu);
    connect(coreWidget,SIGNAL(siGetWidget(QWidget*)),this,SLOT(slSetCentralWidget(QWidget*)));
}

void Core::installationsKeyboard(Keyboard *plugin) {
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    loadKeyboard = true;
    keyboard = plugin;
    setting->addMenu(plugin->getMenu());

    connect(this,SIGNAL(siCloseEvent(QCloseEvent*)),plugin,SLOT(slCloseEvent()));
    connect(this,SIGNAL(siKeyReleaseEvent(QKeyEvent*)),plugin,SLOT(slKeyReleaseEvent(QKeyEvent*)));
    connect(this,SIGNAL(siFocusInEvent(QFocusEvent*)),plugin,SLOT(slFocusInEvent(QFocusEvent*)));
    connect(this,SIGNAL(siKeyPressEvent(QKeyEvent*)),plugin,SLOT(slKeyPressEvent(QKeyEvent*)));
    connect(this,SIGNAL(siMoveEvent(QMoveEvent*)),plugin,SLOT(slMoveEvent(QMoveEvent*)));
    connect(this,SIGNAL(siResizeEvent(QResizeEvent*)),plugin,SLOT(slResizeEvent(QResizeEvent*)));
}

void Core::installationsRigimeFile(RigimeFile * plugin){

    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    plugin->setMenuBar(coreMenu);
    coreWidget->setRegimeMenu(plugin->getActionRegime(), plugin->getIcon());

    connect(plugin,SIGNAL(siGetWidget(QWidget*)),this,SLOT(slSetCentralWidget(QWidget*)));
    connect(this,SIGNAL(siKeyPressEvent(QKeyEvent*)),plugin,SLOT(slKeyPressEvent(QKeyEvent*)));
    connect(this,SIGNAL(siKeyReleaseEvent(QKeyEvent*)),plugin,SLOT(slKeyReleaseEvent(QKeyEvent*)));
    connect(this,SIGNAL(siResizeEvent(QResizeEvent*)),plugin,SLOT(slResizeEvent(QResizeEvent*)));

    if(loadKeyboard){
        connect(plugin,SIGNAL(siGetWord(QChar)),keyboard,SLOT(slAnimatePressWord(QChar)));
        connect(keyboard,SIGNAL(siKeyboardLanguageChange()),plugin,SLOT(slKeyboardLanguageChange()));
        connect(plugin,SIGNAL(stopLesson()),keyboard,SLOT(pressDownOffAllKey()));
    }
}

void Core::installationsWhatIs(WhatIs * plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    help->addAction(plugin->getAction());
}

void Core::installationsStyle(Style *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();

    this->setStyleSheet(plugin->getStyleSheet());
    setting->addMenu(plugin->createZipStyle());

    connect(plugin,SIGNAL(getStyle(QString)),this,SLOT(setStyleSheet(QString)));
    connect(this,SIGNAL(siCloseEvent(QCloseEvent*)),plugin,SLOT(slCloseEvent()));

    if(loadKeyboard){
        keyboard->setStyleSheet(this->styleSheet());
        connect(plugin,SIGNAL(getStyle(QString)),keyboard,SLOT(setStyleSheet(QString)));
    }
}
