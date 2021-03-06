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

#ifndef SAVESETTING_GLOBAL_H
#define SAVESETTING_GLOBAL_H

#include <QStringList>
#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class SaveSetting : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QAction * getAction()   = 0;

    virtual ~SaveSetting() {}

public slots:
    virtual void saveSetting(QStringList)   = 0;
    virtual void setSaveSetting()           = 0;
    virtual void deleteSetting()            = 0;

signals:
    virtual void sisetSaveSetting(QStringList)  = 0;
    virtual void closeApplication()             = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(SaveSetting, "SaveSetting/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // SAVESETTING_GLOBAL_H
