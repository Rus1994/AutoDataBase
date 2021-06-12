#include "AutoDataBase.h"
#include "ui_AutoDataBase.h"

AutoDataBase::AutoDataBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AutoDataBase)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Zhelo/Documents/GitHubPrj/AutoDataBase/AutoDataBase.db");
    if(db.open())
        qDebug("Open");
    else
        qDebug("Not open");

    tab = new QSqlTableModel(this, db);
    tab->setTable("Cars");
    tab->select();

    ui->tableView->setModel(tab);

}

AutoDataBase::~AutoDataBase()
{
    db.close();
    delete ui;
}

