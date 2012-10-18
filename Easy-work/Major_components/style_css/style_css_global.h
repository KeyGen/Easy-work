#ifndef STYLE_CSS_GLOBAL_H
#define STYLE_CSS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class StyleCSS : public QObject
{

public:
    virtual QString getVersion()    = 0;
    virtual QString getName()       = 0;
    virtual QList <QAction*> getActions()    = 0;

    virtual ~StyleCSS() {}

signals:
    virtual void getStyle(QString) = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(StyleCSS, "style_css.programm/EasyWork/Plagin/1.0.0")

QT_END_NAMESPACE


#endif // STYLE_CSS_GLOBAL_H
