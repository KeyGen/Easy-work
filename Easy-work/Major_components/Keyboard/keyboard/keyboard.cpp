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

#include "keyboard.h"
#include "ui_dialog.h"

#include <QDebug>
#include <QMenu>

Q_EXPORT_PLUGIN(KeyboardClass);


KeyboardClass::KeyboardClass(QWidget * parent) : Keyboard(parent) , ui(new Ui::Dialog)
{
    dialog = new QDialog();
    dialog->setWindowFlags(Qt::Tool);

    ui->setupUi(dialog);

    pathDir = "../../readyPluginsForKeyboard";

    menu = new QMenu(tr("Клавиатура"));
    show_close = new QAction(tr("Включить"),this);
    move_yes_no = new QAction(tr("Прикрепить"),this);

    show_close->setCheckable(true);
    move_yes_no->setCheckable(true);
    move_yes_no->setChecked(true);

    connect(show_close,SIGNAL(triggered(bool)),this,SLOT(show(bool)));
    connect(dialog,SIGNAL(rejected()),this,SLOT(actionCheckFalse()));
    connect(move_yes_no,SIGNAL(triggered()),this,SLOT(fasteningDialog()));

    loadPlugins(pathDir);

    menu->addAction(show_close);
    menu->addAction(move_yes_no);
}

void KeyboardClass::fasteningDialog()
{
    dialog->move(saveMoveMainWindowPoint.x()+(sizeMainWindow.width()-dialog->width())/2,
                 saveMoveMainWindowPoint.y()+sizeMainWindow.height());
}

void KeyboardClass::close() {
    dialog->close();
}

void KeyboardClass::setQSizeParent(QSize size)
{
    if(sizeMainWindow!=size)
    {
        sizeMainWindow = size;
        sizeMainWindow.setHeight(sizeMainWindow.height()+20);
    }

}

void KeyboardClass::setQPoinParent(QPoint point){

    saveMoveMainWindowPoint = point;

    if(move_yes_no->isChecked())
    {
        if(sizeMainWindow.width()>dialog->width()||sizeMainWindow.width()<dialog->width())
            dialog->move(point.x()+(sizeMainWindow.width()-dialog->width())/2,point.y()+sizeMainWindow.height());
        else
            dialog->move(point.x(),point.y()+sizeMainWindow.height());
    }
}

void KeyboardClass::show(bool BL){

    if(BL)
        dialog->show();
    else
        dialog->close();
}

void KeyboardClass::actionCheckFalse()
{
    show_close->setChecked(false);
}

void KeyboardClass::setKeyLanguage(QStringList listLanguage)
{
    qDebug() << listLanguage;
}
