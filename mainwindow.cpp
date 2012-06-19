#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Отключаем обводку
    //this->setWindowFlags(Qt::Popup);

    // Эта байда тормозит таймеры
    timer_big_stop = true;
    timer_smoll_stop = true;

    // Начальная позиция move
    move_x_Move_Qml = 170;
    move_y_Move_Qml = 150;

    // Установка положения
    this->move(move_x_Move_Qml,move_y_Move_Qml);

    // Создаем таймер для нажатия на кнопку увеличения
    timer_size_big = new QTimeLine(2,this);
    timer_size_big->setFrameRange(0,2);

    // коннектим его с функцией
    connect(timer_size_big,SIGNAL(finished()),this,SLOT(slots_size_enhance()));

    // Создаем таймер для нажатия на кнопку уменьшения
    timer_size_smoll = new QTimeLine(2,this);
    timer_size_smoll->setFrameRange(0,2);

    // коннектим его с функцией
    connect(timer_size_smoll,SIGNAL(finished()),this,SLOT(slots_size_decreasing()));

    // Позиция курсра для установки размера
    size_widow = 0;

    // Установка подготовленных размеров для окна
    double size_for_window_width = 1050;
    for(int i = 0; i<150; i++,size_for_window_width-=1.0)
    {
        size_for_window << size_for_window_width;
        double size_for_window_height = size_for_window_width*455.0/1050.0;
        size_for_window << size_for_window_height;
    }

    move_plass_x = (size_for_window.at(0) - size_for_window.at(2))/2.0;
    move_plass_y = (size_for_window.at(1) - size_for_window.at(3))/2.0;

    qDebug() << move_plass_y << " " << move_plass_x;

    //this->setFixedSize(size_for_window.at(size_widow),size_for_window.at(size_widow+1));

    //Включаем наш QML
    ui = new QDeclarativeView(QUrl("qrc:/qml/Qml/Main_Qml.qml"),this);
    // Выравниваем по центру
    setCentralWidget(ui);
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    //Находим корневой элемент
    Root = ui->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент Qt_fun
    ui->rootContext()->setContextProperty("Qt_fun", this);
}
//Функция C++ вызываемая из QML остановка таймера увеличивает размер окна
void MainWindow::timer_stop_size_enhance()
{
    timer_big_stop = false;
}

//Функция C++ вызываемая из QML остановка таймера уменьшающая размер окна
void MainWindow::timer_stop_size_decreasing()
{
    timer_smoll_stop = false;
}

//Функция C++ вызываемая из QML запуск таймера увеличивает размер окна
void MainWindow::timer_size_enhance()
{
    timer_big_stop = true;
    timer_size_big->start();
}

//Функция C++ вызываемая из QML запуск таймера уменьшающая размер окна
void MainWindow::timer_size_decreasing()
{
    timer_smoll_stop = true;
    timer_size_smoll->start();
}

// увеличивает размер окна
void MainWindow::slots_size_enhance()
{
    if(timer_big_stop)
    {
        qDebug() << "big";
        size_enhance();
        timer_size_big->start();
    }

}

// уменьшающая размер окна
void MainWindow::slots_size_decreasing()
{
    if(timer_smoll_stop)
    {
        qDebug() << "smoll";
        size_decreasing();
        timer_size_smoll->start();
    }

}

MainWindow::~MainWindow()
{
    //Удаляем QML
    delete ui;
}

//Функция C++ вызываемая из QML для завершения работы приложения
void MainWindow::quit()
{
    // Вырубаем приложение
    ui->close();
    this->close();
    exit(0);
}

//Функция C++ вызываемая из QML увеличивает размер окна
void MainWindow::size_enhance()
{
    if(size_widow!=0)
    {
        size_widow-=2;

        move_x_Move_Qml -= move_plass_x;
        move_y_Move_Qml -= move_plass_y;

        this->move(move_x_Move_Qml, move_y_Move_Qml);
        this->setFixedSize(size_for_window.at(size_widow),size_for_window.at(size_widow+1));
    }
}

//Функция C++ вызываемая из QML уменьшающая размер окна
void MainWindow::size_decreasing()
{
    if(size_for_window.size()-2 != size_widow)
    {
        move_x_Move_Qml += move_plass_x;
        move_y_Move_Qml += move_plass_y;
        size_widow+=2;

        this->move(move_x_Move_Qml, move_y_Move_Qml);
        this->setFixedSize(size_for_window.at(size_widow),size_for_window.at(size_widow+1));
    }
}

//Функция C++ вызываемая из QML премещающие окно
void MainWindow::move_window()
{
    QMouseEvent mause(QEvent::ActionChanged,QPoint(100,100),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);

    move_x_Move_Qml = mause.globalX()  - size_for_window.at(size_widow)+40;
    move_y_Move_Qml = mause.globalY() - 15;

    this->move(move_x_Move_Qml , move_y_Move_Qml);
}
