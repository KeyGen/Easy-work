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

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "keyboard_global.h"

namespace Ui {
class Dialog;
}

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class KeyboardClass : public Keyboard
{
    Q_OBJECT Q_INTERFACES(Keyboard)

public:
    explicit KeyboardClass(QWidget * parent = 0);
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Keyboard"; }
    virtual QMenu* getMenu()        { return menu; }

    virtual ~KeyboardClass()        {}

private:
    Ui::Dialog *ui;
    QDialog *dialog;

    QMenu *menu;
    QAction *show_close;
    QAction *move_yes_no;

    QSize sizeMainWindow;
    QPoint saveMoveMainWindowPoint;

    QString pathDir;

    void loadPlugins(const QString dir);

public slots:
    virtual void setQPoinParent(QPoint);
    virtual void setQSizeParent(QSize);
    virtual void close();
    void fasteningDialog();

private slots:
    void show(bool);
    void actionCheckFalse();
    void setKeyLanguage(QStringList);
};

#endif // KEYBOARD_H
