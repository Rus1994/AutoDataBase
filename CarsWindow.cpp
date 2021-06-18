#include "CarsWindow.h"
#include "QComboBox"

CarsWindow::CarsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent) : AbstractDataWindow(db,nameTableDb,namesColumn, parent)
{
    this->setWindowTitle("Автомобили");
    initTableWidget();
}

void CarsWindow::changeSetOfComboBox(QString model)
{
    QComboBox *cmBx = (QComboBox*)tableWidget->cellWidget(0,2);
    cmBx->clear();
    QString firm = getDataFromDb(AutoDataBase::getNameTable(AutoDataBase::MODELS), "Фирма", "Модель", model);
    QString countries = getDataFromDb(AutoDataBase::getNameTable(AutoDataBase::FIRMS), "`Страны производства`", "Фирма", firm);
    QStringList list = countries.split(",");
    foreach(QString str, list)
        cmBx->addItem(str);
}

void CarsWindow::initTableWidget()
{
    QComboBox *comBoxModels = new QComboBox();
    QComboBox *comBoxCountry = new QComboBox();
    QStringList list = getDataFromDb(AutoDataBase::getNameTable(AutoDataBase::MODELS), "Модель");
    foreach(QString str, list)
        comBoxModels->addItem(str);
    tableWidget->setCellWidget(0, 1, comBoxModels);
    tableWidget->setCellWidget(0, 2, comBoxCountry);
    connect(comBoxModels, &QComboBox::currentTextChanged, this, &CarsWindow::changeSetOfComboBox);
}

void CarsWindow::clearTableWidget()
{
    for(int i = 0; i < namesColumn.count(); i++)
    {
        QTableWidgetItem *tabWdgItem = tableWidget->item(0, i);
        if((i != 1) && (i != 2) && (tabWdgItem != nullptr))
            tabWdgItem->setText("");
    }
}

QStringList CarsWindow::getDataForWriting()
{
    QStringList list = AbstractDataWindow::getDataForWriting();
    QComboBox* cmBxModel = (QComboBox*)tableWidget->cellWidget(0,1);
    QComboBox* cmBxCountry = (QComboBox*)tableWidget->cellWidget(0,2);
    list[namesColumn.indexOf("Модель")] = cmBxModel->currentText();
    list[namesColumn.indexOf("Страна производства")] = cmBxCountry->currentText();
    return list;
}
