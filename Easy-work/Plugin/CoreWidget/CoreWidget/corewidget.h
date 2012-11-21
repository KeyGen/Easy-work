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

#ifndef COREWIDGET_H
#define COREWIDGET_H

#include "CoreWidget_global.h"
#include <QIcon>

#include <QDebug>

QT_BEGIN_NAMESPACE
class QAction;
class QPushButton;
class QDeclarativeView;
QT_END_NAMESPACE

namespace Ui {
class CoreForm;
}

class CoreWidgetClass : public CoreWidget
{
    Q_OBJECT Q_INTERFACES(CoreWidget)

public:
    CoreWidgetClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Core Widget"; }
    virtual QWidget * getWidget();
    virtual void setMenuBar(QList <QMenu *>);
    virtual void activationRegime();

    virtual void setRegimeMenu(QAction *, const QIcon);

    ~CoreWidgetClass() {}

public slots:
    void slResizeEvent (QResizeEvent * event);
    void createConnection(QString path = "../share/EasyWork/Database", QString name = "serverUpdate.mdb");

private:
    QWidget *widget;
    QMenuBar *menuBar;
    QAction *startRegime;
    Ui::CoreForm *ui;
    QList <QMenu *> listMenu;

    QDeclarativeView *ui_d;               // Qml
    QObject *Root;                      // Корневой элемент QML модели

    QList <QIcon > listIconRegime;
    QList <QAction *> listActionRegime;
    QHash <QString,QPixmap> resourceMainWindow;

    bool destroyedBL;

    qint64 controlSize;

private:
    void createRegimeMenu();
    QRegion setRoundedCorners(int width, int height, int,int,int,int);
    void readDB();

private slots:
    void slGetWidget();
    void destroyedWidget();

signals:
    void siGetWidget(QWidget *);
};

#endif // COREWIDGET_H
