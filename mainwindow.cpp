#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    bool isSliderMoved=false;
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowFlag(Qt::FramelessWindowHint);


    m_mediaplayer=new QMediaPlayer(this);
    m_audiooutput=new QAudioOutput(this);

    m_mediaplayer->setAudioOutput(m_audiooutput);


   //进度条正常移动
    connect(m_mediaplayer, &QMediaPlayer::positionChanged, this, &MainWindow::on_player_positionChanged);
     //进度条拖动
    connect(m_mediaplayer, &QMediaPlayer::durationChanged, this, [this](qint64 duration) {
        ui->processbar->setRange(0, duration);
    });


    // 1. 拖动开始时暂停
    connect(ui->processbar, &QSlider::sliderPressed, this, [&isSliderMoved,this]() {
        m_mediaplayer->pause(); // 暂停播放
        isSliderMoved = true;
    });

    // 2. 拖动结束时跳转并继续播放（sliderReleased 无参数，需通过 slider->value() 获取位置）
    connect(ui->processbar, &QSlider::sliderReleased, this, [&isSliderMoved, this]() {
        if (isSliderMoved) {
            int position = ui->processbar->value(); // 获取滑块当前位置
            m_mediaplayer->setPosition(static_cast<qint64>(position)); // 跳转位置
            m_mediaplayer->play(); // 继续播放
            isSliderMoved = false;
        }
    });

    m_netManager=new QNetworkAccessManager(this);
    if (!initDatabase()) {
        qDebug() << "数据库初始化失败";
    } else {
        loadHistoryRecord(); // 加载历史记录
    }




}

MainWindow::~MainWindow()
{ m_db.close();
    delete ui;
}
bool MainWindow::initDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(QDir::currentPath() + "/music_history.db"); // 数据库文件

    if (!m_db.open()) {
        qDebug() << "数据库打开失败：" << m_db.lastError().text();
        return false;
    }

    // 创建历史记录表
    QSqlQuery query;
    QString createTableSql = R"(
        CREATE TABLE IF NOT EXISTS play_history (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            artist TEXT NOT NULL,
            path TEXT NOT NULL,
            play_time DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    )";
    if (!query.exec(createTableSql)) {
        qDebug() << "创建表失败：" << query.lastError().text();
        return false;
    }
    return true;
}
void MainWindow::DownloadPlayer(QString album_id, QString hash)
{
QNetworkRequest netRequest;
     netRequest.setUrl(QUrl("http://localhost:5000/api/music/info"));

}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(mousepress){
        QPoint movePos=event->globalPos();
        move(movePos-movepoint);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        mousepress=true;
    }
    movepoint=event->globalPos()-pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
     mousepress=false;
}
void MainWindow::on_toolButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_volume_sliderMoved(int position)
{
    ui->volume_value->setText(QString::number(position));
    qreal volume = static_cast<qreal>(position) / 100.0;
    m_audiooutput->setVolume(volume);

    qDebug() << "设置音量：" << volume << "实际音量：" << m_audiooutput->volume();
}



void MainWindow::showSearchResult(QByteArray jsonData)
{
    ui->music_list->clear();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (!doc.isArray()) return;

    QJsonArray musicArray = doc.array();
    for (const QJsonValue &val : musicArray) {
        QJsonObject obj = val.toObject();
        QString itemText = QString("%1 - %2").arg(obj["title"].toString()).arg(obj["artist"].toString());
        QListWidgetItem *item = new QListWidgetItem(itemText);
        // 存储歌曲ID和路径（自定义数据）
        item->setData(Qt::UserRole, obj["id"].toString());
        item->setData(Qt::UserRole + 1, obj["audio_path"].toString());
        ui->music_list->addItem(item);
    }
}


void MainWindow::loadLyric(QString musicId)
{
    ui->lyric->clear();

    QString url = QString("http://localhost:5000/api/music/lyric?id=%1").arg(musicId);
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply *reply = m_netManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            ui->lyric->setPlainText(reply->readAll());

        } else {
            ui->lyric->setPlainText("歌词加载失败");
        }
        reply->deleteLater();
    });
}
void MainWindow::loadHistoryRecord()
{
    ui->history->clear();
    QSqlQuery query("SELECT title, artist, play_time FROM play_history ORDER BY play_time DESC");

    while (query.next()) {
        QString title = query.value("title").toString();
        QString artist = query.value("artist").toString();
        QString time = query.value("play_time").toString();
        QString itemText = QString("%1 - %2 [%3]").arg(title).arg(artist).arg(time);
        ui->history->addItem(itemText);
    }
}
void MainWindow::on_player_positionChanged(qint64 position)
{
    ui->processbar->setValue(position);
    // 转换为时间格式（mm:ss）
    qint64 sec = position / 1000;
    QString timeStr = QString("%1:%2").arg(sec / 60, 2, 10, QChar('0')).arg(sec % 60, 2, 10, QChar('0'));
    ui->timer->setText(timeStr);
}

void MainWindow::on_pause_clicked()
{

    if (m_mediaplayer->playbackState() == QMediaPlayer::PlayingState) {
        m_mediaplayer->pause();
        ui->pause->setIcon(this->style()->standardIcon(QStyle::SP_MediaPlay));
    } else {
        m_mediaplayer->play();
        ui->pause->setIcon(this->style()->standardIcon(QStyle::SP_MediaPause));
    }
}


