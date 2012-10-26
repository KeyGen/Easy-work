#ifndef OPENFILE_H
#define OPENFILE_H

#include "OpenFile_global.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
class QDialog;
QT_END_NAMESPACE

namespace Ui {
class DialogOpenFile;
}

class OpenFileClass : public OpenFile
{
    Q_OBJECT Q_INTERFACES(OpenFile)

public:
    OpenFileClass();
    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Open File"; }
    virtual QAction * getAction()   { return actionOpenFile; }

    virtual ~OpenFileClass() {}

private:
    Ui::DialogOpenFile *ui;
    QDialog *dialog;
    QAction *actionOpenFile;
    QString saveOutwardText;
    QString defaultCodec;

private:
    void setCodecComboBox();

private slots:
    void slSetNewTex();
    void setCodec(QString);
    void maskTextEdit(int in);
    void openFile();
    void setTexEdirWriteRead(bool);

signals:
    virtual void siSetNewText(QString);
};

#endif // OPENFILE_H
