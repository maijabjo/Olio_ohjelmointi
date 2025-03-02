#include "shakkikello.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    shakkikello w;
    w.show();
    return a.exec();
}
