#ifndef FINDKEYBOARDLAYOUT_H
#define FINDKEYBOARDLAYOUT_H

#include "FindKeyboardLayout_global.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class FindKeyboardLayoutClass : public FindKeyboardLayout
{
    Q_OBJECT Q_INTERFACES(FindKeyboardLayout)

public:
    FindKeyboardLayoutClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Plugin Keyboard - Find keyboard layout"; }
    virtual QMenu* getMenu()        { return menu; }

    virtual ~FindKeyboardLayoutClass() {}

private:
    QMenu *menu;
    QList <QAction*> listActionLanguage;
    QMultiHash <QString, QString> hashLanguage;

public:
    QMultiHash <QString, QString> readerZipKeyboardLayout(QString, QString);

private:
    QMultiHash <QString, QString> returnStandartLanguage();
    QMultiHash <QString, QString> createLanguageHash(QByteArray);
    QString getStrObjectName(QString);
    QString getNoShift(QString);
    QString getShift(QString);
};

#endif // FINDKEYBOARDLAYOUT_H
