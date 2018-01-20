#ifndef AURORAMONITOR_H
#define AURORAMONITOR_H

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

private slots:
    void loadImage();
    void on_pushButton_clicked();
};

#endif // AURORAMONITOR_H
