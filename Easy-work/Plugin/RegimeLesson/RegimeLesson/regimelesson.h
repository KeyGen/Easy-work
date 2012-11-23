#ifndef REGIMELESSON_H
#define REGIMELESSON_H

#include "RegimeLesson_global.h"

#include <QDebug>

class RegimeLessonClass : public RegimeLesson
{
    Q_OBJECT Q_INTERFACES(RegimeLesson)

public:
    RegimeLessonClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Regime Lesson"; }
    virtual QWidget* getWidget();
    virtual void setMenuBar(QList <QMenu *>);
    virtual QAction * getActionRegime() { return startRegime; }
    virtual const QIcon getIcon();

    virtual ~RegimeLessonClass() {}

signals:
    void siGetWidget(QWidget *);
    void siSaveSetting(QStringList);

private:
    QAction *startRegime;
    QList <QMenu *> listMenu;
    bool destroyedBL;

private:
    void saveSetting();
public slots:
    void slSetSaveSetting(QStringList);
    void slCloseEvent();

private slots:
    void slGetWidget();
};

#endif // REGIMELESSON_H
