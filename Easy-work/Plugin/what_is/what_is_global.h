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

#ifndef WHAT_IS_GLOBAL_H
#define WHAT_IS_GLOBAL_H

#include <QtCore/qglobal.h>

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QDialog;
class QAction;
QT_END_NAMESPACE

class WhatIs : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QAction* getAction()    = 0;
    virtual void renameAction(QString)   = 0;

    virtual ~WhatIs() {}

public slots:
    virtual void exec() = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(WhatIs, "info.programm/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // WHAT_IS_GLOBAL_H
