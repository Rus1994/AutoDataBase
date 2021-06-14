#include "ManufactFirmsWindow.h"

ManufactFirmsWindow::ManufactFirmsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent) : AbstractDataWindow(db,nameTableDb,namesColumn, parent)
{
    this->setWindowTitle("Фирмы-производители");
}
