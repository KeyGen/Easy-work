#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Keyboard_global.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
class QDialog;
class QAction;
QT_END_NAMESPACE

namespace Ui {
class DialogKeyboard;
}

class KeyboardClass : public Keyboard
{
    Q_OBJECT Q_INTERFACES(Keyboard)

public:
    KeyboardClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Keyboard"; }
    virtual QMenu* getMenu()        { return menu; }

    virtual ~KeyboardClass();

private:
    QMenu *menu;
    QAction *showKeyboard;
    Ui::DialogKeyboard *ui;
    QDialog *dialog;
};

#endif // KEYBOARD_H
