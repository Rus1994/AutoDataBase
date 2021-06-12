#include "AutoDataBase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AutoDataBase w;
    w.show();
    return a.exec();
}
