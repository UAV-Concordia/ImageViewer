#include "imageviewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViewer w(QImage("C:\\Users\\Public\\Pictures\\Sample Pictures\\Desert.jpg"));
    w.show();

    return a.exec();
}
