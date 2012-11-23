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

#ifndef STATISTICFORREGIMEFILE_H
#define STATISTICFORREGIMEFILE_H

#include "StatisticForRegimeFile_global.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
class QDialog;
QT_END_NAMESPACE

namespace Ui {
class statisticDialog;
}

class StatisticForRegimeFileClass : public StatisticForRegimeFile
{
    Q_OBJECT Q_INTERFACES(StatisticForRegimeFile)

public:
    StatisticForRegimeFileClass();

    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Statistic for Regime File"; }
    virtual QAction * getAction()   { return showStatistic; }

    virtual ~StatisticForRegimeFileClass() {}

public slots:
    virtual void setValue(QStringList);
    virtual void connectDB();

private slots:
    void exec();
    void setActiveItemWidget(int);
    void deleteStatisticAll();
    void deleteStatistic();

private:
    bool createConnection(QString path = "../share/EasyWork/Database", QString name = "statisticForRegimeFile.mdb");
    void readMDB();
    void insertMDB(QStringList value);
    void createTableVerticalHeader(QHash<QString,QStringList>);
    void moveWindowCenter();

private:
    Ui::statisticDialog *ui;
    QDialog *dialogStatistic;
    bool createMDB;
    QAction *showStatistic;
    int activeHeder;
    QString pathMDB;
    QString nameMDB;
};

#endif // STATISTICFORREGIMEFILE_H
