#ifndef STYLE_CSS_H
#define STYLE_CSS_H

#include "style_css_global.h"
#include <QMap>

class StyleCSSclass : public StyleCSS
{
    Q_OBJECT Q_INTERFACES(StyleCSS)

public:
    StyleCSSclass();

    virtual QString getVersion()            { return "1.0"; }
    virtual QString getName()               { return "Style CSS"; }
    virtual QList <QAction*> getActions()   { return actionsNameCSS; }

    virtual ~StyleCSSclass()                {}

signals:
    virtual void getStyle(QString);

private:
    QList <QAction*> actionsNameCSS;
    QMap <QString, QString> downloadCSS;
    QString strDir;

private slots:
    void slotActivateCSS(bool);

};

#endif // STYLE_CSS_H
