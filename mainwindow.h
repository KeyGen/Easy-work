#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDebug>
#include <QMouseEvent>
#include <QTimeLine>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Добовляем Q_INVOKABLE что бы Qml увидела функцию
    Q_INVOKABLE void quit();//Функция C++ вызываемая из QML для завершения работы приложения
    Q_INVOKABLE void size_enhance(); //Функция C++ вызываемая из QML увеличивает размер окна
    Q_INVOKABLE void size_decreasing(); //Функция C++ вызываемая из QML уменьшающая размер окна
    Q_INVOKABLE void timer_size_enhance(); //Функция C++ вызываемая из QML запуск таймера увеличивает размер окна
    Q_INVOKABLE void timer_size_decreasing(); //Функция C++ вызываемая из QML запуск таймера уменьшающая размер окна
    Q_INVOKABLE void timer_stop_size_enhance(); //Функция C++ вызываемая из QML остановка таймера увеличивает размер окна
    Q_INVOKABLE void timer_stop_size_decreasing(); //Функция C++ вызываемая из QML остановка таймера уменьшающая размер окна
    Q_INVOKABLE void move_window(); //Функция C++ вызываемая из QML премещающие окно

private slots:
    void slots_size_enhance(); // увеличивает размер окна
    void slots_size_decreasing(); // уменьшающая размер окна

private:
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели

    int size_widow;
    QList<double> size_for_window;
    double move_x_Move_Qml;
    double move_y_Move_Qml;
    double move_plass_y;
    double move_plass_x;
    QTimeLine *timer_size_big;
    QTimeLine *timer_size_smoll;
    bool timer_big_stop;
    bool timer_smoll_stop;
};

#endif // MAINWINDOW_H
