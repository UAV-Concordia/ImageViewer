#include "imageviewer.h"
#include <QVBoxLayout>


ImageViewer::ImageViewer(QImage &image, QWidget *parent)
    : QDialog(parent), canvas(new ImageWidget(image))
{
    QVBoxLayout *l = new QVBoxLayout(this);
    l->addWidget(canvas);
}

ImageViewer::~ImageViewer()
{
    delete canvas;
}

QImage ImageViewer::getImage(){
    return this->canvas->getImage();
}
