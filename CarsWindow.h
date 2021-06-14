#ifndef CARSWINDOW_H
#define CARSWINDOW_H
#include "AbstractDataWindow.h"

class CarsWindow : public AbstractDataWindow
{
public:
    CarsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent = nullptr);

private:

};

#endif // CARSWINDOW_H
