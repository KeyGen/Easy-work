#include <QtGui/QApplication>
#include "keyboard_my.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);


    Keyboard_my w;
    w.show();
    
    return a.exec();
}
