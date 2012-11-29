/**
 * Easy work - краткое описание на английском
 * Copyright (C) 2012 KeyGen <KeyGenQt@gmail.com>
 * https://github.com/KeyGen/Easy-work/wiki
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

#ifndef REGIMELESSON_H
#define REGIMELESSON_H

#include "RegimeLesson_global.h"
#include "database.h"
#include <QSize>
#include <QDebug>

QT_BEGIN_NAMESPACE
class QMenuBar;
class QDeclarativeView;
QT_END_NAMESPACE

namespace Ui {
class FormRegimeLesson;
}

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

    Q_INVOKABLE QString getLanguageLesson(int);
    Q_INVOKABLE void readDBNameLesson(QString);
    Q_INVOKABLE QString getNameLesson(int);
    Q_INVOKABLE QString getAutorName() { return authorName; }
    Q_INVOKABLE void startLesson(int);

    virtual ~RegimeLessonClass() {}

signals:
    void siGetWidget(QWidget *);
    void siSaveSetting(QStringList);
    void siGetWord(QChar);
    void stopLesson();

private:
    QWidget *widget;
    QMenuBar *menuBar;
    QAction *startRegime;
    Ui::FormRegimeLesson *ui;

    QDeclarativeView *ui_d;               // Qml
    QObject *Root;                      // Корневой элемент QML модели

    QList <QMenu *> listMenu;
    bool destroyedBL;
    bool destroyedQml;
    QStringList saveUser;
    QMenu *menuRegimeLesson;
    QString userName;
    QString userLessonDone;
    QString newUser;
    QStringList lessonLanguage;
    QHash <int,QStringList> lesson;
    QString authorName;
    QString workerText;

    DataBase base;
    bool startPrintLesson;
    QSize saveSizeLabelInputAndShow;
    int calculateError;

private:
    void saveSetting();
    void startQmlInput();
    void addNewUser();

    void centralAdministration(QChar ch);
    void stopPrint();
    void startPrint();
    QString preparationText(QString);
    QPoint screenCenter();
    void messageBoxExec(QString);
    void errorMax();

public slots:
    void slSetSaveSetting(QStringList);
    void slCloseEvent();
    void slResizeEvent (QResizeEvent * event);
    void slKeyPressEvent (QKeyEvent *event);
    void slKeyboardLanguageChange();

private slots:
    void slGetWidget();
    void destroyedWidget();
    void on_pushButton_clicked();
    void labelSetStyleSheetDefault();
    void labelSetStyleSheetError();
};

#endif // REGIMELESSON_H
