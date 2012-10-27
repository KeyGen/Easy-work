#include "keyboard.h"

#include <QKeyEvent>
#include <QResizeEvent>
#include <QMoveEvent>
#include <QCloseEvent>
#include <QFocusEvent>

#include <QDialog>
#include <QRegExp>
#include <QAction>

void KeyboardClass::slKeyPressEvent  (QKeyEvent *event){

    if(event->text().contains(QRegExp("(\\w+)|" // Буквы
                                      "([~`!@#$%^&*()_+-={}|\\]\\\\:\\[\";\',./<>?])|" // English
                                      "([№])" // Russian
                                      )))
    {
        if(!examinationKeyboardLanguage())
        setDownWordAndSymbolKey(event->text(), true);
    }
    else
        setDownControlKey(event, true);
}

void KeyboardClass::slKeyReleaseEvent(QKeyEvent *event){

    if(event->text().contains(QRegExp("(\\w+)|" // Буквы
                                      "([~`!@#$%^&*()_+-={}|\\]\\\\:\\[\";\',./<>?])|" // English
                                      "([№])" // Russian
                                      )))
    {
        if(!examinationKeyboardLanguage())
        setDownWordAndSymbolKey(event->text(), false);
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

void KeyboardClass::slCloseEvent     (QCloseEvent * event){
    qDebug() << event;
    dialog->close();
}

void KeyboardClass::slFocusInEvent   (QFocusEvent * event){

    event->gotFocus();

    if(examinationKeyboardLanguage())
        if(!findAndSetKeyboardLanguage())
            qDebug() << "Раскладка не найдена";
}
