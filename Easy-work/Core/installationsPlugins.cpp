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

#include "core.h"

//-- Интерфейсы плагинов --//
#include "CoreWidget_global.h"
#include "RegimeFile_global.h"
#include "Keyboard_global.h"
#include "Style_global.h"
#include "what_is_global.h"
#include "SaveSetting_global.h"
#include "Update_global.h"
#include "RegimeLesson_global.h"
#include "RegimeGame_global.h"
#include "Metronome_global.h"
#include "Sound_global.h"
#include "Language_global.h"
//-------------------------//

#include <QPluginLoader>
#include <QMessageBox>
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
    readPluginsName << "RegimeLesson";
    //readPluginsName << "RegimeGame";
    readPluginsName << "Metronome";
    readPluginsName << "Sound";
    readPluginsName << "Language";
    readPluginsName << "Style";
    readPluginsName << "what_is";
    readPluginsName << "Update";

    // Загружаем последним
    readPluginsName << "SaveSetting";

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
                else if(RegimeLesson * plugin = qobject_cast<RegimeLesson *>(obj))
                {
                    installationsRegimeLesson(plugin);
                }
                else if (RegimeGame* plugin = qobject_cast<RegimeGame *>(obj))
                {
                    installationsRegimeGame(plugin);
                }
                else if(Style * plugin = qobject_cast<Style *>(obj))
                {
                    installationsStyle(plugin);
                }
                else if (WhatIs * plugin = qobject_cast<WhatIs *>(obj))
                {
                    installationsWhatIs(plugin);
                }
                else if (SaveSetting* plugin = qobject_cast<SaveSetting *>(obj))
                {
                    installationsSaveSetting(plugin);
                }
                else if (Update* plugin = qobject_cast<Update *>(obj))
                {
                    installationsUpdate(plugin);
                }
                else if (Metronome* plugin = qobject_cast<Metronome *>(obj))
                {
                    installationsMetronome(plugin);
                }
                else if (Language* plugin = qobject_cast<Language *>(obj))
                {
                    installationsLanguage(plugin);
                }
                else if (Sound* plugin = qobject_cast<Sound *>(obj))
                {
                    installationsSound(plugin);
                }
                else{
                    qDebug() << pathPlugin + "/" + prefix + readPluginsName.at(i) + enlargement;
                }
            }
        }
        else{
            controlLoadPlugin(readPluginsName.at(i));
        }
    }

    coreWidget->activationRegime();
}

void Core::controlLoadPlugin(QString LoadPlugin){

    QStringList listFindPlugin;
    listFindPlugin << "CoreWidget";

    if(listFindPlugin.contains(LoadPlugin)){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(tr("Not found plugin: ") + LoadPlugin + tr("    \nРабота приложения не возможна"));
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.exec();

        QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection); // Завершение приложения
    }
}

// Знагрузка найденных плагинов:
void Core::installationsCoreWidget(CoreWidget * plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    coreWidget = plugin;
    coreWidget->setMenuBar(coreMenu);
    connect(coreWidget,SIGNAL(siGetWidget(QWidget*)),this,SLOT(slSetCentralWidget(QWidget*)));
    connect(this,SIGNAL(siResizeEvent(QResizeEvent*)),plugin,SLOT(slResizeEvent(QResizeEvent*)));
    connect(this,SIGNAL(siCloseEvent(QCloseEvent*)),plugin,SLOT(slCloseEvent()));
    connect(plugin,SIGNAL(siFocus()),this,SLOT(setFocus()));
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
    connect(this,SIGNAL(siShowCore()),plugin,SLOT(slShow()));
    connect(this,SIGNAL(siHideCore()),plugin,SLOT(slHide()));
}

