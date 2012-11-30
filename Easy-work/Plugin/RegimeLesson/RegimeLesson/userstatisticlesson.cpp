#include "userstatisticlesson.h"

#include <QDebug>
#include <QMessageBox>

// Создадим папку
#include <QDir>

// Подключение
#include <QSqlDatabase>
#include <QSqlQuery>

// Чтение
#include <QSqlRecord>

StatisticLesson::StatisticLesson(QObject *parent) : QObject(parent) {
    datebaseUserEnlargement = ".lessonStat";
}

StatisticLesson::~StatisticLesson(){}

bool StatisticLesson::createConnection(QString passvord, QString name, QString path)
{
    // Создаем папку если надо...
    QDir create;
    create.mkpath(path);

    // Подключаемся
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path + "/" + name + datebaseUserEnlargement);

    db.setUserName(name);
    db.setPassword(passvord);

//    query.prepare("SELECT * FROM users_tbl WHERE login=?");
//    query.bindValue(0,ui->lineEdit_login->text());
//    query.exec();

//    Добавлено через 3 минуты
//    потом проверяешь свойство query.size(), если ==0 - логин не найден.

    // Проверяем все ли в порядке. Проблемы могут быть с правами...
    if (!db.open()) {
        qDebug() << QObject::tr("Cannot open database");
        return false;
    }

    // Создаем таблицу. Если таблица существует создавать вторую не будет...
    QSqlQuery query;
    QString   str  = "CREATE TABLE tableStatisticLesson ( "
            "lessonName  VARCHAR(20), "
            "assessment VARCHAR(10) "
            ");";

    if (!query.exec(str)) {
        ;//qDebug() << "Таблица уже имеется";
    }

    return true;
}

void StatisticLesson::insertDB(QStringList value){

    if(value.size()==2){
        // Проверим открытие
        bool openBL = true;

        QSqlQuery query;
        if (!query.exec("SELECT * FROM tableStatisticLesson;")) {
            qDebug() << "Unable to execute query - exiting";
            openBL = false;
        }

        if(openBL){

            //Adding some information
            QString str;
            QString strF =
                    "INSERT INTO tableStatisticLesson (lessonName, assessment) "
                    "VALUES('%1', '%2');";

            str = strF.arg(value.at(0))
                    .arg(value.at(1));

            if (!query.exec(str)) {
                qDebug() << "Unable to do insert opeation";
            }
        }
    }
}

QMap<QString,QString> StatisticLesson::readDB(){

    QMap<QString,QString> read;
    // Проверим открытие
    bool openBL = true;

    // Подключаемся с таблице в базе
    QSqlQuery query;
    if (!query.exec("SELECT * FROM tableStatisticLesson;")) {
        qDebug() << "Unable to execute query - exiting";
        openBL = false;
    }

    if(openBL){
        // Чтение базы
        QSqlRecord rec = query.record();

        // Сохраним данные сюда
        QString lessonName;
        QString assessment;

        // Чтение
        while (query.next()) {
            lessonName = query.value(rec.indexOf("lessonName")).toString();
            assessment = query.value(rec.indexOf("assessment")).toString();

            read.insert(lessonName,assessment);
        }
    }

    return read;
}

void StatisticLesson::setData(QMap<QString,QString> value){

    // Проверим открытие
    bool openBL = true;

    QSqlQuery query;
    if (!query.exec("SELECT * FROM tableStatisticLesson;")) {
        qDebug() << "Unable to execute query - exiting";
        openBL = false;
    }

    if(openBL){

        // Текст очистки
        QString strF = "DELETE FROM tableStatisticLesson";

        // Обязательно проверка очистки
        if (!query.exec(strF)) {
            qDebug() << "Unable to do delete opeation";
        }
    }

    if(openBL){
        QMap<QString,QString>::iterator it = value.begin();

        for(; it!=value.end(); ++it){
            QStringList listValue;
            listValue << it.key();
            listValue << it.value();
            insertDB(listValue);
        }
    }
}

void StatisticLesson::setMap(QMap<QString,QString> value){
    saveMap = value;
}

void StatisticLesson::setData(){

    if(!saveMap.isEmpty()){
        // Проверим открытие
        bool openBL = true;

        QSqlQuery query;
        if (!query.exec("SELECT * FROM tableStatisticLesson;")) {
            qDebug() << "Unable to execute query - exiting";
            openBL = false;
        }

        if(openBL){

            // Текст очистки
            QString strF = "DELETE FROM tableStatisticLesson";

            // Обязательно проверка очистки
            if (!query.exec(strF)) {
                qDebug() << "Unable to do delete opeation";
            }
        }

        if(openBL){
            QMap<QString,QString>::iterator it = saveMap.begin();

            for(; it!=saveMap.end(); ++it){
                QStringList listValue;
                listValue << it.key();
                listValue << it.value();
                insertDB(listValue);
            }
        }
    }

    saveMap.clear();
}

QStringList StatisticLesson::findUserStatistic(QString path){

    QStringList user;
    QDir findUser(path);
    QStringList filter;
    filter << "*" + datebaseUserEnlargement;
    user << findUser.entryList(filter);

    for(int i = 0; i<user.size(); i++)
        user[i].replace(datebaseUserEnlargement,"");

    return user;
}
