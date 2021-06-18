#ifndef AUTODATABASE_H
#define AUTODATABASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>


QT_BEGIN_NAMESPACE
namespace Ui { class AutoDataBase; }
QT_END_NAMESPACE



class AutoDataBase : public QMainWindow
{
    Q_OBJECT

public:
    enum NameTable{
        FIRMS,
        CARS,
        OWNERS,
        MODELS
    };

    AutoDataBase(QWidget *parent = nullptr);
    ~AutoDataBase();

    static QString getNameTable(NameTable name);

private slots:

    void on_pushButton_ManufactFirm_clicked();

    void on_pushButton_Models_clicked();

    void on_pushButton_Cars_clicked();

    void on_pushButton_Owners_clicked();

private:
    Ui::AutoDataBase *ui;
    const QString FILE_NAME_DB = "../AutoDataBase/AutoDataBase.db";
    QMultiMap<QString, QStringList> fieldOfTables;
    QSqlDatabase db;

    void initialize();
    void checkTablesInDB();
    void createTableInDB(QString nameTable, QStringList namesColumn, QStringList sizeFields);

};
#endif // AUTODATABASE_H
