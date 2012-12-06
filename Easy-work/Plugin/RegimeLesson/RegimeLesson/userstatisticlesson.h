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

#ifndef StatisticLesson_H
#define StatisticLesson_H

#include <QDebug>
#include <QObject>

class StatisticLesson : public QObject
{
    Q_OBJECT

public:
    explicit StatisticLesson(QObject *parent = 0);
    ~StatisticLesson();

    // Подключение
    bool createConnection(QString passvord, QString name = "sqLite", QString path = "../share/EasyWork/Database");
    // Создадим QTableWidget
    void createTableVerticalHeader(QStringList,QStringList);
    // Вставка
    void insertDB(QStringList);
    // Чтение
    QMap<QString,QString>  readDB();
    void setData(QMap<QString,QString>);
    void setPassword(QString);
    QString getPassword();

    QStringList findUserStatistic(QString path = "../share/EasyWork/Database");

private:
    QString datebaseUserEnlargement;

private:
    void messageBoxExec(QString text);
    QPoint screenCenter();

};

#endif // StatisticLesson_H
