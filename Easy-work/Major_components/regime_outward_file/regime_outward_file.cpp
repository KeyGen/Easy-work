#include "regime_outward_file.h"
#include "ui_outward_file.h"
#include <QAction>

Q_EXPORT_PLUGIN(RegimeFileClass);

RegimeFileClass::RegimeFileClass() : ui(new Ui::Dialog)
{
    dialog = new QDialog();
    ui->setupUi(dialog);

    actionFile = new QAction(tr("Режим файла"),this);

    connect(actionFile,SIGNAL(triggered()),dialog,SLOT(exec()));
}
