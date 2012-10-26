#include "keyboard.h"
#include "ui_keyboard.h"

#include <QMenu>
#include <QDialog>

Q_EXPORT_PLUGIN(KeyboardClass);

KeyboardClass::KeyboardClass() : ui(new Ui::DialogKeyboard)
{
    menu = new QMenu(tr("Клавиатура"));
    showKeyboard = new QAction(tr("Включить"),this);
    menu->addAction(showKeyboard);

    dialog = new QDialog;
    ui->setupUi(dialog);
    dialog->setWindowFlags(Qt::Widget);

    connect(showKeyboard,SIGNAL(triggered()),dialog,SLOT(show()));
}

KeyboardClass::~KeyboardClass(){
    delete ui;
}
