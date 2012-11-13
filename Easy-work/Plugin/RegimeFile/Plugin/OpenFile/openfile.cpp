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

#include "openfile.h"
#include "ui_openfile.h"

#include <QDialog>
#include <QAction>
#include <QFileDialog>
#include <QTextCodec>

Q_EXPORT_PLUGIN(OpenFileClass)

OpenFileClass::OpenFileClass() : ui(new Ui::DialogOpenFile)
{
    dialog =  new QDialog();
    ui->setupUi(dialog);

    actionOpenFile = new QAction(tr("Загрузить файл"),this);

    #ifdef Q_OS_WIN32
        defaultCodec = "Windows-1251";
    #else
        defaultCodec = "UTF-8";
    #endif

    ui->sliderPositionInText->setMaximum(0);
    ui->boxPositionInText->setMaximum(0);

    setCodecComboBox();

    connect(ui->pushSave,SIGNAL(clicked()),this,SLOT(slSetNewTex()));
    connect(actionOpenFile,SIGNAL(triggered()),this,SIGNAL(activatedOpenFile()));
    connect(ui->pushClose,SIGNAL(clicked()),this,SLOT(setDefaultSetting()));
    connect(dialog,SIGNAL(rejected()),this,SLOT(setDefaultSetting()));
    connect(actionOpenFile,SIGNAL(triggered()),this,SLOT(exec()));
    connect(ui->comboBoxCodec,SIGNAL(activated(QString)),this,SLOT(setCodec(QString)));
    connect(ui->pushOutwordFile,SIGNAL(clicked()),this,SLOT(openFile()));
    connect(ui->boxPositionInText,SIGNAL(valueChanged(int)),ui->sliderPositionInText,SLOT(setValue(int)));
    connect(ui->sliderPositionInText,SIGNAL(sliderMoved(int)),ui->boxPositionInText,SLOT(setValue(int)));
    connect(ui->boxPositionInText,SIGNAL(valueChanged(int)),this,SLOT(maskTextEdit(int)));

    connect(ui->pushSave,SIGNAL(clicked()),dialog,SLOT(close()));
    connect(ui->pushClose,SIGNAL(clicked()),dialog,SLOT(close()));
}

void OpenFileClass::setDefaultSetting(){

    if(!save){
        if(!saveSetting.at(0).isEmpty())
        {
            QFile test(saveSetting.at(0));
            if(test.open(QIODevice::ReadOnly)){

                ui->lineEditPath->setText(saveSetting.at(0));
                ui->comboBoxCodec->setCurrentIndex(ui->comboBoxCodec->findText(saveSetting.at(1)));
                readFileAndSetText(ui->lineEditPath->text());
                ui->boxPositionInText->setValue(saveSetting.at(2).toInt());
            }
        }
        else{
            ui->lineEditPath->clear();
            ui->textOutwardShow->clear();
            ui->sliderPositionInText->setMaximum(0);
            ui->boxPositionInText->setMaximum(0);
            saveOutwardText.clear();
            ui->comboBoxCodec->setCurrentIndex(ui->comboBoxCodec->findText(saveSetting.at(1)));
            ui->boxPositionInText->setValue(saveSetting.at(2).toInt());
        }
    }
}

void OpenFileClass::exec(){
    save = false;
    saveSetting.clear();
    saveSetting << ui->lineEditPath->text();
    saveSetting << ui->comboBoxCodec->currentText();
    saveSetting << QString::number(ui->boxPositionInText->value());

    dialog->exec();
}

void OpenFileClass::slSetNewTex(){
    save = true;
    if(!ui->textOutwardShow->toPlainText().isEmpty())
    emit siSetNewText(preparationText(ui->textOutwardShow->toPlainText()));
}

QString OpenFileClass::preparationText(QString text){

    text.replace('\n',' ');

    while(text.contains("  "))
        text.replace("  ", " ");

    if(text.at(0) == ' ')
        text = text.right(text.size()-1);

    if(text.at(text.size()-1) == ' ')
        text.chop(1);

    return text;
}

QString OpenFileClass::preparationTextSimbol(QString text){

    text.replace("—","-");
    text.replace("«","\"");
    text.replace("»", "\"");
    text.replace("“", "\"");
    text.replace("”", "\"");
    text.replace("„", "\"");

    return text;
}

