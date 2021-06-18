#include "ModelsCarsWindow.h"
#include <QComboBox>

ModelsCarsWindow::ModelsCarsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent) : AbstractDataWindow(db,nameTableDb,namesColumn, parent)
{
    this->setWindowTitle("Модели");
    initTableWidget();
}

void ModelsCarsWindow::initTableWidget()
{
    QComboBox *comBox = new QComboBox();
    QStringList list = getDataFromDb(AutoDataBase::getNameTable(AutoDataBase::FIRMS), "Фирма");
    foreach(QString str, list)
        comBox->addItem(str);

    tableWidget->setCellWidget(0, 1, comBox);
}

void ModelsCarsWindow::clearTableWidget()
{
    for(int i = 0; i < namesColumn.count(); i++)
    {
        QTableWidgetItem *tabWdgItem = tableWidget->item(0, i);
        if((i != 1) && (tabWdgItem != nullptr))
            tabWdgItem->setText("");
    }
}

QStringList ModelsCarsWindow::getDataForWriting()
{
    QStringList list = AbstractDataWindow::getDataForWriting();
    QComboBox* cmBx = (QComboBox*)tableWidget->cellWidget(0,1);
    list[namesColumn.indexOf("Фирма")] = cmBx->currentText();
    return list;
}
