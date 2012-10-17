#include "what_is.h"
#include "ui_ui_whatIs.h"

#include <QDialog>
#include <QAction>

Q_EXPORT_PLUGIN(WhatIsClass);

WhatIsClass::WhatIsClass() : ui(new Ui::Dialog) {

    dialog = new QDialog();
    ui->setupUi(dialog);
    action = new QAction(tr("О программе"),this);

    connect(action,SIGNAL(triggered()),dialog,SLOT(exec()));
}

void WhatIsClass::exec()
{
    dialog->exec();
}

QAction* WhatIsClass::getAction()
{
    return action;
}

void WhatIsClass::renameAction(QString str)
{
    action->setText(str);
}