void OpenFileClass::maskTextEdit(int in)
{
    ui->textOutwardShow->setText(saveOutwardText.right(saveOutwardText.size()-in));
}

void OpenFileClass::openFile()
{
    QString path   = QFileDialog::getOpenFileName(ui->gridWidget,
                                                 tr("Open files"),
                                                  "/home",
                                                  tr("*.txt (*.txt)"));

    if(!path.isEmpty())
    {
        readFileAndSetText(path);
    }
}

bool OpenFileClass::readFileAndSetText(QString path){

    QFile read_file(path);

    if(read_file.open(QIODevice::ReadOnly)) // чтение *txt
    {
        QTextStream out(&read_file);
        out.setCodec(ui->comboBoxCodec->itemText(ui->comboBoxCodec->currentIndex()).toAscii());
        saveOutwardText = preparationTextSimbol(out.readAll());

        while(saveOutwardText.at(saveOutwardText.size()-1) == ' '
              || saveOutwardText.at(saveOutwardText.size()-1) == '\n')
            saveOutwardText.chop(1);


        ui->textOutwardShow->setText(saveOutwardText);       // Считываем весь файл в QString

        ui->lineEditPath->setText(path);
        ui->sliderPositionInText->setValue(0);
        ui->boxPositionInText->setValue(0);
        ui->sliderPositionInText->setMaximum(saveOutwardText.size()-1);
        ui->boxPositionInText->setMaximum(saveOutwardText.size()-1);

        return true;
    }

    return false;
}

void OpenFileClass::setCodecComboBox(){

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
    ui->comboBoxCodec->setCurrentIndex(ui->comboBoxCodec->findText(defaultCodec));
}

void OpenFileClass::setCodec(QString nameCodec){

    // Выбор кодека
     QTextCodec *codec = QTextCodec::codecForName(nameCodec.toAscii());

     // Изменяем кодировку
     QByteArray encodedString = codec->fromUnicode(saveOutwardText);

     // В label вписываем текст с новой кодировкой
     ui->textOutwardShow->setText(encodedString);
}

QStringList OpenFileClass::getSettings(){

    QStringList listSettings;
    listSettings << ui->lineEditPath->text();
    listSettings << ui->comboBoxCodec->currentText();
    listSettings << QString::number(ui->boxPositionInText->value());

    return listSettings;
}

void OpenFileClass::setSettings(QStringList listSettings){

    if(!listSettings.isEmpty()){
        if(listSettings.at(0) == "RegimeFile"){

            if(!listSettings.at(1).isEmpty()){
                QFile test(listSettings.at(1));
                if(test.open(QIODevice::ReadOnly)){

                    ui->lineEditPath->setText(listSettings.at(1));

                    defaultCodec = listSettings.at(2);
                    ui->comboBoxCodec->setCurrentIndex(ui->comboBoxCodec->findText(listSettings.at(2)));

                    if(!readFileAndSetText(ui->lineEditPath->text()))
                        qDebug() << "файл не найден";

                    ui->boxPositionInText->setValue(listSettings.at(3).toInt());

                    slSetNewTex();
                }
                else
                    ui->lineEditPath->setText(tr(""));
            }
        }
    }
}

void OpenFileClass::setBoxPosition(QChar findStr){

    if(findStr != ' '){
        ui->boxPositionInText->setValue(
                    ui->textOutwardShow->toPlainText().indexOf(findStr)
                    + ui->boxPositionInText->value());
    }
    else{
        bool stop = false;
        QString text = ui->textOutwardShow->toPlainText();

        for(int i = 0; i<text.size(); i++){
            if(text.at(i) == ' '||text.at(i) == '\n'){
                for(int j = i+1; j<text.size(); j++){
                    if(text.at(j) != ' '&&text.at(j) != '\n'){
                        ui->boxPositionInText->setValue((j) + ui->boxPositionInText->value());
                        stop = true;
                        break;
                    }
                }
            }
            if(stop)
                break;
        }
    }
}

QString OpenFileClass::getAllText(){
    ui->boxPositionInText->setValue(0);
    return preparationText(ui->textOutwardShow->toPlainText());
}
