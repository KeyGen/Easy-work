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

#ifndef DATABASE_H
#define DATABASE_H

#include <QStringList>

#include <QDebug>

class DataBase
{
public:
    explicit DataBase();
    QStringList getNameLesson() { return nameLesson; }
    QString getAuthorLessonName() { return authorName; }
    QHash <int,QStringList> getLesson(QString);

private:
    QStringList nameLesson;
    QString authorName;
    QHash <QString,QString> saveLessonFilePath;

private:
    QStringList findLessonName(QString path = "../share/EasyWork/Lesson");
    QString readDB(QString);

};

#endif // DATABASE_H
