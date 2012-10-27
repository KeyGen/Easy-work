#ifndef FINDKEYBOARDLAYOUT_GLOBAL_H
#define FINDKEYBOARDLAYOUT_GLOBAL_H

#include <QtPlugin>
#include <QMultiHash>

QT_BEGIN_NAMESPACE
class QMenu;
QT_END_NAMESPACE

class FindKeyboardLayout : public QObject
{

public:

    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QMenu* getMenu()        = 0;
    virtual QMultiHash <QString, QString> readerZipKeyboardLayout(QString language = "en-US",
                                                                  QString path = "../Plugin/Keyboard/KeyboardLayout/") = 0;

    virtual ~FindKeyboardLayout() {}
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(FindKeyboardLayout, "FindKeyboardLayout/Keyboard/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // FINDKEYBOARDLAYOUT_GLOBAL_H
