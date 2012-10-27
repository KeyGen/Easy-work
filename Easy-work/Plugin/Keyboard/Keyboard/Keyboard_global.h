#ifndef KEYBOARD_GLOBAL_H
#define KEYBOARD_GLOBAL_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QMenu;
class QKeyEvent;
class QResizeEvent;
class QMoveEvent;
class QCloseEvent;
class QFocusEvent;
QT_END_NAMESPACE

class Keyboard : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QMenu* getMenu()        = 0;

    virtual ~Keyboard() {}

public slots:
    virtual void slKeyPressEvent  (QKeyEvent *event)        = 0;
    virtual void slKeyReleaseEvent(QKeyEvent *event)        = 0;
    virtual void slResizeEvent    (QResizeEvent * event)    = 0;
    virtual void slMoveEvent      (QMoveEvent * event)      = 0;
    virtual void slCloseEvent     (QCloseEvent * event)     = 0;
    virtual void slFocusInEvent   (QFocusEvent * event)     = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(Keyboard, "Keyboard/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // KEYBOARD_GLOBAL_H
