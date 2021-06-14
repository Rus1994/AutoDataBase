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
    ui->tableView->setModel(tab);
    ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

AbstractDataWindow::~AbstractDataWindow()
{
    delete ui;
}

void AbstractDataWindow::on_pushButton_addRow_clicked()
{
    tab->insertRow(tab->rowCount());
}

void AbstractDataWindow::on_pushButton_deleteRow_clicked()
{
    int row = ui->tableView->currentIndex().row();
    tab->removeRow(row);
    ui->tableView->hideRow(row);
}
