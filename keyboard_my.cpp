#include "keyboard_my.h"

Keyboard_my::Keyboard_my(QWidget *parent)
    : QMainWindow(parent)
{
    // Отключаем обводку
    this->setWindowFlags(Qt::CustomizeWindowHint);

    // Разрешение экрана
    QDesktopWidget *desktop = QApplication::desktop();

    //this
    this->setMinimumSize(582,235);
    this->setMaximumSize(1164,470);
    this->setGeometry((desktop->width()-1164)/2,(desktop->height()-470)/2,1164,470);

    //Включаем наш QML
    ui = new QDeclarativeView(this);
    ui->setSource(QUrl("qrc:/Qml/Main_qml.qml"));

    // Выравниваем по центру
    setCentralWidget(ui);
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    //Находим корневой элемент
    Root = ui->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент Qt_fun
    ui->rootContext()->setContextProperty("Qt_fun", this);
}

Keyboard_my::~Keyboard_my()
{
    //Удаляем QML
    delete ui;
}

//Функция C++ вызываемая из QML премещающие окно
void Keyboard_my::move_window()
{
    if(BL_move)
    {
        save_x = QCursor::pos().x() - this->pos().x();
        save_y = QCursor::pos().y() - this->pos().y();

        this->setCursor(QCursor(Qt::SizeAllCursor));
    }

    if(BL_move)
        BL_move = false;

    this->move(QCursor::pos().x()-save_x , QCursor::pos().y() - save_y);
}

//Функция C++ вызываемая из QML изменяющие BL_move на true
void Keyboard_my::bl_true()
{
    BL_move = true;
    this->setCursor(QCursor(Qt::ArrowCursor));
}

//Функция C++ вызываемая из QML изменяющие размер окна
void Keyboard_my::size_input()
{
     if(BL_size_input)
     {
         save_x_size = QCursor::pos().x() - this->pos().x() - this->size().width();
         save_y_size = QCursor::pos().y() - this->pos().y() - this->size().height();
     }

     if(BL_size_input)
         BL_size_input = false;

     this->resize(QCursor::pos().x()-this->pos().x() - save_x_size, QCursor::pos().y() - this->pos().y() - save_y_size);
}

//Функция C++ вызываемая из QML изменяющие BL_size_input на true
void Keyboard_my::bl_true_size()
{
    BL_size_input = true;
}

 //Функция C++ вызываемая из QML изменяющие курсор
void Keyboard_my::cursor_down()
{
    this->setCursor(QCursor(Qt::ArrowCursor));
}

//Функция C++ вызываемая из QML изменяющие курсор
void Keyboard_my::cursor_up()
{
    this->setCursor(QCursor(Qt::SizeFDiagCursor));
}

//Функция C++ вызываемая из QML для завершения работы приложения
void Keyboard_my::quit()
{
    // Вырубаем приложение
    ui->close();
    this->close();
    exit(0);
}
