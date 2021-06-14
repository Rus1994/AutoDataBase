#ifndef OWNERSWINDOW_H
#define OWNERSWINDOW_H
#include "AbstractDataWindow.h"

class OwnersWindow : public AbstractDataWindow
{
public:
    OwnersWindow(QSqlDatabase &db, QString nameTableDb, QStringList namesColumn, QWidget *parent = nullptr);

private:
};

#endif // OWNERSWINDOW_H
