#ifndef MODELSWINDOW_H
#define MODELSWINDOW_H
#include "AbstractDataWindow.h"

class ModelsCarsWindow : public AbstractDataWindow
{
public:
    ModelsCarsWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent = nullptr);

private:
    void initTableWidget();
    void clearTableWidget();
    QStringList getDataForWriting();

};

#endif // MODELSWINDOW_H
