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

#ifndef SAVESETTING_H
#define SAVESETTING_H

#include "SaveSetting_global.h"

QT_BEGIN_NAMESPACE
class QSettings;
QT_END_NAMESPACE

#include <QDebug>

class SaveSettingClass : public SaveSetting
{
    Q_OBJECT Q_INTERFACES(SaveSetting)

public:
    SaveSettingClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Save setting"; }
    virtual QAction * getAction()   { return actionRemoveSetting; }

    virtual ~SaveSettingClass(){}

private:
    QSettings *setting;
    QAction * actionRemoveSetting;
    bool removeSetting;
    enum { MessageNo = 65536, MessageYes = 16384 };

public slots:
    void saveSetting(QStringList);
    void setSaveSetting();
    void deleteSetting();

signals:
    void sisetSaveSetting(QStringList);
    void closeApplication();

};

#endif // SAVESETTING_H
