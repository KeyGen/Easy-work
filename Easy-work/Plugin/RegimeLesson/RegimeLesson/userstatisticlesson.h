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
    void setMap(QMap<QString,QString>);

    QStringList findUserStatistic(QString path = "../share/EasyWork/Database");

private:
    QString datebaseUserEnlargement;
    QMap<QString,QString> saveMap;

public slots:
    // Чистка
    void setData();

};

#endif // StatisticLesson_H
