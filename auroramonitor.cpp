#include "auroramonitor.h"
#include "ui_auroramonitor.h"
#include "filedownloader.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDataStream>
#include <QString>

auroramonitor::auroramonitor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::auroramonitor)
{
    ui->setupUi(this);

}

auroramonitor::~auroramonitor()
{
    delete ui;
}

void auroramonitor::on_getAllskyButton_clicked()
{
    QUrl allskyUrl("http://www2.irf.se/allsky/LASTv2.JPG");
    allsky_ = new FileDownloader(allskyUrl, this);
    connect(allsky_, SIGNAL (downloaded()), this, SLOT (loadImage()));
}
void auroramonitor::loadImage()
{
 QPixmap buttonImage;
 buttonImage.loadFromData(allsky_->downloadedData());
 QGraphicsScene* scene = new QGraphicsScene;
 scene->addPixmap(buttonImage);

 ui->allskyGraphicsView->setScene(scene);
}

void auroramonitor::on_getKpButton_clicked()
{
    QUrl kpUrl("http://www2.irf.se/maggraphs/preliminary_real_time_k_index_15_minutes");
    kpIndex_ = new FileDownloader(kpUrl, this);
    connect(kpIndex_, SIGNAL (downloaded()), this, SLOT (displayKp()));
}
void auroramonitor::displayKp()
{
    QString kpString = QString::fromUtf8(kpIndex_->downloadedData());
    double kpvalue = kpString.toDouble();

    ui->lcdKp->display(kpvalue);
}


void auroramonitor::on_getAuroraPixelsButton_clicked()
{
    QUrl auroraPixelsUrl("http://www2.irf.se/maggraphs/preliminary_real_time_k_index.php");
    auroraPixels_ = new FileDownloader(auroraPixelsUrl, this);
    connect(auroraPixels_, SIGNAL(downloaded()), this, SLOT (displayAuroraPixels()));
}


void auroramonitor::displayAuroraPixels()
{

    QString pageContent = QString::fromUtf8(auroraPixels_->downloadedData());
    int percentPos = pageContent.indexOf("%");
    int leftOfPixels = pageContent.indexOf(">", percentPos-7);
    QString pixelstring = pageContent.mid(leftOfPixels+1, percentPos-leftOfPixels-1);

    double pixels = pixelstring.toDouble();
    ui->lcdAuroraPixels->display(pixels);
}
