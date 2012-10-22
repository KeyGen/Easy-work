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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Установки переменных
    pathDir = "../../readyPlugins";

    ui->setupUi(this);

    moveWindowCenter();

    loadPlugins(pathDir); // installationPlugin.cpp


    ui->inputText->setFixedWidth(400);
    ui->showText->setFixedWidth(400);
    ui->progressBar->setFixedWidth(800);

}

void MainWindow::keyPressEvent ( QKeyEvent * event )
{
    bool keyPress = true;
    emit tracePressKeyboard(event,keyPress);
}

void MainWindow::keyReleaseEvent ( QKeyEvent * event )
{
    bool keyRelease = false;
    emit tracePressKeyboard(event,keyRelease);
}

void MainWindow::resizeEvent ( QResizeEvent * event )
{
    emit traceSizeWindow(event->size());
}

void MainWindow::closeEvent ( QCloseEvent * )
{
    emit rejected();
}

void MainWindow::moveEvent ( QMoveEvent * event )
{
    emit traceMoveWindow(event->pos());
}

void MainWindow::moveWindowCenter(){

    // Запустим программу по центру экрана
    QDesktopWidget *desktop = QApplication::desktop();  // Определяем разрешение экрана
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2-100); // Распологаем MainWindow в ценре
}

MainWindow::~MainWindow()
{
    delete ui;
}
