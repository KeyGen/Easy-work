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

#include "Keyboard_global.h"

#include <QSize>
#include <QPoint>

#include <QDebug>

QT_BEGIN_NAMESPACE
class QDialog;
class QAction;
class QSize;
class FindKeyboardLayout; // Plugin
QT_END_NAMESPACE

namespace Ui {
class DialogKeyboard;
}

class KeyboardClass : public Keyboard
{
    Q_OBJECT Q_INTERFACES(Keyboard)

public:
    KeyboardClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Keyboard"; }
    virtual QMenu* getMenu()        { return menu; }
    virtual QStringList getLoadPlugin() { return listLoadPlugin; }

    virtual ~KeyboardClass();

private:
    QMenu *menu;
    QAction *showKeyboard;
    QAction *move_yes_no;
    Ui::DialogKeyboard *ui;
    QDialog *dialog;
    QSize saveSizeMainWindow;
    QPoint savePointMianWindow;
    QString saveLanguageKeboard;
    QString pathPlugin;
    bool languageBL;
    bool pressShift;
    QMultiHash <QString,QString> hashLanguage;
    FindKeyboardLayout *keyboardLayout;
    QStringList listLoadPlugin;
    QString findKey;

private:
    void setDownControlKey(QKeyEvent *event, bool);
    bool setDownWordAndSymbolKey(QString, bool);
    bool examinationKeyboardLanguage();
    bool findAndSetKeyboardLanguage();
    QString sistemsKeyboardLanguage();
    void loadPlugins(const QString dir);
    void findKeyAndPress(QString);

private slots:
    void slMoveEvent(bool);
    void setKeyboardLanguage();
    void findKeyAndPressTimer();

public slots:
    virtual void slKeyPressEvent  (QKeyEvent *event);
    virtual void slKeyReleaseEvent(QKeyEvent *event);
    virtual void slResizeEvent    (QResizeEvent * event);
    virtual void slMoveEvent      (QMoveEvent * event);
    virtual void slCloseEvent     ();
    virtual void slFocusInEvent   (QFocusEvent * event);
    virtual void slAnimatePressWord (QChar);
    virtual void pressDownOffAllKey();
    virtual void show();
    void setStyleSheet(QString);

signals:
    void siKeyboardLanguageChange();
};

#endif // KEYBOARD_H
