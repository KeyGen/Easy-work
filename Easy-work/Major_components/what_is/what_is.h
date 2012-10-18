#ifndef WHAT_IS_H
#define WHAT_IS_H

#include "what_is_global.h"

namespace Ui {
class Dialog;
}

class WhatIsClass : public WhatIs
{
    Q_OBJECT Q_INTERFACES(WhatIs)

public:

    explicit WhatIsClass();
    virtual ~WhatIsClass(){}


    virtual QString getVersion() { return "1.0"; }
    virtual QString getName()    { return "What is"; }
    virtual QAction* getAction();
    virtual void renameAction(QString);

public slots:
    virtual void exec();

private:
    Ui::Dialog *ui;
    QDialog *dialog;
    QAction *action;
};

#endif // WHAT_IS_H