#include "keyboard.h"
#include "ui_keyboard.h"
#include "FindKeyboardLayout_global.h"

#include <QMenu>
#include <QDialog>
#include <QKeyEvent>
#include <QApplication>

Q_EXPORT_PLUGIN(KeyboardClass);

KeyboardClass::KeyboardClass() : ui(new Ui::DialogKeyboard)
{
    menu = new QMenu(tr("Клавиатура"));

    pathPlugin = "../Plugin/Keyboard/readyPlugins";

    loadPlugins(pathPlugin);

    showKeyboard = new QAction(tr("Включить"),this);
    move_yes_no = new QAction(tr("Прикрепить"),this);
    move_yes_no->setCheckable(true);
    move_yes_no->setChecked(true);

    menu->addAction(move_yes_no);
    menu->addAction(showKeyboard);

    pressShift = false;

    dialog = new QDialog;
    ui->setupUi(dialog);
    dialog->setWindowFlags(Qt::Widget);

    connect(showKeyboard,SIGNAL(triggered()),dialog,SLOT(show()));
    connect(move_yes_no,SIGNAL(triggered(bool)),this,SLOT(slMoveEvent(bool)));
    //connect(ui->Shift_left,SIGNAL(pressed()),this,SLOT(setKeyboardLanguage()));
}

bool KeyboardClass::findAndSetKeyboardLanguage(){

    saveLanguageKeboard = sistemsKeyboardLanguage();
    hashLanguage = keyboardLayout->readerZipKeyboardLayout(saveLanguageKeboard);

    setKeyboardLanguage();

    languageBL = false;

    return true;
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
    else if(event->key() == Qt::Key_Shift)
        {ui->Shift_left->setDown(BL); ui->Shift_right->setDown(BL); pressShift = BL; setKeyboardLanguage();}
    else if(event->key() == Qt::Key_CapsLock)
        ui->Caps_Lock->setDown(BL);
    else if(event->key() == Qt::Key_Control)
        {ui->Ctrl_left->setDown(BL); ui->Ctrl_right->setDown(BL);}
    else if(event->key() == Qt::Key_Menu)
        ui->Menu->setDown(BL);
    else if(event->key() == Qt::Key_Meta)
        ui->Win->setDown(BL);
    else if(event->key() == 16777220)
        ui->Enter->setDown(BL);
    else if(event->key() == -1) {
        languageBL = true;
        ui->Shift_left->setDown(BL);
        ui->Shift_right->setDown(BL);
        ui->Alt_left->setDown(BL);
        ui->Alt_right->setDown(BL);
    }

    if(ui->Shift_left->isDown()&&ui->Ctrl_left->isDown()) {
        languageBL = true;
    }

    if(languageBL)
        if(!(ui->Shift_left->isDown())&&!(ui->Alt_left->isDown())|!(ui->Shift_left->isDown())&&!(ui->Ctrl_left->isDown()))
            if(examinationKeyboardLanguage())
                if(!findAndSetKeyboardLanguage())
                    qDebug() << "Раскладка не найдена";
}

void KeyboardClass::setDownWordAndSymbolKey(QString ch, bool BL)
{
    QList<QPushButton *> allPButtons = ui->gridWidget->findChildren<QPushButton *>();

    for(int i = 0; i<allPButtons.size(); i++)
        if(allPButtons.at(i)->text() == ch)
        {allPButtons.at(i)->setDown(BL); break;}
}

KeyboardClass::~KeyboardClass(){
    delete ui;
}

QString KeyboardClass::sistemsKeyboardLanguage(){
    return QApplication::keyboardInputLocale().bcp47Name();
}
