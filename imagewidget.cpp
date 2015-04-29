#include "imagewidget.h"
#include <QPixmap>
#include <QMessageBox>

ImageWidget::ImageWidget(QImage &image, QWidget *parent):
    QLabel(parent)
{
    this->setPixmap(QPixmap::fromImage(image));
    this->image = image;
}

ImageWidget::~ImageWidget()
{

}

inline void swap(int a, int b){
    int t = b;
    b = a;
    a = t;
}

void ImageWidget::mousePressEvent(QMouseEvent *event){
    this->x0 = event->x();
    this->y0 = event->y();
}

void ImageWidget::mouseReleaseEvent(QMouseEvent *event){
    this->x1 = event->x();
    this->y1 = event->y();

    // No area defined
    if(x0 == x1 || y0 == y1)
        return;

    // Confirmation dialog
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Crop", "Are you sure you want to crop?",
                                    QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        // Reorder variables
        if(x0 > x1) swap(x0, x1);
        if(y0 > y1) swap(y0, y1);

        // Crop
        int w = x1 -x0;
        int h = y1 -y0;
        this->image = this->image.copy(x0, y0, w, h);

        // Updating
        this->setPixmap(QPixmap::fromImage(this->image));
    }
}

QImage ImageWidget::getImage(){
    return this->image;
}
