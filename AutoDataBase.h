#ifndef AUTODATABASE_H
#define AUTODATABASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery> // .exec("запросы, команды")
#include <QSqlTableModel>


QT_BEGIN_NAMESPACE
namespace Ui { class AutoDataBase; }
QT_END_NAMESPACE

class AutoDataBase : public QMainWindow
{
    Q_OBJECT

public:
    AutoDataBase(QWidget *parent = nullptr);
    ~AutoDataBase();

private:
    Ui::AutoDataBase *ui;
    QSqlDatabase db;
    QSqlTableModel *tab;
};
#endif // AUTODATABASE_H
