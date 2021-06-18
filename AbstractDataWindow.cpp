#include "AbstractDataWindow.h"
#include "ui_AbstractDataWindow.h"

AbstractDataWindow::AbstractDataWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AbstractDataWindow)
{
    ui->setupUi(this);
    this->db = db;
    this->nameTableDb = nameTableDb;
    this->namesColumn = namesColumn;

    tab = new QSqlTableModel(this, db);
    tab->setTable(nameTableDb);
    tab->select();
    tab->setEditStrategy(QSqlTableModel::OnFieldChange);

    tableView = ui->tableView;
    tableView->setModel(tab);
    tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

    tableWidget = ui->tableWidget;
    tableWidget->setRowCount(1);
    tableWidget->setColumnCount(namesColumn.count());
    tableWidget->setHorizontalHeaderLabels(namesColumn);
    tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

AbstractDataWindow::~AbstractDataWindow()
{
    delete ui;
}

void AbstractDataWindow::on_pushButton_addRow_clicked()
{
    if(tableWidget->item(0, 0) == nullptr)
        return;

    QStringList list = getDataForWriting();
    insertToDb(nameTableDb, namesColumn, list);
    tab->select();
    clearTableWidget();
}

void AbstractDataWindow::on_pushButton_deleteRow_clicked()
{
    int row = tableView->currentIndex().row();
    tab->removeRow(row);
    tableView->hideRow(row);
}

QStringList AbstractDataWindow::getDataForWriting()
{
    QStringList list;
    for(int i = 0; i < namesColumn.count(); i++)
    {
        QTableWidgetItem *tabWdgItem = tableWidget->item(0, i);
        if(tabWdgItem != nullptr)
            list.append(tabWdgItem->text());
        else
            list.append("");
    }
    return list;
}

void AbstractDataWindow::clearTableWidget()
{
    for(int i = 0; i < namesColumn.count(); i++)
    {
        QTableWidgetItem *tabWdgItem = tableWidget->item(0, i);
        if((tabWdgItem != nullptr))
            tabWdgItem->setText("");
    }
}

void AbstractDataWindow::updateToDb(QString nameTable, QString nameCol, QString data, QString idCol, QString nameRow)
{
    QString queryStr = "UPDATE " + nameTable + " SET " + nameCol + " = '" + data + "' WHERE " + idCol + " = '"  + nameRow + "';";
    QSqlQuery query(db);
    if(query.exec(queryStr))
        qDebug("Данные успешно записаны");
    else
        qDebug("Данные не сохранены");
}

void AbstractDataWindow::insertToDb(QString nameTable, QStringList params, QStringList values)
{
    QString queryStr = "INSERT INTO " + nameTable + " (";
    foreach(QString str, params)
    {
        queryStr += "'" + str + "',";
    }
    queryStr.remove(queryStr.length() - 1, 1);
    queryStr += ") VALUES(";
    foreach(QString str, values)
    {
        queryStr += "'" + str + "',";
    }
    queryStr.remove(queryStr.length() - 1, 1);
    queryStr += ");";
    QSqlQuery query(db);
    query.exec(queryStr);
}

QString AbstractDataWindow::getDataFromDb(QString nameTable, QString nameField, QString nameCol, QString valCol)
{
    QString str;
    QSqlQuery query("SELECT " + nameField + " FROM " + nameTable + " WHERE " + nameCol + " = '" + valCol + "';");
    if(query.next())
    {
        str = query.value(0).toString();
    }
    return str;
}

QStringList AbstractDataWindow::getDataFromDb(QString nameTable, QString nameField)
{
    QStringList list;
    QSqlQuery query("SELECT " + nameField + " FROM " + nameTable + ";");

    while (query.next())
        list.append(query.value(0).toString());

    return list;
}
