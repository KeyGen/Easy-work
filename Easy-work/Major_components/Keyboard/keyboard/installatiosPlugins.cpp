#include "keyboard.h"
#include "downloadLanguageKeyboard_global.h"

#include <QPluginLoader>
#include <QMenu>
#include <QDebug>
#include <QDir>

void KeyboardClass::loadPlugins(const QString dir) {

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

            if (KeyboardLanguage * plugin = qobject_cast<KeyboardLanguage *>(obj))
            {
                menu->addMenu(plugin->getMenu());

                this->setKeyLanguage(plugin->getLanguageHash(),false);

                connect(plugin,SIGNAL(getLanguage(QMultiHash<QString, QString>,bool)),
                        this,SLOT(setKeyLanguage(QMultiHash<QString, QString>,bool)));

            }
        }
    }
}

