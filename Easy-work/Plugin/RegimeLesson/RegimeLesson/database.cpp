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
