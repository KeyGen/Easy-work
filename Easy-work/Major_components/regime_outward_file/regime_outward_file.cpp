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

#include "regime_outward_file.h"
#include "ui_outward_file.h"

#include <QTextCodec>
#include <QAction>

Q_EXPORT_PLUGIN(RegimeFileClass);

RegimeFileClass::RegimeFileClass() : ui(new Ui::Dialog)
{
    dialog = new QDialog();
    ui->setupUi(dialog);

    actionFile = new QAction(tr("Режим файла"),this);

    saveOutwardText = "Text для проверки кодировок";
    ui->textOutwardShow->setText(saveOutwardText);

    setCodecComboBox();

    connect(actionFile,SIGNAL(triggered()),dialog,SLOT(exec()));
    connect(ui->comboBoxCodec,SIGNAL(activated(QString)),this,SLOT(setCodec(QString)));
}

void RegimeFileClass::setCodecComboBox(){

    QStringList listCodec;
    // Вот некоторые кодеки из доступных в Qt
    listCodec << "Apple Roman";
    listCodec << "Big5";
    listCodec << "Big5-HKSCS";
    listCodec << "CP949";
    listCodec << "EUC-JP";
    listCodec << "EUC-KR";
    listCodec << "KOI8-R";
    listCodec << "KOI8-U";
    listCodec << "MuleLao-1";
    listCodec << "ROMAN8";
    listCodec << "Shift-JIS";
    listCodec << "TIS-620";
    listCodec << "TSCII";
    listCodec << "UTF-8";
    listCodec << "UTF-16";
    listCodec << "UTF-16BE";
    listCodec << "Windows-1250"; // to 1258
    listCodec << "Windows-1251"; // Русский

    // Добавим из в comboBox
    ui->comboBoxCodec->addItems(listCodec);
}

void RegimeFileClass::setCodec(QString nameCodec){

    // Выбор кодека
     QTextCodec *codec = QTextCodec::codecForName(nameCodec.toAscii());

     // Изменяем кодировку
     QByteArray encodedString = codec->fromUnicode(saveOutwardText);

     // В label вписываем текст с новой кодировкой
     ui->textOutwardShow->setText(encodedString);
}
