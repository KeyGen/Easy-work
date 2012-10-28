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

#include "corewidget.h"

#include "ui_corewidget.h"
#include <QMenuBar>
#include <QWidget>
#include <QSize>

Q_EXPORT_PLUGIN(CoreWidgetClass);

CoreWidgetClass::CoreWidgetClass()
{
    startRegime = new QAction(tr("Выйти из режима"),this);
    connect(startRegime,SIGNAL(triggered()),this,SLOT(slGetWidget()));
}

QWidget * CoreWidgetClass::getWidget() {

    menuBar = new QMenuBar();
    widget = new QWidget();
    ui = new Ui::CoreForm;
    ui->setupUi(widget);

    ui->centralGridLayout->setMenuBar(menuBar);

    for(int i = 0; i<listMenu.size(); i++)
    menuBar->addMenu(listMenu.at(i));

    return widget;
}

QSize CoreWidgetClass::getSize(){
    return widget->size();
}

void CoreWidgetClass::setMenuBar(QList <QMenu *> bar)
{
    listMenu = bar;

    if(!listMenu.isEmpty())
    listMenu.at(1)->addAction(startRegime);
}

void CoreWidgetClass::slGetWidget(){
    emit siGetWidget(getWidget());
}
