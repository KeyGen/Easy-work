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
    virtual QString getName()       { return "Plugin Regime File - Open File"; }
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
    QString preparationText(QString);

private slots:
    void slSetNewTex();
    void setCodec(QString);
    void maskTextEdit(int in);
    void openFile();
    void setTexEdirWriteRead(bool);

signals:
    void siSetNewText(QString);
};

#endif // OPENFILE_H
