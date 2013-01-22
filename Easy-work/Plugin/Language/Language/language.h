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

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Language_global.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class LanguageClass : public Language
{
    Q_OBJECT Q_INTERFACES(Language)

public:
    LanguageClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Language"; }
    virtual QMenu *getMenu()        { return menuLanguage;}
    ~LanguageClass(){}

private:
    QMenu *menuLanguage;
    QList <QAction*> listLanguage;
    int saveLanguageActive;

    void setMenu();

private slots:
    void clickAction();
};

#endif // LANGUAGE_H
