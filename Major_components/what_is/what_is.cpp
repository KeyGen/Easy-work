#include "what_is.h"
#include "ui_ui_whatIs.h"
#include <QDialog>

Q_EXPORT_PLUGIN(WhatIsClass);

WhatIsClass::WhatIsClass() : ui(new Ui::Dialog) {
    dialog = new QDialog();
    ui->setupUi(dialog);
}

void WhatIsClass::exec()
{
    dialog->exec();
}
