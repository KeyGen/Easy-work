#include "mainwindow.h"
#include "ui_mainwindow.h"

// Интерфейсы плагинов
#include "what_is_global.h"
#include "style_css_global.h"

#include <QPluginLoader>
#include <QDialog>
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pathPluginDir = "../../readyPlugins";

    loadPlugins(pathPluginDir);

    ui->inputText->setFixedWidth(400);
    ui->showText->setFixedWidth(400);
}

void MainWindow::loadPlugins(const QString dir) {

    const QDir pluginsDir(dir);

    QStringList filter;
    filter << "*.so";

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

            if (WhatIs * plugin = qobject_cast<WhatIs *>(obj))
            {
                m_modules.insert(plugin->getName(), plugin);
                ui->help->addAction(plugin->getAction());

            }
            else if(StyleCSS *pluginCss = qobject_cast<StyleCSS *>(obj))
            {
                ui->setting->addActions(pluginCss->getActions());

                connect(pluginCss,SIGNAL(getStyle(QString)),this,SLOT(setStyleSheet(QString)));
            }

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}