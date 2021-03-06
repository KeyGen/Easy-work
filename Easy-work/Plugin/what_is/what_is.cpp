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

#include "what_is.h"
#include "ui_ui_whatIs.h"

#include <QDesktopWidget>
#include <QDialog>
#include <QAction>

Q_EXPORT_PLUGIN(WhatIsClass)

WhatIsClass::WhatIsClass() : ui(new Ui::Dialog) {

    dialog = new QDialog();
    ui->setupUi(dialog);
    action = new QAction(tr("О программе"),this);

    moveWindowCenter();

    connect(action,SIGNAL(triggered()),dialog,SLOT(exec()));
}

WhatIsClass::~WhatIsClass(){
}

void WhatIsClass::exec()
{
    dialog->exec();
}

void WhatIsClass::moveWindowCenter(){
    // Запустим программу по центру экрана
    QDesktopWidget *desktop = QApplication::desktop();  // Определяем разрешение экрана
    dialog->move((desktop->width()-dialog->width())/2,(desktop->height()-dialog->height())/2); // Распологаем MainWindow в ценре
}

QAction* WhatIsClass::getAction()
{
    return action;
}

void WhatIsClass::renameAction(QString str)
{
    action->setText(str);
}

// Всего строк 5890, актуальных 4000, 52x21 файлов
