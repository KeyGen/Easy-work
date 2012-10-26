#ifndef KEYBOARD_GLOBAL_H
#define KEYBOARD_GLOBAL_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QMenu;
QT_END_NAMESPACE

class Keyboard : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QMenu* getMenu()        = 0;

    virtual ~Keyboard() {}
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(Keyboard, "Keyboard/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // KEYBOARD_GLOBAL_H
