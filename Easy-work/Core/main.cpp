#include <QtGui/QApplication>
#include <QTextCodec>
#include "core.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Устанавливаем кодировку с который будет работать программа (UTF-8)
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);

    Core w;
    w.show();
    
    return a.exec();
}
