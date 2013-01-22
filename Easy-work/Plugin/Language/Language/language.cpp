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

#include "language.h"
#include <QAction>
#include <QMenu>

Q_EXPORT_PLUGIN(LanguageClass)

LanguageClass::LanguageClass(){
    saveLanguageActive = 1;
    setMenu();
}

void LanguageClass::setMenu(){

    menuLanguage = new QMenu(tr("Язык приложения"));

    listLanguage << new QAction(tr("Английский"),this);
    listLanguage << new QAction(tr("Русский"),this);

    for(int i = 0; i<listLanguage.size(); i++){
        listLanguage.at(i)->setCheckable(true);
        connect(listLanguage.at(i),SIGNAL(triggered()),this,SLOT(clickAction()));
    }

    menuLanguage->addActions(listLanguage);

    listLanguage.at(saveLanguageActive)->setChecked(true);
}

void LanguageClass::clickAction(){
    listLanguage.at(saveLanguageActive)->setChecked(false);
    for(int i = 0; i<listLanguage.size(); i++){
        if(listLanguage.at(i)->isChecked()){
            qDebug() << "Выбран язык:" << listLanguage.at(i)->text();
            saveLanguageActive = i;
            break;
        }
    }
}
