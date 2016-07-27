#include "gifwidget.h"

//tool hide everything!
GifWidget::GifWidget(QWidget *parent) :
    QWidget(parent,Qt::FramelessWindowHint | Qt::WindowSystemMenuHint |Qt::WindowStaysOnBottomHint | Qt::Tool)
{    
    //get config from .gifwidget in ~/
    const QSettings settings(QString(configDir), QSettings::IniFormat);

    //get image location
    QString imageDir =settings.value("Image", "").toString();

    //label to draw on and gif animation
    QPointer<QLabel>label = new QLabel(this);
    QPointer<QMovie> movie = new QMovie(imageDir);

    //get Image size and discard image
    QImage* image= new QImage(imageDir);
    label->setFixedSize(image->size());
    delete image;

    //quitaction crtl+q closes widget
    QPointer<QAction> quitAction = new QAction(tr("Exit"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    addAction(quitAction);

    //get position setting and move widget
    int posx = settings.value("PositionX", "").toInt();
    int posy =settings.value("PositionY", "").toInt();
    move(posx,posy);

    //start the magic
    label->setMovie(movie);
    movie->start();
}
