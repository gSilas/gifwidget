#ifndef GIFWIDGET_H
#define GIFWIDGET_H

//wall of includes
#include <QWidget>
#include <QtWidgets>
#include <QMovie>
#include <QLabel>
#include <QSettings>
#include <QString>
#include <QDir>

class GifWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GifWidget(QWidget *parent = 0);

private:
    //constant config directory
    const QString configDir = QDir::homePath() + "/.gifwidget/config.ini";
};

#endif // GIFWIDGET_H
