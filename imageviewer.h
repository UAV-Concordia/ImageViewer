#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QDialog>
#include <QImage>
#include "imagewidget.h"


// Dialot use to display an image
class ImageViewer : public QDialog
{
    Q_OBJECT

public:
    ImageViewer(QImage &image, QWidget *parent = 0);
    ~ImageViewer();
    QImage getImage();

private:
    ImageWidget *canvas;
};

#endif // IMAGEVIEWER_H
