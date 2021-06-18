#ifndef CARSWINDOW_H
#define CARSWINDOW_H
#include "AbstractDataWindow.h"

class CarsWindow : public AbstractDataWindow
{
public:
    CarsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent = nullptr);

private slots:
    void changeSetOfComboBox(QString);
private:
    void initTableWidget();
    void clearTableWidget();
    QStringList getDataForWriting();

};

#endif // CARSWINDOW_H
