#ifndef STYLE_H
#define STYLE_H

#include "Style_global.h"

#include <QDebug>

class StyleClass : public Style
{
    Q_OBJECT Q_INTERFACES(Style)

public:
    StyleClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Style"; }
    virtual QString getStyleSheet() { return readFile(); }

    virtual ~StyleClass();

private:
    QString readFile(QString path = ":/standart.style");

signals:
    void getStyle(QString);
};

#endif // STYLE_H
