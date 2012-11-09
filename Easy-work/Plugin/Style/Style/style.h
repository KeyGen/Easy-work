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

#ifndef STYLE_H
#define STYLE_H

#include "Style_global.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class StyleClass : public Style
{
    Q_OBJECT Q_INTERFACES(Style)

public:
    StyleClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Style"; }
    virtual QString getStyleSheet() { return readStyleSheet(); }

    virtual QMenu * createZipStyle(QString path = "Style/");

    virtual ~StyleClass();

private:
    QString readStyleSheet(QString path = ":/standart.style");
    QString findStyleName(QByteArray, QString language = "name_ru");
    void getStyleForName(QString, QString path = "Style/");
    void removeTempFolderPath();

private:
    QMenu *menu;
    QList <QAction*> listAction;
    QString tempFolderPath;
    QString saveNaemStile;

private slots:
    void slotActivateCSS();
    void saveSetting();

public slots:
    virtual void slCloseEvent ();
    void slSetSaveSetting(QStringList);

signals:
    void getStyle(QString);
    void siSaveSetting(QStringList);
};

#endif // STYLE_H
