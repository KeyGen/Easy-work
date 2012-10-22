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

        setQPoinParent(saveMoveMainWindowPoint);
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

void KeyboardClass::setKeyLanguage(QMultiHash<QString, QString> getListLanguage,bool pressShift)
{

    if(listLanguage!=getListLanguage)
        listLanguage = getListLanguage;

    QList<QPushButton *> allPButtons = ui->gridWidget->findChildren<QPushButton *>();

    if(!allPButtons.isEmpty())
    {
        for(int i = 0; i<allPButtons.size(); i++)
        {
            QMultiHash <QString,QString>::iterator it = getListLanguage.find(allPButtons.at(i)->objectName());

            for(; it != getListLanguage.end(); ++it)
            {
                if(pressShift) // ? & ????
                {++it; ++it;}

                ///////////////////
                listUiPushButton.insertMulti(it.value().toInt(),allPButtons.at(i));
                ////////////////////

                ++it;

                if(it.value()=="&")
                    allPButtons.at(i)->setText(it.value()+"&");
                else
                    allPButtons.at(i)->setText(it.value());

                break;
            }
        }
    }
    else
        qDebug() << "no child";
}

void KeyboardClass::pressKeyboard(QKeyEvent* event,bool state)
{
    qDebug() << event->key();

    if(event->key() == 16777248 /*shift*/)
        if(state)
        {
            ui->Shift_left->animateClick(99999999);
            ui->Shift_right->animateClick(99999999);

            bool pressShift = true;
            this->setKeyLanguage(listLanguage,pressShift);
        }
        else
        {
            bool pressShift = false;
            this->setKeyLanguage(listLanguage,pressShift);

            ui->Shift_left->animateClick(0);
            ui->Shift_right->animateClick(0);
        }

    else if(event->key() == 16777252 /*Caps Lock*/) // нужна проверка Caps Lock из системы
        if(state)
        {
            ui->Caps_Lock->animateClick(99999999);
        }
        else
        {
            ui->Caps_Lock->animateClick(0);
        }

    else if(event->key() == 16777220 /*Enter*/)
        if(state)
        {
            ui->Enter->animateClick(99999999);
        }
        else
        {
            ui->Enter->animateClick(0);
        }

    else if(event->key() == 16777249 /*Ctrl*/)
        if(state)
        {
            ui->Ctrl_left->animateClick(99999999);
            ui->Ctrl_right->animateClick(99999999);
        }
        else
        {
            ui->Ctrl_left->animateClick(0);
            ui->Ctrl_right->animateClick(0);
        }

    else if(event->key() == 16777251 /*Alt*/)
        if(state)
        {
            ui->Alt_left->animateClick(99999999);
            ui->Alt_right->animateClick(99999999);
        }
        else
        {
            ui->Alt_left->animateClick(0);
            ui->Alt_right->animateClick(0);
        }

    else if(event->key() == 16777250 /*Win*/)
        if(state)
        {
            ui->Win->animateClick(99999999);
        }
        else
        {
            ui->Win->animateClick(0);
        }

    else if(event->key() == 16777301 /*Menu*/)
        if(state)
        {
            ui->Menu->animateClick(99999999);
        }
        else
        {
            ui->Menu->animateClick(0);
        }

    else if(event->key() == 16777219 /*Backspace*/)
        if(state)
        {
            ui->Backspace->animateClick(99999999);
        }
        else
        {
            ui->Backspace->animateClick(0);
        }

    else if(event->key() == 16777217 /*Tab*/)
        if(state)
        {
            ui->Tab->animateClick(99999999);
        }
        else
        {
            ui->Tab->animateClick(0);
        }

    else if(event->key() == 32 /*Space*/) // нужна проверка Caps Lock из системы
        if(state)
        {
            ui->Space->animateClick(99999999);
        }
        else
        {
            ui->Space->animateClick(0);
        }

    else
    {
        QHash<int,QPushButton*>::iterator it = listUiPushButton.find(event->key());

        for(;it!=listUiPushButton.end(); it++)
        {
            if(state)
            {
                it.value()->animateClick(99999999);
            }
            else
            {
                it.value()->animateClick(0);
            }
            break;
        }
    }
}
