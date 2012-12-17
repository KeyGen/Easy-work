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

#ifndef REGIMEGAME_H
#define REGIMEGAME_H

#include "RegimeGame_global.h"

#include <QSize>
#include <QDebug>

QT_BEGIN_NAMESPACE
class QMenuBar;
class QDeclarativeView;
QT_END_NAMESPACE

namespace Ui {
class Regime;
}

class RegimeGameClass : public RegimeGame
{
    Q_OBJECT Q_INTERFACES(RegimeGame)

public:
    explicit RegimeGameClass();
    virtual QString getVersion()        { return "1.0"; }
    virtual QString getName()           { return "Regime Game"; }
    virtual QAction * getActionRegime() { return startRegime; }
    virtual QWidget* getWidget();
    virtual void setMenuBar(QList <QMenu *>);
    virtual const QIcon getIcon();
    void saveSetting();

    virtual ~RegimeGameClass() {}

public slots:
    void slSetSaveSetting(QStringList);
    void slCloseEvent ();
    void slResizeEvent (QResizeEvent * event);

private slots:
    void slGetWidget();
    void destroyedWidget();

signals:
    void siSaveSetting(QStringList);
    void siGetWidget(QWidget *);

private:
    QAction *startRegime;
    QList <QMenu *> listMenu;

    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuRegimeGame;
    bool destroyedBL;
    QSize saveSize;
    Ui::Regime *ui;

    QDeclarativeView *ui_d;               // Qml
    QObject *Root;                      // Корневой элемент QML модели
};

#endif // REGIMEGAME_H
