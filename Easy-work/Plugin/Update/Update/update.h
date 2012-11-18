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

#ifndef UPDATE_H
#define UPDATE_H

#include "Update_global.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
class QNetworkAccessManager;
class QNetworkReply;
class QProgressDialog;
class QDialog;
QT_END_NAMESPACE

namespace Ui {
class UpdateDialog;
}

class UpdateClass : public Update
{
    Q_OBJECT Q_INTERFACES(Update)

public:
    UpdateClass();

    virtual QString getVersion()    { return "1.0"; }
    virtual QString getName()       { return "Update"; }
    virtual QAction * getAction()   { return showDialogSettings; }

    virtual ~UpdateClass(){}

public slots:
    virtual void slSetSaveSetting(QStringList);
    virtual void slCloseEvent();

signals:
    void siSaveSetting(QStringList);
    void closeApplication();
    void siUdate(QString);

private:
    Ui::UpdateDialog *ui;
    QDialog *dialogUpdate;
    QAction *showDialogSettings;
    bool saveDialog;
    bool clickCheckForUpdates;
    bool boolSlCheckForUpdates;
    QStringList dateSaveDialog;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QString fileName;
    QString dateUpdate;
    QString pathHttp;
    QString pathTemp;

    QString updateOneDay;
    QString updateOneWeek;
    QString updateOneMonth;
    QProgressDialog *progress;
    QStringList updateDisk;
    bool downloadDisk;

    enum { MessageNo = 65536, MessageYes = 16384 };

private:
    void saveSetting();
    void checkForUpdates();
    bool WriteFile(QNetworkReply * networkReply);
    QString ReadFile(QString newCodec = "Windows-1251");

    void setPath(QString pathHttpF = "http://siteaac.narod.ru",
                 QString pathTempF = "../share/EasyWork/Database");

    QString findVersion(QString);
    void updateEasyWork();
    void StartCheckForUpdates(QString);

private slots:
    void dialogExec();
    void dialogSave();
    void dialogNotSave();
    void slCheckForUpdates();
    void replyFinished(QNetworkReply*);
    void replyFinishedFile(QNetworkReply*);
    void slBoolCheckForUpdates();
    void downloadProgress(qint64,qint64);
    void stopDownload();
};

#endif // UPDATE_H
