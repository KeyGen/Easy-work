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

#ifndef DOWNLOADLANGUAGEKEYBOARD_GLOBAL_H
#define DOWNLOADLANGUAGEKEYBOARD_GLOBAL_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QStringList;
class QMenu;
QT_END_NAMESPACE

class KeyboardLanguage : public QObject
{

public:

    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QMenu* getMenu()        = 0;

    virtual ~KeyboardLanguage() {}

private slots:
    virtual void slotActivateLanguage() = 0;

signals:
    virtual void getLanguage(QStringList) = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(KeyboardLanguage, "keyboard.language.for.keyboardPlugin.programm/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // DOWNLOADLANGUAGEKEYBOARD_GLOBAL_H
