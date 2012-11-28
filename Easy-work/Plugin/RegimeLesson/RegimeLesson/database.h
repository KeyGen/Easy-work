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
