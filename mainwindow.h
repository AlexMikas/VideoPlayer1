#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene * scene;
    QMediaPlayer * player;
    QGraphicsVideoItem * videoItem;

    void play(QUrl url);
public slots:
    void playVideo();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
