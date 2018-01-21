#ifndef AURORAMONITOR_H
#define AURORAMONITOR_H
#include "filedownloader.h"
#include <QMainWindow>

namespace Ui {
class auroramonitor;
}

class auroramonitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit auroramonitor(QWidget *parent = 0);
    ~auroramonitor();

private:
    Ui::auroramonitor *ui;
    FileDownloader* allsky_;
    FileDownloader* kpIndex_;
    FileDownloader* auroraPixels_;
private slots:
    void on_getAllskyButton_clicked();
    void loadImage();

    void on_getKpButton_clicked();
    void displayKp();

    void on_getAuroraPixelsButton_clicked();
    void displayAuroraPixels();
};

#endif // AURORAMONITOR_H
