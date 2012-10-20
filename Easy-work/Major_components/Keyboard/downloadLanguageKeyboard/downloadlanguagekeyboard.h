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

#ifndef DOWNLOADLANGUAGEKEYBOARD_H
#define DOWNLOADLANGUAGEKEYBOARD_H

#include "downloadLanguageKeyboard_global.h"

#include <QHash>
#include <QStringList>
#include <QMenu>

class KeyboardLanguageClass : public KeyboardLanguage
{
    Q_OBJECT Q_INTERFACES(KeyboardLanguage)

public:
    KeyboardLanguageClass();
    virtual ~KeyboardLanguageClass() {}

    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Keyboard Language"; }
    virtual QMenu* getMenu()        { return menuLanguage; }

private:
    QString pathDir;
    QHash < QString, QStringList> hashLanguage;
    QList <QAction*> actionsLanguage;
    QString rememberActionActive;
    QMenu *menuLanguage;

private slots:
    void slotActivateLanguage();

signals:
    void getLanguage(QStringList);
};


#endif // DOWNLOADLANGUAGEKEYBOARD_H
