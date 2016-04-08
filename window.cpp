#include "window.h"

CWindow::CWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800, 600);

    /*QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(Pal);
    show();*/
}

