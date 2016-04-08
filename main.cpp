#include <QApplication>
#include "window.h"
#include "tachometer.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 CWindow c_window;
 CTachometer c_tachometer(&c_window);

 c_tachometer.setFixedSize(300, 300);
 c_tachometer.move(50, 50);

 c_window.show();

 return app.exec();
}
