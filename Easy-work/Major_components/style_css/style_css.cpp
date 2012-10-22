/**
 * Easy work - writed by KeyGen 2012
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "style_css.h"
#include <QAction>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QMenu>

Q_EXPORT_PLUGIN(StyleCSSclass);

StyleCSSclass::StyleCSSclass()
{
    pathDir = "../../readyStyleCSS";
    menuStyle = new QMenu(tr("Стили"));
    QStringList filterDir;
    QStringList filterCSS;
    QStringList folderWithCSS;

    filterDir << "*.style";
    filterCSS << "*.css";

    QDir dirWithCSS(pathDir);

    folderWithCSS = dirWithCSS.entryList(filterDir);

    if(!folderWithCSS.isEmpty())
    {
        for(int i = 0; i<folderWithCSS.size(); i++)
        {
            QDir readCSS(pathDir + "/" + folderWithCSS.at(i));

            if(!readCSS.entryList(filterCSS).isEmpty())
            {

                QFile read_file(pathDir + "/" + folderWithCSS.at(i) + "/" + readCSS.entryList(filterCSS).at(0));

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

    menuStyle->setStyleSheet(
                "QMenu::indicator {"
                "background: #505050;"
                "}"

                "QMenu::indicator:non-exclusive:unchecked:selected {"
                "background: #228B22;"
                "}"
                );


    if(!downloadCSS.isEmpty())
    {
        QMap <QString,QString>::iterator it = downloadCSS.begin();

        for(int i = 0; it != downloadCSS.end(); ++it, i++)
        {
            actionsNameCSS.append(new QAction(it.key(),this));

            menuStyle->addAction(actionsNameCSS.at(i));

            actionsNameCSS.at(i)->setCheckable(true);

            connect(actionsNameCSS.at(i),SIGNAL(triggered()),this,SLOT(slotActivateCSS()));
        }
    }
    else
    {
        actionsNameCSS.append(new QAction(tr("Стили не найдены"),this));
        menuStyle->addAction(actionsNameCSS.at(0));
    }

}

void StyleCSSclass::slotActivateCSS()
{

    for(int i = 0; i<actionsNameCSS.size(); i++)
    {
        if(actionsNameCSS.at(i)->isChecked())
        {
            rememberActionActive = actionsNameCSS.at(i)->text();

            for(int j = 0; j<actionsNameCSS.size(); j++)
            {
                actionsNameCSS.at(j)->setChecked(false);
            }

            break;
        }
    }

    QMap <QString,QString>::iterator it = downloadCSS.find(rememberActionActive);

    emit getStyle(it.value());
}

QString StyleCSSclass::getStandardStyleSheet()
{
    QString standardSheet(

"QWidget#centralWidget {"

    "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1, "
                                "stop:0 blue,"
                                "stop: 0.50 blue,"
                                "stop:1 #00ffff);"

    "border-radius: 15px;"
    "background-position: top center;"
    "background-origin: padding;"
"}"

"QLabel#showText {"

    "background: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5,"
                                "stop:0 #9C9C9C,"
                                "stop:0.5 #E8E8E8,"
                                "stop:1 #9C9C9C);"

    "border: solid black;"
    "border-top-left-radius: 10px;"
    "border-bottom-left-radius: 10px;"
    "color: black;"
    "font-size: 40px;"
    "border-width: 2px 0px 2px 2px;"
"}"

"QLabel#inputText { "

    "background: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5, "
                                "stop:0 #464451,"
                                "stop:0.5  #9C9C9C,"
                                "stop:1 #464451);"
    "border: solid;"
    "border-top-right-radius: 10px;"
    "border-bottom-right-radius: 10px;"
    "color: white;"
    "font-size: 40px;"
    "border-width: 2px 2px 2px 0px;"

"}"

"QProgressBar::chunk {"
    "background: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5, stop:0 #464451, stop:1 #9C9C9C);"
    "border-radius: 9px;"
"}"

"QProgressBar {"
    "background: #E8E8E8;"
    "color: black;"
    "font: bold;"
    "border: 1px solid black;"
    "border-radius: 10px;"
    "text-align: center;"
"}"

"QMenuBar {"
    "spacing: 20;"
    "min-width: 72px;"
    "min-height: 25px;"

    "background: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5,"
                                "stop:0 #171717,"
                                "stop: 0.25 grey,"
                                "stop: 0.75 grey,"
                                "stop:1 #171717);"
"}"

"QMenuBar::item {"
    "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1,"
                                "stop:0 #00ffff,"
                                "stop:1 blue);"
    "border: 1px solid blue;"
    "border-top-right-radius: 5px;"
    "border-top-left-radius: 5px;"
    "border-width: 1px 1px 0px 1px;"
    "color: black;"
"}"

"QMenuBar::item:pressed {"
    "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1,"
                                "stop:0 #000000,"
                                "stop:1 blue);"
    "color: white"
"}"

"QWidget#gridWidget {"

    "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1,"
    "stop:0 blue,"
    "stop:0.25 blue,"
    "stop: 0.50 #00ffff,"
    "stop:0.75 blue,"
    "stop:1 blue);"

    "border-radius: 15px;"
    "background-position: top center;"
    "background-origin: padding;"
"}"

"QPushButton {"

    "background: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5,"
    "stop:0 #464451,"
    "stop:0.5  #9C9C9C,"
    "stop:1 #464451);"

    "border-style: outset;"
    "border-width: 1px;"
    "border-radius: 10px;"
    "border-color: black;"
    "font: bold 14px;"
    "padding: 6px;"
    "color: white;"
"}"

"QPushButton:pressed {"

    "border-style: inset;"

    "background-color: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5,"
    "stop:0 #464451,"
    "stop:0.5  #000000,"
    "stop:1 #464451);"
"}" );

    return standardSheet;
}
