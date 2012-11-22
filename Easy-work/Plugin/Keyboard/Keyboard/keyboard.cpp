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

#include "keyboard.h"
#include "ui_keyboard.h"
#include "FindKeyboardLayout_global.h"

#include <QMenu>
#include <QTimer>
#include <QDialog>
#include <QKeyEvent>
#include <QApplication>

Q_EXPORT_PLUGIN(KeyboardClass)

KeyboardClass::KeyboardClass() : ui(new Ui::DialogKeyboard)
{

    dialog = new QDialog;
    ui->setupUi(dialog);
    dialog->setWindowFlags(Qt::Tool);

    menu = new QMenu(tr("Клавиатура"));

    showKeyboard = new QAction(tr("Включить"),this);
    move_yes_no = new QAction(tr("Прикрепить"),this);
    move_yes_no->setCheckable(true);
    move_yes_no->setChecked(true);

    menu->addAction(move_yes_no);
    menu->addAction(showKeyboard);

    pressShift = false;
    BLShowDialog = false;
    enteredCapsLock = false;

    connect(showKeyboard,SIGNAL(triggered()),this,SLOT(show()));
    connect(move_yes_no,SIGNAL(triggered(bool)),this,SLOT(slMoveEvent(bool)));
    connect(dialog,SIGNAL(rejected()),this,SLOT(setBLShow()));
    connect(showKeyboard,SIGNAL(triggered()),this,SLOT(setBLShow()));

}

void KeyboardClass::setStyleSheet(QString style){
    dialog->setStyleSheet(style);
}

void KeyboardClass::setBLShow(){
    BLShowDialog = dialog->isVisible();
}

void KeyboardClass::show() {

    if(examinationKeyboardLanguage())
        if(!findAndSetKeyboardLanguage())
            qDebug() << "Раскладка не найдена";

    if(dialog->isMinimized())
    dialog->close();

    dialog->show();
    BLShowDialog = true;
}

void KeyboardClass::slShow(){
    if(BLShowDialog)
    dialog->setVisible(true);
}

void KeyboardClass::slHide(){
    if(BLShowDialog)
    dialog->setVisible(false);
}

bool KeyboardClass::findAndSetKeyboardLanguage(){

    saveLanguageKeboard = sistemsKeyboardLanguage();
    hashLanguage = keyboardLayout->readerZipKeyboardLayout(saveLanguageKeboard);

    enteredCapsLock = false;
    setCapsLock();

    pressDownOffAllKey();

    emit siKeyboardLanguageChange();

    languageBL = false;

    return true;
}

void KeyboardClass::setCapsLock(){

    if(enteredCapsLock != statusCapsLock()){

        QMultiHash<QString,QString>::iterator it = hashLanguage.begin();

        for(; it!=hashLanguage.end(); ++it)
        {
            if(it.value().contains(QRegExp("\\w")))
                if(it.value().contains(QRegExp("\\D")))
                    if(it.value()!="_"){
                        QString shift  = it.value();
                        hashLanguage.find(it.key(),shift).value() = "shift";
                        ++it;
                        QString noShift = it.value();

                        hashLanguage.find(it.key(),noShift).value() = shift;
                        hashLanguage.find(it.key(),"shift").value() = noShift;
                    }
        }
        setKeyboardLanguage();
        enteredCapsLock = statusCapsLock();
    }

    pressDownOffAllKey();
    ui->Caps_Lock->setDown(statusCapsLock());
}

void KeyboardClass::pressDownOffAllKey(){
    QList<QPushButton *> widgets = ui->gridWidget->findChildren<QPushButton *>();
    for(int i = 0; i<widgets.size(); i++) widgets.at(i)->setDown(false);

    pressShift = false;
    setKeyboardLanguage();
    ui->Caps_Lock->setDown(statusCapsLock());
}

void KeyboardClass::findKeyAndPress(QString findKeyTemp){
    findKey = findKeyTemp;
    QTimer::singleShot(200, this, SLOT(findKeyAndPressTimer()));
}

