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

#ifndef REGIMEFILE_H
#define REGIMEFILE_H

#include "RegimeFile_global.h"
#include <QSize>
#include <QDebug>

QT_BEGIN_NAMESPACE
class QAction;
class QDialog;
class QTime;
QT_END_NAMESPACE

namespace Ui {
class RegimeFile;
class InfoPrint;
}

class RigimeFileClass : public RigimeFile
{
    Q_OBJECT Q_INTERFACES(RigimeFile)

public:
    RigimeFileClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Regime File"; }
    virtual QWidget * getWidget();
    virtual QSize getSize();
    virtual void setMenuBar(QList <QMenu *>);

    virtual ~RigimeFileClass();

private:
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuRegimeFile;
    QAction *startRegime;
    Ui::RegimeFile *ui;
    Ui::InfoPrint *uiDialog;
    QList <QMenu *> listMenu;
    QString pathPlugin;
    QString workerText;
    bool destroyedBL;
    bool startBL;
    QSize saveSizeLabelInputAndShow;

    int calculateCorrectly;
    int calculateError;
    QTime *calculateTime;

    QDialog *dialog;

private:
     void loadPlugins(const QString dir);
     void centralAdministration(QChar);
     void startPrint();
     void stopPrint();

private slots:
    void slGetWidget();
    void setWorkerText(QString);
    void destroyedWidget();

public slots:
    void slKeyPressEvent  (QKeyEvent *event);
    void slResizeEvent (QResizeEvent * event);
    void siKeyboardLanguageChange();

signals:
    void siGetWidget(QWidget *);
    void siGetWord(QChar);
    void stopLesson();
};

#endif // REGIMEFILE_H
