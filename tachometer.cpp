#include "tachometer.h"
#include <QPaintEvent>
#include <QDebug>
#include <QPainter>
#include <QTimer>


#define SBI_WIDTH 26
#define CSG_WIDTH 12

#define HOOK_WIDHT 10


CTachometer::CTachometer(QWidget *parent) :
    QWidget(parent),
    rotation(0)
{
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(Pal);
    show();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_widget()));
    timer->start(200);

}

void CTachometer::paintEvent(QPaintEvent *)
{
    int widget_width = size().width();
    int widget_height = size().height();



    QPainter painter_sbi(this);
    painter_sbi.setRenderHint(QPainter::Antialiasing);
    QPen pen_sbi(Qt::red);
    pen_sbi.setWidth(SBI_WIDTH);
    pen_sbi.setCapStyle(Qt::FlatCap);
    painter_sbi.setPen(pen_sbi);
    QRect rect2(SBI_WIDTH/2, SBI_WIDTH/2, widget_width - SBI_WIDTH, widget_height - SBI_WIDTH);
    painter_sbi.drawArc(rect2, 0, 16*50);




    QPainter painter_csg(this);
    painter_csg.setRenderHint(QPainter::Antialiasing);
    QPen pen_csg(Qt::blue);
    pen_csg.setWidth(CSG_WIDTH);
    pen_csg.setCapStyle(Qt::FlatCap);
    painter_csg.setPen(pen_csg);

    QRect rect_csg(CSG_WIDTH/2, CSG_WIDTH/2, widget_width - CSG_WIDTH, widget_height - CSG_WIDTH);
    painter_csg.drawArc(rect_csg, 50*16, 16*90);





    QPainter painter_hook(this);

    // xc and yc are the center of the widget's rect.
    qreal xc = width() * 0.5;
    qreal yc = height() * 0.5;

    painter_hook.setBrush(Qt::yellow);
    painter_hook.setPen(Qt::NoPen);
    painter_hook.setRenderHint(QPainter::Antialiasing);

    // translates the coordinate system by xc and yc
    painter_hook.translate(xc, yc);

    // then rotate the coordinate system
    painter_hook.rotate(40);

    // we need to move the rectangle that we draw by rx and ry so it's in the center.
    qreal rx = -(HOOK_WIDHT * 0.5);
    painter_hook.drawRect(QRect(rx, -yc, HOOK_WIDHT, SBI_WIDTH));

}


void CTachometer::update_widget()
{
    rotation++;
    this->update();
}
