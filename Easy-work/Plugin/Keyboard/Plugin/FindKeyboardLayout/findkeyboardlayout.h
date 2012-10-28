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

#ifndef FINDKEYBOARDLAYOUT_H
#define FINDKEYBOARDLAYOUT_H

#include "FindKeyboardLayout_global.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class FindKeyboardLayoutClass : public FindKeyboardLayout
{
    Q_OBJECT Q_INTERFACES(FindKeyboardLayout)

public:
    FindKeyboardLayoutClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Plugin Keyboard - Find keyboard layout"; }

    virtual ~FindKeyboardLayoutClass() {}

private:
    QMenu *menu;
    QList <QAction*> listActionLanguage;
    QMultiHash <QString, QString> hashLanguage;

public:
    QMultiHash <QString, QString> readerZipKeyboardLayout(QString, QString);
    QMenu* createLanguageMenu(QString path = "../Plugin/Keyboard/KeyboardLayout/");

private:
    QMultiHash <QString, QString> returnStandartLanguage();
    QMultiHash <QString, QString> createLanguageHash(QByteArray);
    QString getStrObjectName(QString);
    QString getNoShift(QString);
    QString getShift(QString);
    QString findNameLanguage(QByteArray);

signals:
    void getWindowsTitle(QString);
};

#endif // FINDKEYBOARDLAYOUT_H
