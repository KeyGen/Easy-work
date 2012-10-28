/**
 * Easy work - writed by KeyGen 2012
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

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

    virtual void keyPressEvent  (QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void resizeEvent    (QResizeEvent * event);
    virtual void moveEvent      (QMoveEvent * event);
    virtual void closeEvent     (QCloseEvent * event); // Срабатывает когда закрывают окно
    virtual void focusInEvent   (QFocusEvent * event); // Срабатывает когда приложение получает фокус

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

    QRegExp coreExpWord;

private slots:
    void slSetCentralWidget(QWidget *);

signals:
    void siKeyPressEvent  (QKeyEvent *event);
    void siKeyReleaseEvent(QKeyEvent *event);
    void siResizeEvent    (QResizeEvent * event);
    void siMoveEvent      (QMoveEvent * event);
    void siCloseEvent     (QCloseEvent * event);
    void siFocusInEvent   (QFocusEvent * event);

};

#endif // CORE_H
