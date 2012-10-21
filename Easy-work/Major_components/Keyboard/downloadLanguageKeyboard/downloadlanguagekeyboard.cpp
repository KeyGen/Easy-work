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

            if(read_file.open(QIODevice::ReadOnly)) // чтение *txt
            {
                QTextStream out(&read_file);
                out.setCodec("UTF-8");          // Установка кодека

                QString readAll = out.readAll();
                hashLanguage.insert(getNameLanguage(readAll), getMultiHahs(readAll));
            }
        }
    }

    installationQMenuStyleSheet();
    installationQMenu(hashLanguage);
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

    QHash <QString, QMultiHash<QString, QString> >::iterator it = hashLanguage.find(rememberActionActive);

    emit getLanguage(it.value());
}

void KeyboardLanguageClass::installationQMenuStyleSheet(){

    menuLanguage->setStyleSheet(
                "QMenu::indicator {"
                "background: #505050;"
                "}"

                "QMenu::indicator:non-exclusive:unchecked:selected {"
                "background: #228B22;"
                "}"
                );
}

void KeyboardLanguageClass::installationQMenu(QHash < QString, QMultiHash<QString, QString> > hashLanguageTemp){

    if(!hashLanguageTemp.isEmpty())
    {
        QHash <QString,QMultiHash<QString,QString> >::iterator it = hashLanguageTemp.begin();

        for(int i = 0; it != hashLanguageTemp.end(); ++it, i++)
        {
            actionsLanguage.append(new QAction(it.key(),this));

            menuLanguage->addAction(actionsLanguage.at(i));

            actionsLanguage.at(i)->setCheckable(true);

            connect(actionsLanguage.at(i),SIGNAL(triggered()),this,SLOT(slotActivateLanguage()));
        }
    }
    else
    {
        actionsLanguage.append(new QAction(tr("Языки не найдены"),this));
        menuLanguage->addAction(actionsLanguage.at(0));
    }
}


QString KeyboardLanguageClass::getNameLanguage(QString str)
{
    QString temp;

    QString name = "WindowTitle=";

    for(int i = str.lastIndexOf(name) + name.size();; i++)
    {
        if(str.at(i) == '\n')
            break;

        temp += str.at(i);
    }

    return temp;
}

QMultiHash <QString, QString > KeyboardLanguageClass::getMultiHahs(QString str)
{
    QMultiHash <QString, QString> temp;

    if(!str.isEmpty())
    {
        str.remove('\n');

        QRegExp rxKey       ("<key>([^\\A]*)</key>");
        rxKey.setMinimal(true);

        int pos = 0;
        while ((pos = rxKey.indexIn(str, pos)) != -1)
        {
            QString strKey = rxKey.cap(1);
            QString strObjectName = getStrObjectName(strKey);

            temp.insert(strObjectName,getShift(strKey));
            temp.insert(strObjectName,getNoShift(strKey));

            pos += rxKey.matchedLength();
        }
    }

    return temp;
}

QString KeyboardLanguageClass::getStrObjectName(QString str){

    QString temp;

    QRegExp rxObjectName("<objectName>([^\\A]*)</objectName>");
    rxObjectName.setMinimal(true);

    int pos = 0;
    while ((pos = rxObjectName.indexIn(str, pos)) != -1)
    {
        temp = rxObjectName.cap(1);

        pos += rxObjectName.matchedLength();
    }

    return temp;
}

QString KeyboardLanguageClass::getNoShift(QString str){

    QString temp;

    QRegExp rxNoShift   ("<noShift>([^\\A]*)</noShift>");
    rxNoShift.setMinimal(true);

    int pos = 0;
    while ((pos = rxNoShift.indexIn(str, pos)) != -1)
    {
        temp = rxNoShift.cap(1);

        pos += rxNoShift.matchedLength();
    }

    return temp;
}

QString KeyboardLanguageClass::getShift(QString str){

    QString temp;

    QRegExp rxShift     ("<shift>([^\\A]*)</shift>");
    rxShift.setMinimal(true);

    int pos = 0;
    while ((pos = rxShift.indexIn(str, pos)) != -1)
    {
        temp = rxShift.cap(1);

        pos += rxShift.matchedLength();
    }

    return temp;
}
