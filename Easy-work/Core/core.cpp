#include "core.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QMenuBar>
#include <QKeyEvent>

Core::Core(QWidget *parent)
    : QMainWindow(parent)
{
    QMainWindow::setWindowTitle("Easy work v1.0");
    installationsCoreMenu();

    pathPlugin = "../readyPlugins";
    loadPlugins(pathPlugin);
    moveWindowCenter();
}

Core::~Core() {}

void Core::moveWindowCenter(){
    // Запустим программу по центру экрана
    QDesktopWidget *desktop = QApplication::desktop();  // Определяем разрешение экрана
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2-20); // Распологаем MainWindow в ценре
}

void Core::installationsCoreMenu()
{
    menu = new QMenu(tr("Меню"),this);
    regime  = new QMenu(tr("Режимы"),this);
    learner  = new QMenu(tr("Ученики"),this);
    setting = new QMenu(tr("Настройки"),this);
    help = new QMenu(tr("Справка"),this);

    coreMenu << menu;
    coreMenu << regime;
    //coreMenu << learner;
    coreMenu << setting;
    coreMenu << help;

    QAction *exit = new QAction(tr("Выход"),this);
    menu->addAction(exit);
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));

    this->setFocusPolicy(Qt::StrongFocus); // Focus Tab and Click
}

// slots
void Core::slSetCentralWidget(QWidget *widget)
{
    QMainWindow::setWindowTitle(widget->windowTitle());
    this->setCentralWidget(widget);
}

// signals
void Core::keyPressEvent  (QKeyEvent *event){
    emit siKeyPressEvent  (event);
}

void Core::keyReleaseEvent(QKeyEvent * event){
    emit siKeyReleaseEvent(event);
}

void Core::resizeEvent    (QResizeEvent * event){
    emit siResizeEvent(event);
}

void Core::moveEvent      (QMoveEvent * event){
    emit siMoveEvent(event);
}

void Core::closeEvent     (QCloseEvent * event){
    emit siCloseEvent(event);
}

void Core::focusInEvent   (QFocusEvent * event){
    emit siFocusInEvent(event);
}


