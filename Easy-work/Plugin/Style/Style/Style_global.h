#ifndef STYLE_GLOBAL_H
#define STYLE_GLOBAL_H

#include <QtPlugin>

//QT_BEGIN_NAMESPACE

//QT_END_NAMESPACE

class Style : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QString getStyleSheet() = 0;

    virtual ~Style() {}

signals:
    virtual void getStyle(QString) = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(Style, "Style/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE

#endif // STYLE_GLOBAL_H
