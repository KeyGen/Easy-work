#include "regimelesson.h"

#include <QAction>
#include <QMenu>

Q_EXPORT_PLUGIN(RegimeLessonClass)

RegimeLessonClass::RegimeLessonClass(){

    destroyedBL = true;
    startRegime = new QAction(tr("Режим урока"),this);
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

}

QWidget* RegimeLessonClass::getWidget(){

}

void RegimeLessonClass::slGetWidget(){
    qDebug() << "start";
    emit siGetWidget(getWidget());
}

void RegimeLessonClass::setMenuBar(QList <QMenu *> bar)
{
    listMenu = bar;

    if(!listMenu.isEmpty())
    {
        listMenu.at(1)->addAction(startRegime);
    }
}

const QIcon RegimeLessonClass::getIcon(){
    const QIcon *ico = new QIcon(":/iconLesson");
    return *ico;
}
