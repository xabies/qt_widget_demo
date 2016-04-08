#ifndef CTACHOMETER_H
#define CTACHOMETER_H

#include <QWidget>

class CTachometer : public QWidget
{
    Q_OBJECT
public:
    explicit CTachometer(QWidget *parent = 0);

signals:

public slots:
    void update_widget();

private:
    void paintEvent(QPaintEvent *);
    float rotation;
};

#endif // CTACHOMETER_H
