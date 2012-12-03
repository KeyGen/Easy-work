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
