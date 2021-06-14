#include "ModelsCarsWindow.h"

ModelsCarsWindow::ModelsCarsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent) : AbstractDataWindow(db,nameTableDb,namesColumn, parent)
{
    this->setWindowTitle("Модели");
}
