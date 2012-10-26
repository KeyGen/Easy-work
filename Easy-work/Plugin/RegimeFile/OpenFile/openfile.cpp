#include "openfile.h"
#include "ui_openfile.h"

#include <QDialog>
#include <QAction>
#include <QFileDialog>
#include <QTextCodec>

Q_EXPORT_PLUGIN(OpenFileClass);

OpenFileClass::OpenFileClass() : ui(new Ui::DialogOpenFile)
{
    dialog =  new QDialog();
    ui->setupUi(dialog);

    actionOpenFile = new QAction(tr("Загрузить файл"),this);

    saveOutwardText = "Text для проверки кодировок";
    defaultCodec = "UTF-8";

    ui->sliderPositionInText->setMaximum(saveOutwardText.size()-1);
    ui->boxPositionInText->setMaximum(saveOutwardText.size()-1);

    ui->textOutwardShow->setText(saveOutwardText);

    setCodecComboBox();

    connect(actionOpenFile,SIGNAL(triggered()),dialog,SLOT(exec()));
    connect(ui->pushSave,SIGNAL(clicked()),this,SLOT(slSetNewTex()));
    connect(ui->comboBoxCodec,SIGNAL(activated(QString)),this,SLOT(setCodec(QString)));
    connect(ui->checkBox,SIGNAL(clicked(bool)),this,SLOT(setTexEdirWriteRead(bool)));
    connect(ui->pushOutwordFile,SIGNAL(clicked()),this,SLOT(openFile()));
    connect(ui->boxPositionInText,SIGNAL(valueChanged(int)),ui->sliderPositionInText,SLOT(setValue(int)));
    connect(ui->sliderPositionInText,SIGNAL(sliderMoved(int)),ui->boxPositionInText,SLOT(setValue(int)));
    connect(ui->boxPositionInText,SIGNAL(valueChanged(int)),this,SLOT(maskTextEdit(int)));
}

void OpenFileClass::slSetNewTex(){
    if(!ui->textOutwardShow->toPlainText().isEmpty())
    emit siSetNewText(ui->textOutwardShow->toPlainText());
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
        QFile read_file(path);
        if(read_file.open(QIODevice::ReadOnly)) // чтение *txt
        {
            QTextStream out(&read_file);
            out.setCodec(ui->comboBoxCodec->itemText(ui->comboBoxCodec->currentIndex()).toAscii());
            saveOutwardText = out.readAll();
            ui->textOutwardShow->setText(saveOutwardText);       // Считываем весь файл в QString
        }

        ui->lineEditPath->setText(path);
        ui->sliderPositionInText->setValue(0);
        ui->boxPositionInText->setValue(0);
        ui->sliderPositionInText->setMaximum(saveOutwardText.size()-1);
        ui->boxPositionInText->setMaximum(saveOutwardText.size()-1);
    }
}

void OpenFileClass::setTexEdirWriteRead(bool BL)
{
    ui->textOutwardShow->setReadOnly(BL);
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
