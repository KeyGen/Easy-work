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

#include "database.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QDir>

DataBase::DataBase()
{
    nameLesson = findLessonName();
}

QStringList DataBase::findLessonName(QString path){
    QStringList obtainedNameLesson;
    QDir findLesson(path);

    QStringList filter;
    filter << "*.lesson";

    QStringList file = findLesson.entryList(filter);

    for(int i = 0; i<file.size(); i++){
        QString nameBD = readDB(path + "/" + file.at(i));
        if(!nameBD.isEmpty())
            obtainedNameLesson << nameBD;
    }

    return obtainedNameLesson;
}

QString DataBase::readDB(QString path){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()) {
        qDebug() << "Unable to execute db - exiting";
        return "";
    }

    QSqlQuery query;
    if (!query.exec("SELECT * FROM lesson;")) {
        qDebug() << "Unable to execute query - exiting";
        return "";
    }

    //Reading of the data
    QSqlRecord rec     = query.record();
    QString nameLessonFile;

    while (query.next()){
        nameLessonFile = query.value(rec.indexOf("lessonName")).toString();
        break;
    }

    if(!nameLessonFile.isEmpty())
    saveLessonFilePath.insert(nameLessonFile,path);

    return nameLessonFile;
}

QHash <int,QStringList> DataBase::getLesson(QString language){

    QHash <int,QStringList> lesson;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(saveLessonFilePath.find(language).value());

    if (!db.open()) {
        qDebug() << "Unable to execute db - exiting";
        return lesson;
    }

    QSqlQuery query;
    if (!query.exec("SELECT * FROM lesson;")) {
        qDebug() << "Unable to execute query - exiting";
        return lesson;
    }

    //Reading of the data
    QSqlRecord rec = query.record();

    int id;
    QStringList lessonNameAndText;

    while (query.next()){
        id = query.value(rec.indexOf("id")).toInt();

        if(id != 0){
            lessonNameAndText << query.value(rec.indexOf("lessonName")).toString();
            lessonNameAndText << query.value(rec.indexOf("lessonText")).toString();
            lesson.insert(id,lessonNameAndText);
            lessonNameAndText.clear();
        }
        else{
            authorName = query.value(rec.indexOf("lessonText")).toString();
        }
    }

    return lesson;
}
