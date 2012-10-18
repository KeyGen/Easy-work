#include "style_css.h"
#include <QAction>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <QDebug>

Q_EXPORT_PLUGIN(StyleCSSclass);

StyleCSSclass::StyleCSSclass()
{
    strDir = "../../readyStyleCSS";
    QStringList filterDir;
    QStringList filterCSS;
    QStringList folderWithCSS;

    filterDir << "*.style";
    filterCSS << "*.css";

    QDir dirWithCSS(strDir);

    folderWithCSS = dirWithCSS.entryList(filterDir);

    if(!folderWithCSS.isEmpty())
    {
        for(int i = 0; i<folderWithCSS.size(); i++)
        {
            QDir readCSS(strDir + "/" + folderWithCSS.at(i));

            if(!readCSS.entryList(filterCSS).isEmpty())
            {
                qDebug() << readCSS.entryList(filterCSS).at(0);
                QFile read_file(strDir + "/" + folderWithCSS.at(i) + "/" + readCSS.entryList(filterCSS).at(0));

                QString all_file;

                if(read_file.open(QIODevice::ReadOnly)) // чтение *txt
                {
                    QTextStream out(&read_file);
                    out.setCodec("UTF-8");          // Установка кодека
                    all_file = out.readAll();       // Считываем весь файл в QString
                }

                QChar ch;
                QString readNameRead;
                QString name_ru = "name_ru: ";
                for(int i = all_file.lastIndexOf(name_ru) + name_ru.size(); ch != '\n'; i++)
                {
                    if(all_file.at(i) == '\n')
                        break;

                    ch = all_file.at(i);

                    readNameRead += ch;
                }

                downloadCSS.insert(readNameRead,all_file);
            }
        }
    }

    // В downloadCSS загрузили имена и сами стили создадим QAction

    QMap <QString,QString>::iterator it = downloadCSS.begin();

    for(int i = 0; it != downloadCSS.end(); ++it, i++)
    {
        actionsNameCSS.append(new QAction(it.key(),this));

        connect(actionsNameCSS.at(i),SIGNAL(triggered(bool)),this,SLOT(slotActivateCSS(bool)));
    }

}

void StyleCSSclass::slotActivateCSS(bool BL)
{
    QMap <QString,QString>::iterator it = downloadCSS.begin();

    for(; it != downloadCSS.end(); ++it)
    {
        emit getStyle(it.value());
        break;
    }
}
