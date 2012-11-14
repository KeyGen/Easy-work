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

#include "style.h"

#include "qzipreader_p.h"

#include <QMenu>
#include <QDir>

Q_EXPORT_PLUGIN(StyleClass)

StyleClass::StyleClass(){
    menu = new QMenu(tr("Стили"));
}

StyleClass::~StyleClass(){
}

void StyleClass::slCloseEvent (){
    saveSetting();
    removeTempFolderPath();
}

QString StyleClass::readStyleSheet(QString path){

    QFile read_file(path);

    if(read_file.open(QIODevice::ReadOnly))
    {
        QTextStream out(&read_file);
        return out.readAll();
    }

    return "";
}

QMenu * StyleClass::createZipStyle(QString path)
{
    tempFolderPath = path + "/readStyle";

    QDir dir(path.toAscii());    // Создаем QDir в указанном пути (path)

    QStringList filters;
    filters << "*.style";

    QStringList files = dir.entryList(filters);

    listAction.append(new QAction(tr("Стандартная"),this));
    listAction.last()->setCheckable(true);
    connect(listAction.last(),SIGNAL(triggered()),this,SLOT(slotActivateCSS()));
    menu->addAction(listAction.last());

    for(int i = 0; i<files.size(); i++ )
    {
        QZipReader zip_reader(path.toAscii()  + "/" +  files.at(i).toAscii());

        if (zip_reader.exists()) {          // Если все чудно

            foreach (QZipReader::FileInfo info, zip_reader.fileInfoList()) {
                if(info.filePath.contains(".style")){
                    //qDebug() << "Файл:" << info.filePath << "Размер:" << info.size; // размер извлекаемого файла
                    listAction.append(new QAction (findStyleName(zip_reader.fileData(info.filePath)),this));
                    listAction.last()->setCheckable(true);
                    connect(listAction.last(),SIGNAL(triggered()),this,SLOT(slotActivateCSS()));
                    menu->addAction(listAction.last());
                }
            }
        }
    }

    menu->setStyleSheet(
                        "QMenu::indicator {"
                        "background: #505050;"
                        "}"

                        "QMenu::indicator:non-exclusive:unchecked:selected {"
                        "background: #228B22;"
                        "}"
                        );

    return menu;
}

QString StyleClass::findStyleName(QByteArray byte, QString language){

    QString allFile = byte;
    QString name;

    for(int i = allFile.indexOf(language + ":") + language.size() + 1; allFile.at(i)!='\n'; i++)
        name += allFile.at(i);

    if(!name.isEmpty())
    {
        while(name.at(0) == ' ')
            name = name.right(name.size()-1);
    }

    return name;
}

void StyleClass::slotActivateCSS()
{

    for(int i = 0; i<listAction.size(); i++)
    {
        if(listAction.at(i)->isChecked())
        {
            getStyleForName(listAction.at(i)->text());

            for(int j = 0; j<listAction.size(); j++)
            {
                listAction.at(j)->setChecked(false);
            }

            break;
        }
    }
}

void StyleClass::getStyleForName(QString nameFind, QString path){

    saveNaemStile = nameFind;
    bool endCycle = false;
    QDir dir(path.toAscii());    // Создаем QDir в указанном пути (path)

    QStringList filters;
    filters << "*.style";

    QStringList files = dir.entryList(filters);

    for(int i = 0; i<files.size(); i++ )
    {
        QZipReader zip_reader(path.toAscii() + "/" + files.at(i).toAscii());

        if (zip_reader.exists()) {          // Если все чудно

            foreach (QZipReader::FileInfo info, zip_reader.fileInfoList()) {
                if(info.filePath.contains(".style")){
                    if(nameFind == findStyleName(zip_reader.fileData(info.filePath))){

                        if(zip_reader.count() == 1){
                            removeTempFolderPath();
                            emit getStyle(QString(zip_reader.fileData(info.filePath)));
                        }
                        else{
                            removeTempFolderPath();
                            QDir createFolder;
                            createFolder.mkdir(tempFolderPath);
                            zip_reader.extractAll(tempFolderPath);
                            emit getStyle(readStyleSheet(tempFolderPath + "/" + info.filePath));
                        }

                        endCycle = true;
                        break;
                    }
                }
            }
        }

        if(endCycle)
            break;
    }

    if(!endCycle)
        emit getStyle(readStyleSheet());
}

void StyleClass::removeTempFolderPath(){

    QDir dir(tempFolderPath.toAscii());

    if(!dir.entryList().isEmpty()){

        QStringList filesList = dir.entryList();

        for (int i = 0; i < filesList.size(); ++i)
            dir.remove(filesList.at(i));

        dir.cdUp();
        dir.rmdir(tempFolderPath.split("/").last());
    }
}

