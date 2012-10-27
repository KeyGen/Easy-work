#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Keyboard_global.h"
#include <QSize>
#include <QPoint>

#include <QDebug>

QT_BEGIN_NAMESPACE
class QDialog;
class QAction;
class QSize;
class FindKeyboardLayout; // Plugin
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
    QAction *move_yes_no;
    Ui::DialogKeyboard *ui;
    QDialog *dialog;
    QSize saveSizeMainWindow;
    QPoint savePointMianWindow;
    QString saveLanguageKeboard;
    QString pathPlugin;
    bool languageBL;
    bool pressShift;
    QMultiHash <QString,QString> hashLanguage;

    FindKeyboardLayout *keyboardLayout;

private:
    void setDownControlKey(QKeyEvent *event, bool);
    void setDownWordAndSymbolKey(QString, bool);
    bool examinationKeyboardLanguage();
    bool findAndSetKeyboardLanguage();
    QString sistemsKeyboardLanguage();
    void loadPlugins(const QString dir);

private slots:
    void slMoveEvent(bool);
    void setKeyboardLanguage();

public slots:
    virtual void slKeyPressEvent  (QKeyEvent *event);
    virtual void slKeyReleaseEvent(QKeyEvent *event);
    virtual void slResizeEvent    (QResizeEvent * event);
    virtual void slMoveEvent      (QMoveEvent * event);
    virtual void slCloseEvent     (QCloseEvent * event);
    virtual void slFocusInEvent   (QFocusEvent * event);
};

#endif // KEYBOARD_H
