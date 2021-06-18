#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QTableWidget>
#include <AutoDataBase.h>

namespace Ui {
class AbstractDataWindow;
}

class AbstractDataWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractDataWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent = nullptr);
    ~AbstractDataWindow();

private slots:
    void on_pushButton_addRow_clicked();

    void on_pushButton_deleteRow_clicked();

protected:
    Ui::AbstractDataWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *tab;
    QString nameTableDb;
    QStringList namesColumn;
    QTableView *tableView;
    QTableWidget *tableWidget;

    void updateToDb(QString nameTable, QString nameCol, QString data, QString idCol, QString nameRow);
    void insertToDb(QString nameTable, QStringList params, QStringList values);
    QString getDataFromDb(QString nameTable, QString nameField, QString nameCol, QString valCol);
    QStringList getDataFromDb(QString nameTable, QString nameField);

    virtual void initTableWidget(){}
    virtual QStringList getDataForWriting();
    virtual void clearTableWidget();
};

#endif // ABSTRACTDATA_H
