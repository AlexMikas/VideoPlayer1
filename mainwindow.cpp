#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    player = new QMediaPlayer;

    videoItem = new QGraphicsVideoItem;
    videoItem->setSize(QSizeF(640, 480));
    //videoItem->
    player->setVideoOutput(videoItem);
    scene->addItem(videoItem);

    QPixmap pixmap("../VideoPlayer2/src/picture.png");
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(pixmap.scaled(640, 480));
    scene->addItem(image);
    //player->play();
    QTimer::singleShot(0, this, SLOT(playVideo()));
}
void MainWindow::playVideo()
{
    QString foo("../VideoPlayer2/src/video2.mp4");
    play(QUrl(foo));
}
void MainWindow::play(QUrl url)
{
    player->setMedia(url);
}
MainWindow::~MainWindow()
{
    delete ui;
}
