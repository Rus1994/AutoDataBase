#include "OwnersWindow.h"

OwnersWindow::OwnersWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent) : AbstractDataWindow(db,nameTableDb,namesColumn, parent)
{
    this->setWindowTitle("Владельцы");
}
