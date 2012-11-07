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

#ifndef KEYBOARD_GLOBAL_H
#define KEYBOARD_GLOBAL_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QMenu;
class QKeyEvent;
class QResizeEvent;
class QMoveEvent;
class QFocusEvent;
QT_END_NAMESPACE

class Keyboard : public QObject
{

public:
    virtual QString getVersion()        = 0;
    virtual QString getName()           = 0;
    virtual QMenu* getMenu()            = 0;
    virtual bool loadPlugins(QString)   = 0;

    virtual ~Keyboard() {}

public slots:
    virtual void slKeyPressEvent  (QKeyEvent *event)        = 0;
    virtual void slKeyReleaseEvent(QKeyEvent *event)        = 0;
    virtual void slResizeEvent    (QResizeEvent * event)    = 0;
    virtual void slMoveEvent      (QMoveEvent * event)      = 0;
    virtual void slCloseEvent     ()     = 0;
    virtual void slFocusInEvent   (QFocusEvent * event)     = 0;
    virtual void slAnimatePressWord (QChar)                 = 0;
    virtual void pressDownOffAllKey()                       = 0;
    virtual void show()                                     = 0;
    virtual void setStyleSheet(QString)                     = 0;

signals:
    virtual void siKeyboardLanguageChange()                 = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(Keyboard, "Keyboard/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // KEYBOARD_GLOBAL_H
