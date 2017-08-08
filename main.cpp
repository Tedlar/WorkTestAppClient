#include "appmain.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppMain app;
    return a.exec();
}
