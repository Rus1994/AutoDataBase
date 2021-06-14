#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>

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
};

#endif // ABSTRACTDATA_H
