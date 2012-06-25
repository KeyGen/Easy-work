#ifndef KEYBOARD_MY_H
#define KEYBOARD_MY_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDebug>
#include <QMouseEvent>

#include "ui_font_input.h"

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

    Q_INVOKABLE QSize size_input(); //Функция C++ вызываемая из QML изменяющие размер окна
    Q_INVOKABLE void bl_true_size(); //Функция C++ вызываемая из QML изменяющие BL_size_input на true
    Q_INVOKABLE void cursor_up(); //Функция C++ вызываемая из QML изменяющие курсор
    Q_INVOKABLE void cursor_down(); //Функция C++ вызываемая из QML изменяющие курсор

    Q_INVOKABLE void menu_up(); //Функция C++ вызываемая из QML открывающая меню
    Q_INVOKABLE void MaxSize(); // Функция C++ вызываемая из QML увеличивающие окно на максимум

    void Initialization_language_key(); // Ициализация клавиш разных языков

private:
    QDeclarativeView *ui;
    QObject *Root; //корневой элемент QML модели

    Ui::Font_input *font_ui; // Форма для выбора шрифта
    QDialog *dialog_font; // Окно для формы

    bool BL_move;
    int save_x;
    int save_y;

    bool BL_size_input;
    int save_x_size;
    int save_y_size;

    bool Bl_fixed; // Разрешить запретить перемешение окна

    QMenu *menu;

    QAction *fixed_window_action;
    QAction *fixed_action;
    QAction *font_action;
    QAction *quit_action;
    QAction *input_font;

    // Клавиши на выбор русские, английские, украинские....
    QStringList key_rus_big;
    QStringList key_rus_smoll;
    QStringList key_eng_big;
    QStringList key_eng_smoll;
    QStringList key_ukr_big;
    QStringList key_ukr_smoll;


private slots:
    void slot_fixed_window_action(); //Слот C++ вызываемый QAction fixed_window_action
    void slot_fixed_action(bool); //Слот C++ вызываемый QAction fixed_action
    void slot_font_action(); //Слот C++ вызываемый QAction font_action
    void slot_font_input(); // Слот C++ вызываемый QAction input_font
};

#endif // KEYBOARD_MY_H
