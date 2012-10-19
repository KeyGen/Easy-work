#ifndef REGIME_OUTWARD_FILE_H
#define REGIME_OUTWARD_FILE_H

#include "regime_outward_file_global.h"

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
};


#endif // REGIME_OUTWARD_FILE_H
