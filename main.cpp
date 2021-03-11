// #a0eb0c
#include "mainwindow.h"
#include <QFontDatabase>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/Roboto-Regular.ttf");
    MainWindow w;
    w.show();
    return a.exec();
}
