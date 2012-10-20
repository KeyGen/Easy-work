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

#include "downloadlanguagekeyboard.h"

#include <QDebug>
#include <QDir>

Q_EXPORT_PLUGIN(KeyboardLanguageClass);

KeyboardLanguageClass::KeyboardLanguageClass()
{
    pathDir = "../../readyKeyboardLanguage";

    menuLanguage = new QMenu(tr("Выбор языка"));

    QDir dir(pathDir);
    QStringList filter;
    QStringList readFile;
    filter << "*.language";

    readFile = dir.entryList(filter);

    if(!readFile.isEmpty())
    {
        for(int i = 0; i<readFile.size(); i++)
        {
            QFile read_file(pathDir + "/" + readFile.at(i));

            QString all_file;

            if(read_file.open(QIODevice::ReadOnly)) // чтение *txt
            {
                QTextStream out(&read_file);
                out.setCodec("UTF-8");          // Установка кодека
                all_file = out.readAll();       // Считываем весь файл в QString
            }

            QChar ch;
            QString readNameRead;
            QString name = "WindowTitle=";
            for(int i = all_file.lastIndexOf(name) + name.size(); ch != '\n'; i++)
            {
                if(all_file.at(i) == '\n')
                    break;

                ch = all_file.at(i);

                readNameRead += ch;
            }

            all_file.remove(name);
            all_file.remove(readNameRead);
            all_file.remove("\n");

            QStringList listKeyTemp;
            QRegExp rx("<key>([^<]*)</key>");
            rx.setMinimal(true);

             int pos = 0;
             while ((pos = rx.indexIn(all_file, pos)) != -1)
             {
                 QString str = rx.cap(1);

                 listKeyTemp << str;

                 pos += rx.matchedLength();
             }

             hashLanguage.insert(readNameRead,listKeyTemp);
        }
    }


    // В downloadCSS загрузили имена и сами стили создадим QAction

    menuLanguage->setStyleSheet(
                "QMenu::indicator {"
                "background: #505050;"
                "}"

                "QMenu::indicator:non-exclusive:unchecked:selected {"
                "background: #228B22;"
                "}"
                );


    if(!hashLanguage.isEmpty())
    {
        QHash <QString,QStringList>::iterator it = hashLanguage.begin();

        for(int i = 0; it != hashLanguage.end(); ++it, i++)
        {
            actionsLanguage.append(new QAction(it.key(),this));

            menuLanguage->addAction(actionsLanguage.at(i));

            actionsLanguage.at(i)->setCheckable(true);

            connect(actionsLanguage.at(i),SIGNAL(triggered()),this,SLOT(slotActivateLanguage()));
        }
    }
    else
    {
        actionsLanguage.append(new QAction(tr("Стили не найдены"),this));
        menuLanguage->addAction(actionsLanguage.at(0));
    }

}

void KeyboardLanguageClass::slotActivateLanguage()
{

    for(int i = 0; i<actionsLanguage.size(); i++)
    {
        if(actionsLanguage.at(i)->isChecked())
        {
            rememberActionActive = actionsLanguage.at(i)->text();

            for(int j = 0; j<actionsLanguage.size(); j++)
            {
                actionsLanguage.at(j)->setChecked(false);
            }

            break;
        }
    }

    QHash <QString,QStringList>::iterator it = hashLanguage.find(rememberActionActive);

    emit getLanguage(it.value());

}