void MainWindow::on_search_btn_clicked()
{
    QString keyword=ui->search_box->text().trimmed();
    QString url = QString("http://localhost:5000/api/music/search?keyword=%1").arg(keyword);
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply *reply = m_netManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            showSearchResult(reply->readAll());
        } else {
            qDebug() << "搜索请求失败：" << reply->errorString();
        }
        reply->deleteLater();
    });
}
void MainWindow::savePlayHistory(QString title, QString artist, QString path)
{
    QSqlQuery query;
    query.prepare("INSERT INTO play_history (title, artist, path) VALUES (:title, :artist, :path)");
    query.bindValue(":title", title);
    query.bindValue(":artist", artist);
    query.bindValue(":path", path);
    if (!query.exec()) {
        qDebug() << "保存历史记录失败：" << query.lastError().text();
    }
}
void MainWindow::downloadFile(QString url, QString savePath)
{
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply *reply = m_netManager->get(request);

    // 绑定下载完成信号，传递保存路径
    connect(reply, &QNetworkReply::finished, this, [=]() {
        onFileDownloadFinished(reply, savePath);
    });
}
void MainWindow::onFileDownloadFinished(QNetworkReply *reply, QString savePath)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "下载失败：" << reply->errorString();
        reply->deleteLater();
        return;
    }

    // 创建保存目录（如：./downloads/）
    QDir saveDir(QFileInfo(savePath).path());
    if (!saveDir.exists()) {
        saveDir.mkpath(".");
    }

    // 写入文件到本地
    QFile file(savePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(reply->readAll());
        file.close();
        qDebug() << "文件保存成功：" << savePath;

        // 若是音频文件，自动播放
        if (savePath.endsWith(".mp3")) {
            m_mediaplayer->setSource(QUrl::fromLocalFile(savePath));
            m_mediaplayer->play();
            ui->pause->style()->standardIcon(QStyle::SP_MediaStop);
        }
        // 若是歌词文件，加载显示
        else if (savePath.endsWith(".lrc")) {
            QFile lyricFile(savePath);
            if (lyricFile.open(QIODevice::ReadOnly|QIODevice::Text)) {
                QByteArray data = lyricFile.readAll();
                lyricFile.close();

                // 尝试解析编码（优先 UTF-8，失败则尝试本地编码）
                QString lyric;
                QString formattedLyric;
                lyric = QString::fromUtf8(data); // UTF-8 编码
                for (int i = 0; i < lyric.size(); ++i) {
                    QChar c = lyric.at(i);
                    if (c == '[' && i > 0) { // 跳过第一个字符为 '[' 的情况
                        formattedLyric += '\n'; // 插入换行
                    }
                    formattedLyric += c;
                }
                ui->lyric->setPlainText(formattedLyric);
                lyricFile.close();
            }
        }
    } else {
        qDebug() << "文件保存失败：" << file.errorString();
    }

    reply->deleteLater();
}

void MainWindow::on_music_list_itemDoubleClicked(QListWidgetItem *item)
{
    QString musicId = item->data(Qt::UserRole).toString();
    QStringList titleArtist = item->text().split(" - ");
    QString title = titleArtist[0];
    QString artist = titleArtist[1];

    // 2. 先请求歌曲完整信息（含本地文件名）
    QString infoUrl = QString("http://localhost:5000/api/music/info/%1").arg(musicId);
    QNetworkRequest infoRequest;
    infoRequest.setUrl(QUrl(infoUrl));
    QNetworkReply *infoReply = m_netManager->get(infoRequest);

    connect(infoReply, &QNetworkReply::finished, this, [=]() {
        if (infoReply->error() == QNetworkReply::NoError) {
            // 解析歌曲信息
            ui->pause->setIcon(this->style()->standardIcon(QStyle::SP_MediaPause));
            QJsonDocument doc = QJsonDocument::fromJson(infoReply->readAll());
            QJsonObject obj = doc.object();
            QString audioDownloadUrl = obj["audio_path"].toString();
            QString localAudioName = obj["local_audio_name"].toString();
            QString localLyricName = obj["local_lyric_name"].toString();

            // 3. 定义本地保存路径（如：./downloads/1.mp3）
            QString saveDir = QDir::currentPath() + "/downloads/";
            QString audioSavePath = saveDir + localAudioName;
            QString lyricSavePath = saveDir + localLyricName;

            // 4. 先下载音频文件（自动播放）
            downloadFile("http://localhost:5000" + audioDownloadUrl, audioSavePath);
            // 5. 再下载歌词文件（自动显示）
            downloadFile(QString("http://localhost:5000/api/music/lyric?id=%1").arg(musicId), lyricSavePath);

            // 6. 保存播放历史（本地路径）
            savePlayHistory(title, artist, audioSavePath);
            loadHistoryRecord();
        } else {
            qDebug() << "获取歌曲信息失败：" << infoReply->errorString();
        }
        infoReply->deleteLater();
    });
}



void MainWindow::on_next_clicked()
{
    auto itemIndex=ui->music_list->currentRow();
    QListWidgetItem *nextItem;
    if(itemIndex+1<ui->music_list->count())
        nextItem=ui->music_list->item(itemIndex+1);
    else
        return;
    on_music_list_itemDoubleClicked(nextItem);

}


void MainWindow::on_pre_clicked()
{
    auto itemIndex=ui->music_list->currentRow();
    QListWidgetItem *nextItem;
    if(itemIndex-1>-1)
        nextItem=ui->music_list->item(itemIndex-1);
    else
        return;
    on_music_list_itemDoubleClicked(nextItem);
}

