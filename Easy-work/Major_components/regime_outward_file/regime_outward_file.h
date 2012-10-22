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

#ifndef REGIME_OUTWARD_FILE_H
#define REGIME_OUTWARD_FILE_H

#include "regime_outward_file_global.h"
#include <QDebug>

namespace Ui {
class Dialog;
}

QT_BEGIN_NAMESPACE
class QDialog;
QT_END_NAMESPACE

class RegimeFileClass : public RegimeFile
{
    Q_OBJECT Q_INTERFACES(RegimeFile)

public:
    RegimeFileClass();

    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Regime File"; }
    virtual QAction* getActions()   { return actionFile; }

    virtual ~RegimeFileClass() {}

private:
    QAction *actionFile;
    QDialog *dialog;
    Ui::Dialog *ui;
    QString saveOutwardText;

    void setCodecComboBox();

private slots:
    void setCodec(QString);
};


#endif // REGIME_OUTWARD_FILE_H
