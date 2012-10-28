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

#include "findkeyboardlayout.h"

#include "qzipreader_p.h"
#include <QMenu>
#include <QDir>

Q_EXPORT_PLUGIN(FindKeyboardLayoutClass);

FindKeyboardLayoutClass::FindKeyboardLayoutClass()
{
    menu = new QMenu("Доступны языки");
}

// Распаковка zip
QMultiHash <QString, QString> FindKeyboardLayoutClass::readerZipKeyboardLayout(QString language, QString path)
{
    language += ".language";
    QDir dir(path.toAscii());    // Создаем QDir в указанном пути (path)

    QStringList filters;            // Устанавливаем фильтры
    filters << language.toAscii();  // Устанавливаем фильтры

    if(!dir.entryInfoList(filters).isEmpty())
    {
        QZipReader zip_reader(path.toAscii() + language.toAscii());

        if (zip_reader.exists()) {          // Если все чудно

            foreach (QZipReader::FileInfo info, zip_reader.fileInfoList()) {
                if(info.isFile)
                    if(info.filePath.contains(".language")) {
                        //qDebug() << "Файл:" << info.filePath << "Размер:" << info.size; // размер извлекаемого файла

                        emit getWindowsTitle(findNameLanguage(zip_reader.fileData(info.filePath)));
                        return createLanguageHash(zip_reader.fileData(info.filePath));
                    }
            }
        }
        else {
            return returnStandartLanguage();
        }
    }
    else {
        return returnStandartLanguage();
    }

    return hashLanguage;
}

QMultiHash <QString, QString> FindKeyboardLayoutClass::returnStandartLanguage(){

    QFile read_file(":/standartLanguage");

    if(read_file.open(QIODevice::ReadOnly))
    {
        QTextStream out(&read_file);
        return createLanguageHash(out.readAll().toUtf8());
    }

    return hashLanguage;
}

QMultiHash <QString, QString> FindKeyboardLayoutClass::createLanguageHash(QByteArray bit){

    hashLanguage.clear();

    QRegExp rxKey       ("<key>([^”]*)</key>");
    rxKey.setMinimal(true);

    int pos = 0;
    while ((pos = rxKey.indexIn(bit, pos)) != -1)
    {
        QString strKey = rxKey.cap(1);

        QString nameKey = getStrObjectName(strKey);
        hashLanguage.insert(nameKey,getNoShift(strKey));
        hashLanguage.insert(nameKey,getShift(strKey));

        pos += rxKey.matchedLength();
    }

    return hashLanguage;
}

QString FindKeyboardLayoutClass::getStrObjectName(QString str){

    QString temp;

    QRegExp rxObjectName("<objectName>([^”]*)</objectName>");
    rxObjectName.setMinimal(true);

    int pos = 0;
    while ((pos = rxObjectName.indexIn(str, pos)) != -1)
    {
        temp = rxObjectName.cap(1);

        pos += rxObjectName.matchedLength();
    }

    return temp;
}

QString FindKeyboardLayoutClass::getNoShift(QString str){

    QString temp;

    QRegExp rxNoShift   ("<noShift>([^”]*)</noShift>");
    rxNoShift.setMinimal(true);

    int pos = 0;
    while ((pos = rxNoShift.indexIn(str, pos)) != -1)
    {
        temp = rxNoShift.cap(1);

        pos += rxNoShift.matchedLength();
    }

    return temp;
}

QString FindKeyboardLayoutClass::getShift(QString str){

    QString temp;

    QRegExp rxShift     ("<shift>([^”]*)</shift>");
    rxShift.setMinimal(true);

    int pos = 0;
    while ((pos = rxShift.indexIn(str, pos)) != -1)
    {
        temp = rxShift.cap(1);

        pos += rxShift.matchedLength();
    }

    return temp;
}

QMenu* FindKeyboardLayoutClass::createLanguageMenu(QString path){

    QDir dir(path.toAscii());    // Создаем QDir в указанном пути (path)

    QStringList filters;            // Устанавливаем фильтры
    filters << "*.language";  // Устанавливаем фильтры

    QStringList listLanguage = dir.entryList(filters);

    for(int i = 0; i < listLanguage.size(); i++)
    {
        QZipReader zip_reader(path.toAscii() + listLanguage.at(i));

        if (zip_reader.exists()) {          // Если все чудно

            foreach (QZipReader::FileInfo info, zip_reader.fileInfoList()) {
                if(info.isFile)
                    if(info.filePath.contains(".language")) {

                        listActionLanguage.append(new QAction(findNameLanguage(zip_reader.fileData(info.filePath)),this));
                    }
            }
        }
    }

    menu->addActions(listActionLanguage);

    return menu;
}

QString FindKeyboardLayoutClass::findNameLanguage(QByteArray By){

    QString text = By;
    QString name;

    for(int i = text.indexOf("WindowTitle=") + 12; text.at(i)!='\n'; i++)
        name += text.at(i);


    return name;
}
