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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>


///
#include <QMoveEvent>

namespace Ui {
class MainWindow;
}

QT_BEGIN_NAMESPACE
// Интерфейсы
class WhatIs;
class StyleCSS;
class RegimeFile;
class Keyboard;
//
class QDialog;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void moveWindowCenter();

private:
    Ui::MainWindow *ui;
    QString pathDir;
    virtual void moveEvent ( QMoveEvent * event );
    virtual void closeEvent ( QCloseEvent * );
    virtual void resizeEvent ( QResizeEvent * event );

private:
    // Функции для загрузки прагинов
    // Главная
    void loadPlugins(const QString dirPlugins);
    // Знагрузка найденных плагинов:
    // WhatIs класс создает окно с инфо о программе
    void installationsWhatIs(WhatIs *);
    // StyleCSS класс осуществляет загрузку стилий
    void installationsStyleCSS(StyleCSS *);
    // RegimeFile класс режима файла (печать слепым метод. внешнего файла)
    void installationsRegimeFile(RegimeFile *);
    // Keyborad класс клавиатуры отображение клавиш
    void installationsKeyboard(Keyboard *);
    QList <Keyboard *> keyboard;

signals:
    void traceMoveWindow(QPoint);
    void traceSizeWindow(QSize);
    void rejected();
};

#endif // MAINWINDOW_H
