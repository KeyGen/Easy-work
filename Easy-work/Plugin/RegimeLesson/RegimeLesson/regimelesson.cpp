/**
 * Easy work - краткое описание на английском
 * Copyright (C) 2012 KeyGen <KeyGenQt@gmail.com>
 * https://github.com/KeyGen/Easy-work/wiki
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

#include "regimelesson.h"
#include "ui_regimeLesson.h"

#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QDesktopServices>
#include <QDesktopWidget>

#include <QInputDialog>
#include <QMessageBox>
#include <QResizeEvent>
#include <QAction>
#include <QMenuBar>
#include <QTimer>
#include <QDir>

Q_EXPORT_PLUGIN(RegimeLessonClass)

RegimeLessonClass::RegimeLessonClass(){

    calculateError = 0;
    destroyedBL = true;
    destroyedQml = true;
    startPrintLesson = false;
    startRegime = new QAction(tr("Режим урока"),this);
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    menuRegimeLesson = new QMenu(tr("Режим урока"));

    newUser = tr("Создать нового");
    saveUser << newUser;
}

QWidget* RegimeLessonClass::getWidget(){
    destroyedBL = false;

    menuBar = new QMenuBar();
    widget = new QWidget();
    ui = new Ui::FormRegimeLesson;
    ui->setupUi(widget);

    for(int i = 0; i<listMenu.size(); i++)
    menuBar->addMenu(listMenu.at(i));

    for(int i = 0; i<listMenu.size(); i++){
        if(i == 2)
            menuBar->addMenu(menuRegimeLesson);
        menuBar->addMenu(listMenu.at(i));
    }

    ui->gridLayout->setMenuBar(menuBar);
    ui->comboBox->addItems(saveUser);
    if(!userName.isEmpty())
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(userName));
    ui->widgetQmlLesson->close();

    lessonLanguage = base.getNameLesson();

    connect(widget,SIGNAL(destroyed()),this,SLOT(destroyedWidget()));
    disconnect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));

    return widget;
}

void RegimeLessonClass::destroyedWidget(){
    destroyedBL = true;
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
}

void RegimeLessonClass::slGetWidget(){
    emit siGetWidget(getWidget());
}

void RegimeLessonClass::setMenuBar(QList <QMenu *> bar)
{
    listMenu = bar;

    if(!listMenu.isEmpty())
    {
        listMenu.at(1)->addAction(startRegime);
    }
}

const QIcon RegimeLessonClass::getIcon(){
    const QIcon *ico = new QIcon(":/iconLesson");
    return *ico;
}

void RegimeLessonClass::addNewUser(){

    bool ok = true;

    while(ok){

        QInputDialog inputUserName;
        inputUserName.setWindowTitle(tr("Новый пользователь"));
        inputUserName.setLabelText(tr("Введите ник нового пользователя:"));
        inputUserName.setWindowFlags(Qt::Tool);
        inputUserName.setTextValue(QDir::home().dirName());

        QPoint center = screenCenter();
        QSize sizeUserNameDialog = inputUserName.sizeHint();
        inputUserName.move(center.x()-sizeUserNameDialog.width()/2-10,center.y()-sizeUserNameDialog.height()/2-20);
        ok = inputUserName.exec();

        QString text = inputUserName.textValue();

        if (ok && !text.isEmpty()){
            if(saveUser.contains(text)){
                messageBoxExec(tr("Такой ученик уже существует!\n"
                                  "Выберите другое имя или используйте уже доступное.\n\n"));
            }
            else{
                ok = false;
                saveUser << text;
                ui->comboBox->clear();
                ui->comboBox->addItems(saveUser);
                ui->comboBox->setCurrentIndex(ui->comboBox->findText(text));
            }
        }
        else{

            if(ok)
                messageBoxExec(tr("Поле пустое!\n"
                                  "Выберите другое имя или используйте уже доступное.\n\n"));
        }
    }
}

void RegimeLessonClass::on_pushButton_clicked()
{
    if(ui->comboBox->currentText() == newUser){
        addNewUser();
    }
    else{
        startQmlInput();
    }
}

void RegimeLessonClass::startQmlInput(){
    destroyedQml = false;
    userName = ui->comboBox->currentText();

    //Включаем наш QML
    ui_d = new QDeclarativeView();
    ui_d->setSource(QUrl("qrc:/mainLesson"));

    //Находим корневой элемент
    Root = ui_d->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент Qt_fun
    ui_d->rootContext()->setContextProperty("Qt_fun", this);

    ui->gridWidget->close();
    ui->widgetQmlLesson->show();
    ui->printWidget->close();
    ui->labelStart->close();
    ui->widgetQmlLesson->layout()->addWidget(ui_d);

    if(Root){
        Root->setProperty("width", QString::number(ui->widgetQmlLesson->width()+400));
        Root->setProperty("height", QString::number(ui->widgetQmlLesson->height()+200));
    }

    QObject *child = Root->findChild<QObject*>("setItemLanguageLessonF");
    if(child){
        child->setProperty("running","true");
    }
}

QString RegimeLessonClass::getLanguageLesson(int i){
    if(i<lessonLanguage.size())
        return lessonLanguage.at(i);
    else
        return "";
}

void RegimeLessonClass::readDBNameLesson(QString language){
    lesson = base.getLesson(language);
    authorName = base.getAuthorLessonName();
}

QString RegimeLessonClass::getNameLesson(int i){

    if(i<lesson.size()){
        return lesson.find(i+1).value().at(0);
    }
    else
        return "";
}

void RegimeLessonClass::startLesson(int i){

    workerText = lesson.find(i).value().at(1);
    ui_d->close();
    ui->labelStart->show();
    workerText = preparationText(workerText);
}

QString RegimeLessonClass::preparationText(QString text){

    text.replace('\n',' ');

    while(text.contains("  "))
        text.replace("  ", " ");

    if(text.at(0) == ' ')
        text = text.right(text.size()-1);

    if(text.at(text.size()-1) == ' ')
        text.chop(1);

    return text;
}

void RegimeLessonClass::slResizeEvent (QResizeEvent * event){

    saveSizeLabelInputAndShow.setHeight(event->size().height()-33);
    saveSizeLabelInputAndShow.setWidth(event->size().width()-14);

    if(!destroyedBL)
    {
        if(ui->labelInput->width() == 0){
            ui->labelStart->setMaximumSize(saveSizeLabelInputAndShow);
        }
        else {
            ui->labelInput->setMaximumWidth(saveSizeLabelInputAndShow.width()/2);
            ui->labelShow->setMaximumWidth(saveSizeLabelInputAndShow.width()/2);
            ui->labelStart->setMaximumSize(saveSizeLabelInputAndShow);
        }
    }

    if(!destroyedQml){
        if(Root){
            Root->setProperty("width", QString::number(ui->widgetQmlLesson->width()+400));
            Root->setProperty("height", QString::number(ui->widgetQmlLesson->height()+200));
        }
    }
}

void RegimeLessonClass::slKeyPressEvent (QKeyEvent *event){
    if(!destroyedBL){

        if(event->key() == Qt::Key_Backspace){
            if(startPrintLesson)
                stopPrint();
            startQmlInput();
        }

        if(startPrintLesson){

            if(event->key() == Qt::Key_CapsLock)
                emit siGetWord(ui->labelInput->text().at(0));

            if(startPrintLesson){
                if(event->key() != Qt::Key_Return){ // 16777220 - Enter
                    if(!event->text().isEmpty())
                        centralAdministration(event->text().at(0));
                }
                else{
                    stopPrint();
                }
            }
        }
        else{
            if(event->key() == Qt::Key_Space)
                startPrint();
        }
    }
}

void RegimeLessonClass::centralAdministration(QChar inputWord){

    if(!ui->labelInput->text().isEmpty()){
        if(ui->labelInput->text().at(0) == inputWord)
        {
            ui->labelShow->setText(ui->labelShow->text() + QString(inputWord));
            ui->labelInput->setText(ui->labelInput->text().right(ui->labelInput->text().size() - 1));

            if(ui->labelInput->text().isEmpty()){
                stopPrint();
            }
            else{
                emit siGetWord(ui->labelInput->text().at(0));
            }
        }
        else
        {
            calculateError++;

            if(calculateError>4)
                errorMax();

            labelSetStyleSheetError();
            emit siGetWord(ui->labelInput->text().at(0));
        }
    }
    else
    {
        stopPrint();
    }
}

void RegimeLessonClass::slKeyboardLanguageChange(){
    if(startPrintLesson)
        if(!ui->labelInput->text().isEmpty())
            emit siGetWord(ui->labelInput->text().at(0));
}

void RegimeLessonClass::labelSetStyleSheetDefault(){
    ui->labelInput->setStyleSheet("border-color: black; border-width: 2px 2px 2px 0px;");
    ui->labelShow->setStyleSheet("border-color: black; border-width: 2px 0px 2px 2px;");
}

void RegimeLessonClass::labelSetStyleSheetError(){

    ui->labelInput->setStyleSheet("border-color: red; border-width: 3px 3px 3px 0px;");
    ui->labelShow->setStyleSheet("border-color: red; border-width: 3px 0px 3px 3px;");

    QTimer::singleShot(200, this, SLOT(labelSetStyleSheetDefault()));
}

void RegimeLessonClass::errorMax()
{
    startPrintLesson = false;
    ui->labelStart->show();
    ui->printWidget->close();

    emit stopLesson();

    messageBoxExec(tr("Вы привысили максимальное количество допустимых ошибок\n"
                      "Урок прийдется начать заново"));

    ui->labelInput->clear();
    ui->labelShow->clear();
    calculateError = 0;
}

void RegimeLessonClass::stopPrint(){
    startPrintLesson = false;
    ui->labelStart->show();
    ui->printWidget->close();

    emit stopLesson();

    if(ui->labelInput->text().isEmpty())
    messageBoxExec(tr("Поздравляю Вы прошли урок!\n"
                      "Вы допустили ошибок:  ")
                       + QString::number(calculateError) +
                       tr("\nОценка:  ") + QString::number(5 - calculateError));

    ui->labelInput->clear();
    ui->labelShow->clear();
    calculateError = 0;
}

void RegimeLessonClass::startPrint(){

    ui->labelInput->setMaximumWidth(saveSizeLabelInputAndShow.width()/2);
    ui->labelInput->setMinimumWidth(10);
    ui->labelShow->setMaximumWidth(saveSizeLabelInputAndShow.width()/2);
    ui->labelShow->setMinimumWidth(10);

    startPrintLesson = true;
    ui->labelStart->close();
    ui->printWidget->show();
    ui->labelInput->setText(workerText);

    emit siGetWord(ui->labelInput->text().at(0));
}

QPoint RegimeLessonClass::screenCenter(){
    QDesktopWidget *desktop = QApplication::desktop();  // Определяем разрешение экрана
    return QPoint(desktop->width()/2,desktop->height()/2);
}

void RegimeLessonClass::messageBoxExec(QString text){

    QPoint center = screenCenter();
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Информация"));
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);

    msgBox.setText(text);

    msgBox.show();
    msgBox.move(center.x()-msgBox.width()/2,center.y()-msgBox.height()/2-20);
    msgBox.exec();
}
