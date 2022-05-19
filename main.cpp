#include <QApplication>
#include <QPushButton>
#include "xo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XO W;
    W.show();
    return a.exec();
}