void KeyboardClass::findKeyAndPressTimer(){

    if(findKey != " ")
    {
        QMultiHash <QString,QString>::iterator it = hashLanguage.begin();

        for(int i = 2; it!= hashLanguage.end(); ++it,i++)
        {
            if(it.value() == findKey){

                QList<QPushButton *> widgets = ui->gridWidget->findChildren<QPushButton *>(it.key());

                if(!widgets.isEmpty())
                    widgets.at(0)->setDown(true);

                if(!(i%2)){
                        ui->Shift_left->setDown(true);
                        ui->Shift_right->setDown(true);
                }
            }
        }
    }
    else
        ui->Space->setDown(true);
}

bool KeyboardClass::setDownWordAndSymbolKey(QString ch, bool BL)
{
    QList<QPushButton *> allPButtons = ui->gridWidget->findChildren<QPushButton *>();

    for(int i = 0; i<allPButtons.size(); i++)
        if(allPButtons.at(i)->text() == ch)
        {allPButtons.at(i)->setDown(BL); return true; break;}

    return false;
}

void KeyboardClass::setKeyboardLanguage(){

    QList<QPushButton *> allPButtons = ui->gridWidget->findChildren<QPushButton *>();

    if(!allPButtons.isEmpty())
    {
        for(int i = 0; i<allPButtons.size(); i++)
        {
            QMultiHash <QString,QString>::iterator it = hashLanguage.find(allPButtons.at(i)->objectName());

            for(; it!=hashLanguage.end(); ++it) {

                if(!pressShift)
                        ++it;

                if(it.value() == "&")
                    allPButtons.at(i)->setText("&&");
                else
                allPButtons.at(i)->setText(it.value());

                break;
            }
        }
    }
    else
        qDebug() << "no child";
}

bool KeyboardClass::examinationKeyboardLanguage(){

        return (sistemsKeyboardLanguage() != saveLanguageKeboard);
}

void KeyboardClass::setDownControlKey(QKeyEvent *event, bool BL)
{
    if(event->key() == Qt::Key_Backspace)
        ui->Backspace->setDown(BL);
    else if(event->key() == Qt::Key_Alt)
        {ui->Alt_left->setDown(BL); ui->Alt_right->setDown(BL);}
    else if(event->key() == Qt::Key_Space)
        ui->Space->setDown(BL);
    else if(event->key() == Qt::Key_Tab)
        ui->Tab->setDown(BL);
    else if(event->key() == Qt::Key_Shift){
        ui->Shift_left->setDown(BL); ui->Shift_right->setDown(BL); pressShift = BL; setKeyboardLanguage();
        if(!BL)
            pressDownOffAllKey();
    }
    else if(event->key() == Qt::Key_CapsLock){
            setCapsLock();
        if(examinationKeyboardLanguage())
            if(!findAndSetKeyboardLanguage())
                qDebug() << "Раскладка не найдена";
    }
    else if(event->key() == Qt::Key_Control)
        {ui->Ctrl_left->setDown(BL); ui->Ctrl_right->setDown(BL);}
    else if(event->key() == Qt::Key_Menu)
        ui->Menu->setDown(BL);
    else if(event->key() == Qt::Key_Meta)
        ui->Win->setDown(BL);
    else if(event->key() == Qt::Key_Return)
        ui->Enter->setDown(BL);
    else if(event->key() == -1) {
        languageBL = true;
        ui->Shift_left->setDown(BL);
        ui->Shift_right->setDown(BL);
        ui->Alt_left->setDown(BL);
        ui->Alt_right->setDown(BL);
    }

    if(!(ui->Shift_left->isDown())&&!(ui->Alt_left->isDown())|!(ui->Shift_left->isDown())&&!(ui->Ctrl_left->isDown()))
        if(examinationKeyboardLanguage())
            if(!findAndSetKeyboardLanguage())
                qDebug() << "Раскладка не найдена";
}

KeyboardClass::~KeyboardClass(){
    delete ui;
}
