#ifndef FIRMSWINDOW_H
#define FIRMSWINDOW_H
#include "AbstractDataWindow.h"

class ManufactFirmsWindow : public AbstractDataWindow
{
public:
    ManufactFirmsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent = nullptr);

private:
};

#endif // FIRMSWINDOW_H