void Core::installationsRigimeFile(RigimeFile * plugin){

    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    loadRegimeFile = true;
    regimeFile = plugin;

    plugin->setMenuBar(coreMenu);
    coreWidget->setRegimeMenu(plugin->getActionRegime(), plugin->getIcon());

    connect(this,SIGNAL(siCloseEvent(QCloseEvent*)),plugin,SLOT(slCloseEvent()));
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

void Core::installationsRegimeLesson(RegimeLesson *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();

    regimeLesson = plugin;
    loadRegimeLesson = true;
    plugin->setMenuBar(coreMenu);
    coreWidget->setRegimeMenu(plugin->getActionRegime(), plugin->getIcon());

    connect(plugin,SIGNAL(siGetWidget(QWidget*)),this,SLOT(slSetCentralWidget(QWidget*)));
    connect(this,SIGNAL(siResizeEvent(QResizeEvent*)),plugin,SLOT(slResizeEvent(QResizeEvent*)));
    connect(this,SIGNAL(siCloseEvent(QCloseEvent*)),plugin,SLOT(slCloseEvent()));
    connect(this,SIGNAL(siKeyPressEvent(QKeyEvent*)),plugin,SLOT(slKeyPressEvent(QKeyEvent*)));

    if(loadKeyboard){
        connect(plugin,SIGNAL(siGetWord(QChar)),keyboard,SLOT(slAnimatePressWord(QChar)));
        connect(keyboard,SIGNAL(siKeyboardLanguageChange()),plugin,SLOT(slKeyboardLanguageChange()));
        connect(plugin,SIGNAL(stopLesson()),keyboard,SLOT(pressDownOffAllKey()));
    }
}

void Core::installationsRegimeGame(RegimeGame *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();

    regimeGame = plugin;
    loadRegimeGame = true;
    plugin->setMenuBar(coreMenu);
    coreWidget->setRegimeMenu(plugin->getActionRegime(), plugin->getIcon());

    connect(plugin,SIGNAL(siGetWidget(QWidget*)),this,SLOT(slSetCentralWidget(QWidget*)));
    connect(this,SIGNAL(siResizeEvent(QResizeEvent*)),plugin,SLOT(slResizeEvent(QResizeEvent*)));
    connect(this,SIGNAL(siCloseEvent(QCloseEvent*)),plugin,SLOT(slCloseEvent()));
    //connect(this,SIGNAL(siKeyPressEvent(QKeyEvent*)),plugin,SLOT(slKeyPressEvent(QKeyEvent*)));

//    if(loadKeyboard){
//        connect(plugin,SIGNAL(siGetWord(QChar)),keyboard,SLOT(slAnimatePressWord(QChar)));
//        connect(keyboard,SIGNAL(siKeyboardLanguageChange()),plugin,SLOT(slKeyboardLanguageChange()));
//        connect(plugin,SIGNAL(stopLesson()),keyboard,SLOT(pressDownOffAllKey()));
//    }
}

void Core::installationsWhatIs(WhatIs * plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    help->addAction(plugin->getAction());
}

void Core::installationsStyle(Style *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();

    style = plugin;
    loadStyle = true;

    this->setStyleSheet(plugin->getStyleSheet());
    setting->addMenu(plugin->createZipStyle());

    connect(plugin,SIGNAL(getStyle(QString)),this,SLOT(setStyleSheet(QString)));
    connect(this,SIGNAL(siCloseEvent(QCloseEvent*)),plugin,SLOT(slCloseEvent()));

    if(loadKeyboard){
        keyboard->setStyleSheet(this->styleSheet());
        connect(plugin,SIGNAL(getStyle(QString)),keyboard,SLOT(setStyleSheet(QString)));
    }
}

void Core::installationsSaveSetting(SaveSetting *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();

    setting->addAction(plugin->getAction());
    connect(this,SIGNAL(siSaveSetting(QStringList)),plugin,SLOT(saveSetting(QStringList)));
    connect(plugin,SIGNAL(sisetSaveSetting(QStringList)),this,SLOT(slSetSaveSetting(QStringList)));
    connect(plugin,SIGNAL(closeApplication()),this,SLOT(close()));

    connect(coreWidget,SIGNAL(siSaveSetting(QStringList)),plugin,SLOT(saveSetting(QStringList)));
    connect(plugin,SIGNAL(sisetSaveSetting(QStringList)),coreWidget,SLOT(slSetSaveSetting(QStringList)));

    if(loadKeyboard){
        connect(keyboard,SIGNAL(siSaveSetting(QStringList)),plugin,SLOT(saveSetting(QStringList)));
        connect(plugin,SIGNAL(sisetSaveSetting(QStringList)),keyboard,SLOT(slSetSaveSetting(QStringList)));
    }

    if(loadStyle){
        connect(style,SIGNAL(siSaveSetting(QStringList)),plugin,SLOT(saveSetting(QStringList)));
        connect(plugin,SIGNAL(sisetSaveSetting(QStringList)),style,SLOT(slSetSaveSetting(QStringList)));
    }

    if(loadUpdate){
        connect(update,SIGNAL(siSaveSetting(QStringList)),plugin,SLOT(saveSetting(QStringList)));
        connect(plugin,SIGNAL(sisetSaveSetting(QStringList)),update,SLOT(slSetSaveSetting(QStringList)));
    }

    if(loadRegimeFile){
        connect(regimeFile,SIGNAL(siSaveSetting(QStringList)),plugin,SLOT(saveSetting(QStringList)));
        connect(plugin,SIGNAL(sisetSaveSetting(QStringList)),regimeFile,SLOT(slSetSaveSetting(QStringList)));
    }

    if(loadRegimeLesson){
        connect(regimeLesson,SIGNAL(siSaveSetting(QStringList)),plugin,SLOT(saveSetting(QStringList)));
        connect(plugin,SIGNAL(sisetSaveSetting(QStringList)),regimeLesson,SLOT(slSetSaveSetting(QStringList)));
    }

    if(loadRegimeGame){
        connect(regimeGame,SIGNAL(siSaveSetting(QStringList)),plugin,SLOT(saveSetting(QStringList)));
        connect(plugin,SIGNAL(sisetSaveSetting(QStringList)),regimeGame,SLOT(slSetSaveSetting(QStringList)));
    }

    plugin->setSaveSetting();
}

void Core::installationsUpdate(Update *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();

    update = plugin;
    loadUpdate = true;

    setting->addAction(plugin->getAction());

    connect(plugin,SIGNAL(closeApplication()),this,SLOT(close()));
    connect(plugin,SIGNAL(siUdate(QString)),this,SLOT(slUpdateTrue(QString)));
    connect(this,SIGNAL(siCloseEvent(QCloseEvent*)),plugin,SLOT(slCloseEvent()));
}

void Core::installationsMetronome(Metronome *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
}

void Core::installationsSound(Sound *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    setting->addMenu(plugin->getMenu());
}

void Core::installationsLanguage(Language *plugin){
    qDebug() << "Load plugin:" << plugin->getName() << plugin->getVersion();
    setting->addMenu(plugin->getMenu());
}
