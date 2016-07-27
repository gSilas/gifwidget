#include "gifwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GifWidget w;

    w.show();

    return a.exec();
}
