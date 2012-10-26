#ifndef CORE_H
#define CORE_H

#include <QtGui/QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
class CoreWidget;
class RigimeFile;
class Keyboard;
class QMenuBar;
QT_END_NAMESPACE

class Core : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Core(QWidget *parent = 0);
    ~Core();

    virtual void keyPressEvent (QKeyEvent *event);
    virtual void focusInEvent ( QFocusEvent * event )  ;

private:
    void loadPlugins(const QString dir);
    void installationsCoreWidget(CoreWidget * plugin);
    void installationsRigimeFile(RigimeFile * plugin);
    void installationsKeyboard(Keyboard *plugin);

    void installationsCoreMenu();
    void moveWindowCenter();

private:
    QString pathPlugin;
    QList <QMenu *> coreMenu;
    QMenu *menu;
    QMenu *regime;
    QMenu *learner;
    QMenu *setting;
    QMenu *help;

private slots:
    void slSetCentralWidget(QWidget *);
};

#endif // CORE_H
