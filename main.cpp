#include "auroramonitor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auroramonitor w;
    w.show();

    return a.exec();
}
