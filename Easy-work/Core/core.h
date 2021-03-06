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

#ifndef CORE_H
#define CORE_H

#include <QtGui/QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
class CoreWidget;
class RigimeFile;
class RegimeLesson;
class RegimeGame;

class Metronome;
class Sound;
class Language;

class Keyboard;
class Style;
class WhatIs;
class SaveSetting;
class Update;
class QMenuBar;
QT_END_NAMESPACE

class Core : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Core(QWidget *parent = 0);
    ~Core();

    virtual void keyPressEvent  (QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void resizeEvent    (QResizeEvent * event);
    virtual void moveEvent      (QMoveEvent * event);
    virtual void closeEvent     (QCloseEvent * event); // Срабатывает когда закрывают окно
    virtual void focusInEvent   (QFocusEvent * event); // Срабатывает когда приложение получает фокус
    virtual void showEvent ( QShowEvent * event );
    virtual void hideEvent ( QHideEvent * event );

private:
    // Путь к плагинам
    void loadPlugins(QString pathPlugin = "../lib/EasyWork");

    void installationsCoreWidget(CoreWidget * plugin);
    void installationsRigimeFile(RigimeFile * plugin);
    void installationsKeyboard(Keyboard *plugin);
    void installationsWhatIs(WhatIs *plugin);
    void installationsStyle(Style *plugin);
    void installationsSaveSetting(SaveSetting *plugin);
    void installationsUpdate(Update *plugin);
    void installationsRegimeLesson(RegimeLesson *plugin);
    void installationsRegimeGame(RegimeGame *plugin);

    void installationsMetronome(Metronome *plugin);
    void installationsSound(Sound *plugin);
    void installationsLanguage(Language *plugin);

    void controlLoadPlugin(QString);
    void installationsCoreMenu();
    void moveWindowCenter();

    void fGoToWebSite(QString site = "https://github.com/KeyGen/Easy-work/wiki");
    void fCommunicateBags(QString site = "https://github.com/KeyGen/Easy-work/issues?page=1&state=open");

    #ifdef Q_OS_WIN32
        void delUpdate(QString pathTempUpdate = "C:/Users/Public/Documents/tempEasyWorkUpdate");
        void delDir(QString pathTempUpdate = "C:/Users/Public/Documents/tempEasyWorkUpdate");
    #endif

    #ifdef Q_OS_LINUX
        void delUpdate(QString pathTempUpdate = "../share/EasyWork/Database");
    #endif

private:
    QList <QMenu *> coreMenu;
    QMenu *menu;
    QMenu *regime;
    QMenu *learner;
    QMenu *setting;
    QMenu *help;

    RegimeLesson *regimeLesson;
    bool loadRegimeLesson;
    RegimeGame *regimeGame;
    bool loadRegimeGame;
    Update *update;
    bool loadUpdate;
    Keyboard *keyboard;
    bool loadKeyboard;
    Style *style;
    bool loadStyle;
    RigimeFile *regimeFile;
    bool loadRegimeFile;
    CoreWidget *coreWidget;

    QString pathUpdate;

private slots:
    void slSetCentralWidget(QWidget *);
    void slSetSaveSetting(QStringList);
    void saveSetting();
    void slGoToWebSite();
    void slCommunicateBags();
    void slUpdateTrue(QString path);

signals:
    void siKeyPressEvent  (QKeyEvent *event);
    void siKeyReleaseEvent(QKeyEvent *event);
    void siResizeEvent    (QResizeEvent * event);
    void siMoveEvent      (QMoveEvent * event);
    void siCloseEvent     (QCloseEvent * event);
    void siFocusInEvent   (QFocusEvent * event);
    void siShowCore();
    void siHideCore();

    void siSaveSetting(QStringList);

};

#endif // CORE_H
