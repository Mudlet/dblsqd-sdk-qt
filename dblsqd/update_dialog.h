#ifndef DBLSQD_UPDATE_DIALOG_H
#define DBLSQD_UPDATE_DIALOG_H

#include "dblsqd/feed.h"
#include "ui_update_dialog.h"
#include <QSettings>
#include <QTemporaryFile>
#include <QFile>
#include <QMessageBox>
#include <QDesktopServices>

namespace dblsqd {

class UpdateDialog : public QDialog
{
    Q_OBJECT

public:
    enum Type {OnUpdateAvailable, OnLastWindowClosed, Manual, ManualChangelog};
    explicit UpdateDialog(Feed* feed, int = OnUpdateAvailable, QWidget* parent = 0, QSettings* settings = new QSettings());
    ~UpdateDialog();

    void setIcon(QString fileName);
    void setIcon(QPixmap pixmap);
    void addInstallButton(QAbstractButton* button);

signals:
    void ready();
    void installButtonClicked(QAbstractButton* button, QString filePath);

public slots:
    void onButtonInstall();
    void onButtonCustomInstall();
    void skip();
    void showIfUpdatesAvailable();
    void showIfUpdatesAvailableOrQuit();

private:
    Ui::UpdateDialog* ui;
    Feed* feed;
    int type;

    QSettings* settings;
    QString settingsGroup;
    void setSettingsValue(QString key, QVariant value);
    QVariant settingsValue(QString key, QVariant defaultValue = QVariant());
    void removeSetting(QString key);
    void replaceAppVars(QString& string);
    QString generateChangelogDocument();

    void disableButtons(bool disable = true);
    void resetUi();
    void setupLoadingUi();
    void setupUpdateUi();
    void setupChangelogUi();
    void setupNoUpdatesUi();

    void startDownload();
    virtual void startUpdate();

    bool accepted;
    bool isDownloadFinished;
    QString updateFilePath;
    QList<Release> updates;
    Release latestRelease;
    QList<QAbstractButton*> installButtons;
    QAbstractButton* acceptedInstallButton;

private slots:
    void toggleAutoDownloads(bool);
    void handleFeedReady();
    void handleDownloadFinished();
    void handleDownloadError(QString);
    void updateProgressBar(qint64, qint64);
};

} //namespace dblsqd

#endif // DBLSQD_UPDATE_DIALOG_H
