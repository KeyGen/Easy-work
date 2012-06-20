#ifndef KEYBOARD_MY_H
#define KEYBOARD_MY_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDebug>
#include <QMouseEvent>

class Keyboard_my : public QMainWindow
{
    Q_OBJECT
    
public:
    Keyboard_my(QWidget *parent = 0);
    ~Keyboard_my();

    // Добовляем Q_INVOKABLE что бы Qml увидела функцию
    Q_INVOKABLE void quit();//Функция C++ вызываемая из QML для завершения работы приложения

    Q_INVOKABLE void move_window(); //Функция C++ вызываемая из QML премещающие окно
    Q_INVOKABLE void bl_true(); //Функция C++ вызываемая из QML изменяющие BL_move на true

    Q_INVOKABLE void size_input(); //Функция C++ вызываемая из QML изменяющие размер окна
    Q_INVOKABLE void bl_true_size(); //Функция C++ вызываемая из QML изменяющие BL_size_input на true
    Q_INVOKABLE void cursor_up(); //Функция C++ вызываемая из QML изменяющие курсор
    Q_INVOKABLE void cursor_down(); //Функция C++ вызываемая из QML изменяющие курсор


private:
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели

    bool BL_move;
    int save_x;
    int save_y;

    bool BL_size_input;
    int save_x_size;
    int save_y_size;
};

#endif // KEYBOARD_MY_H
