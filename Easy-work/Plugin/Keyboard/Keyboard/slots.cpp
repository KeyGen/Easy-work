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

#include <QKeyEvent>
#include <QResizeEvent>
#include <QMoveEvent>
#include <QFocusEvent>

#include <QDialog>
#include <QAction>

void KeyboardClass::slAnimatePressWord (QChar ch){
    if(!examinationKeyboardLanguage())
        findKeyAndPress(QString(ch));
}

void KeyboardClass::slKeyPressEvent  (QKeyEvent *event){

    if(!examinationKeyboardLanguage()){
        if(!setDownWordAndSymbolKey(event->text(), true))
            setDownControlKey(event, true);
    }
    else
            setDownControlKey(event, true);

}

void KeyboardClass::slKeyReleaseEvent(QKeyEvent *event){

    if(!examinationKeyboardLanguage()){
        if(!setDownWordAndSymbolKey(event->text(), false))
            setDownControlKey(event, false);
    }
    else
            setDownControlKey(event, false);
}

void KeyboardClass::slResizeEvent    (QResizeEvent * event){

    saveSizeMainWindow = event->size();

    saveSizeMainWindow.setHeight(saveSizeMainWindow.height()+20);

    slMoveEvent(true);
}

void KeyboardClass::slMoveEvent      (QMoveEvent * event){

    savePointMianWindow = event->pos();

    if(move_yes_no->isChecked()) {
        dialog->move(event->pos().x()+(saveSizeMainWindow.width()-dialog->width())/2,
                     event->pos().y()+saveSizeMainWindow.height());
    }
}

void KeyboardClass::slMoveEvent(bool BL) {

    if(BL) {
        if(move_yes_no->isChecked()) {
            dialog->move(savePointMianWindow.x()+(saveSizeMainWindow.width()-dialog->width())/2,
                         savePointMianWindow.y()+saveSizeMainWindow.height());
        }
    }
}

void KeyboardClass::slCloseEvent (){
    disconnect(dialog,SIGNAL(rejected()),this,SLOT(setBLShow()));
    dialog->close();
    saveSetting();
}

void KeyboardClass::slFocusInEvent   (QFocusEvent * event){

    event->gotFocus();

    if(examinationKeyboardLanguage())
        if(!findAndSetKeyboardLanguage())
            qDebug() << "Раскладка не найдена";
}

void KeyboardClass::slShow(){
    dialog->setVisible(true);
}

void KeyboardClass::slHide(){
    dialog->setVisible(false);
}
