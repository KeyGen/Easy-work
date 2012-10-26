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

#include "core.h"

//-- Интерфейсы плагинов --//
#include "CoreWidget_global.h"
#include "RegimeFile_global.h"
#include "Keyboard_global.h"
//-------------------------//

#include <QPluginLoader>
#include <QMenu>
#include <QDir>

void Core::loadPlugins(const QString dir) {

    const QDir pluginsDir(dir);

    QStringList filter;
    filter << "*.so";   // Для Linux
    filter << "*.dll";  // Для Windows

    foreach (QString fileName, pluginsDir.entryList(filter, QDir::Files))
    {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));

        if (loader.isLoaded())
        {
            qDebug() << QString("%1: %2 %3.").arg("Plugin file").arg(fileName).arg(QObject::tr("is already loaded"));
            continue;
        }

        if (loader.load() == false)
        {
            qDebug() << QString("%1 %2\n%3: %4").arg(QObject::tr("Can't load a plugin"))
                .arg(fileName).arg(QObject::tr("error"))
                .arg(loader.errorString());
        }
        else
        {
            QObject * obj = loader.instance();

            if (CoreWidget * plugin = qobject_cast<CoreWidget *>(obj))
            {
                installationsCoreWidget(plugin);
            }
            else if(RigimeFile * plugin = qobject_cast<RigimeFile *>(obj))
            {
                installationsRigimeFile(plugin);
            }
            else if(Keyboard * plugin = qobject_cast<Keyboard *>(obj))
            {
                installationsKeyboard(plugin);
            }

        }
    }
}

// Знагрузка найденных плагинов:
void Core::installationsCoreWidget(CoreWidget * plugin){

   qDebug() << plugin->getName() << plugin->getVersion();
   plugin->setMenuBar(coreMenu);
   this->setCentralWidget(plugin->getWidget());
   this->resize(plugin->getSize());

   connect(plugin,SIGNAL(siGetWidget(QWidget*)),this,SLOT(slSetCentralWidget(QWidget*)));
}

void Core::installationsRigimeFile(RigimeFile * plugin)
{
    qDebug() << plugin->getName() << plugin->getVersion();
    plugin->setMenuBar(coreMenu);

    connect(plugin,SIGNAL(siGetWidget(QWidget*)),this,SLOT(slSetCentralWidget(QWidget*)));
}

void Core::installationsKeyboard(Keyboard *plugin)
{
    qDebug() << plugin->getName() << plugin->getVersion();
    setting->addMenu(plugin->getMenu());
}
