#include "style.h"

#include "qzipreader_p.h"

Q_EXPORT_PLUGIN(StyleClass);

StyleClass::StyleClass(){
}

StyleClass::~StyleClass() {}

QString StyleClass::readFile(QString path){

    QFile read_file(path);

    if(read_file.open(QIODevice::ReadOnly))
    {
        QTextStream out(&read_file);
        return out.readAll();
    }

    return "";
}
