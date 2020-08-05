#include <QApplication>
#include <QSurfaceFormat>
#include <QDebug>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
//    format.setStencilBufferSize(8);
//    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
//    QSurfaceFormat::setDefaultFormat(format);

    Widget w;
    w.resize(600,400);
    w.show();

    return a.exec();
}
