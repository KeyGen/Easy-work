#include <QtGui/QApplication>
#include "keyboard_my.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Keyboard_my w;
    w.show();
    
    return a.exec();
}
