#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>

namespace Ui {
class MainWindow;
}

QT_BEGIN_NAMESPACE
class WhatIs;
class QDialog;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QDialog *dialog;
    QString pathPluginDir;
    void loadPlugins(const QString dirPlugins);
    QHash<QString, WhatIs *> m_modules;
};

#endif // MAINWINDOW_H
