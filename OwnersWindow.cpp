#include "OwnersWindow.h"
// При записи в БД автоматически выставлять уникальный ID
OwnersWindow::OwnersWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent) : AbstractDataWindow(db,nameTableDb,namesColumn, parent)
{
    this->setWindowTitle("Владельцы");
}


