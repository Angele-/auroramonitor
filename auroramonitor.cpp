#include "auroramonitor.h"
#include "ui_auroramonitor.h"
#include "filedownloader.h"

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

void auroramonitor::loadImage()
{
 QPixmap buttonImage;
 buttonImage.loadFromData(m_pImgCtrl->downloadedData());
}

void auroramonitor::on_pushButton_clicked()
{
    QUrl imageUrl("http://www2.irf.se/allsky/LASTv2.JPG");
    m_pImgCtrl = new FileDownloader(imageUrl, this);
    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}
