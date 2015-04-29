#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QLabel>
#include <QMouseEvent>

class ImageWidget : public QLabel
{
public:
    explicit ImageWidget(QImage &image, QWidget *parent=0);
    ~ImageWidget();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QImage getImage();
private:
    int x0,x1,y0,y1;
    QImage image;
};

#endif // IMAGEWIDGET_H
