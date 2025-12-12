#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonArray>
#include <QJsonObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QAudioBufferOutput>
#include <QtSql/qsqldatabase.h>
#include <QListWidgetItem>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlError>
#include <QFile>
#include <QMessageBox>
#include <math.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:

    void downloadFile(QString url,QString savePath);
    void onFileDownloadFinished(QNetworkReply *reply, QString savePath);
    void on_player_positionChanged(qint64 position);
    void DownloadPlayer(QString album_id, QString hash);
    void showSearchResult(QByteArray jsonData);
    void loadLyric(QString musicId);
    void on_pause_clicked();
    void on_toolButton_clicked();

    void on_volume_sliderMoved(int position);
    void on_search_btn_clicked();
    void savePlayHistory(QString title, QString artist, QString path);
    void on_music_list_itemDoubleClicked(QListWidgetItem *item);

    void on_next_clicked();

    void on_pre_clicked();

private:
    bool initDatabase();
    // 加载历史记录到列表
    void loadHistoryRecord();
    // 保存播放记录到数据库

    QPoint m_mousepoint;
    QPoint movepoint;
    bool mousepress;
    QMediaPlayer * m_mediaplayer;
    QAudioOutput * m_audiooutput;
    QNetworkAccessManager *m_netManager;
    QSqlDatabase m_db;
    QString m_currentMusicPath;

};
#endif // MAINWINDOW_H
