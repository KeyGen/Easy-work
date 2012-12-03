#include "userstatisticlesson.h"

#include <QDebug>
#include <QMessageBox>
#include <QProgressDialog>
#include <QDesktopWidget>
#include <QApplication>

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

    // Проверяем все ли в порядке. Проблемы могут быть с правами...
    if (!db.open()) {
        qDebug() << QObject::tr("Cannot open database");
        return false;
    }

    // Создаем таблицу. Если таблица существует создавать вторую не будет...
    QSqlQuery query;

    QString   str  = "CREATE TABLE tableStatisticLesson ( "
            "password VARCHAR(20),"
            "lessonName  VARCHAR(20),"
            "assessment VARCHAR(10) "
            ");";

    if (!query.exec(str)) {
        if(passvord != getPassword()){
            messageBoxExec(tr("Пароль введен не верно"));
            db.close();
            return false;
        }

    }

    return true;
}

void StatisticLesson::setPassword(QString password){

    // Проверим открытие
    bool openBL = true;

    QSqlQuery query;
    if (!query.exec("SELECT * FROM tableStatisticLesson;")) {
        qDebug() << "Unable to execute query - exiting";
        openBL = false;
    }

    if(openBL){

        //Adding some information
        QString strF =
                "INSERT INTO tableStatisticLesson (password) "
                "VALUES('" + password + "');";

        if (!query.exec(strF)) {
            qDebug() << "Unable to do insert opeation";
        }
    }
}

QString StatisticLesson::getPassword(){

    QString password;
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

        // Чтение
        while (query.next()) {
            password = query.value(rec.indexOf("password")).toString();
            if(!password.isEmpty())
                return password;
        }
    }

    return "";
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

    QString password = getPassword();

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
        if(!value.isEmpty()){

            QMap<QString,QString>::iterator it = value.begin();
            int size = value.size();

            QProgressDialog *progress = new QProgressDialog(0);       // Первоначальная загрузка приложения
            progress->setWindowFlags(Qt::ToolTip);
            progress->setFixedSize(300,100);
            progress->setLabelText(tr("Происходит сохранение статистики."));
            QPoint pointCenter = screenCenter();
            progress->move(pointCenter.x()-progress->width()/2,pointCenter.y()-progress->height()/2); // Распологаем MainWindow в ценре
            progress->show();

            for(int i = 0; it!=value.end(); ++it, i++){
                progress->setValue(i*100/size);

                QStringList listValue;
                listValue << it.key();
                listValue << it.value();
                insertDB(listValue);
            }

            progress->setValue(100);
            delete progress;
        }
    }

    setPassword(password);

    qDebug() << "Перезапись статистики выполена";
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

void StatisticLesson::messageBoxExec(QString text){

    QPoint center = screenCenter();
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Информация"));
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);

    msgBox.setText(text);

    msgBox.show();
    msgBox.move(center.x()-msgBox.width()/2,center.y()-msgBox.height()/2-20);
    msgBox.exec();
}

QPoint StatisticLesson::screenCenter(){
    QDesktopWidget *desktop = QApplication::desktop();  // Определяем разрешение экрана
    return QPoint(desktop->width()/2,desktop->height()/2);
}
