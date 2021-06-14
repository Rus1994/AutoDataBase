#include "CarsWindow.h"

CarsWindow::CarsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent) : AbstractDataWindow(db,nameTableDb,namesColumn, parent)
{
    this->setWindowTitle("Автомобили");
}
