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

#ifndef UPDATE_GLOBAL_H
#define UPDATE_GLOBAL_H

#include <QStringList>
#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class Update : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QAction *getAction()    = 0;

    virtual ~Update() {}

public slots:
    virtual void slSetSaveSetting(QStringList) = 0;
    virtual void slCloseEvent()                = 0;
signals:
    virtual void siSaveSetting(QStringList)    = 0;
    virtual void siUdate(QString)              = 0;
    virtual void closeApplication()            = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(Update, "Update/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // UPDATE_GLOBAL_H
