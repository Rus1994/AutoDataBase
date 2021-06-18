#include "AutoDataBase.h"
#include "ui_AutoDataBase.h"
#include "ManufactFirmsWindow.h"
#include "ModelsCarsWindow.h"
#include "CarsWindow.h"
#include "OwnersWindow.h"

AutoDataBase::AutoDataBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AutoDataBase)
{
    ui->setupUi(this);
    initialize();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(FILE_NAME_DB);

    if(db.open())
        qDebug("Open");
    else
        qDebug("Not open");
    checkTablesInDB();
}

AutoDataBase::~AutoDataBase()
{
    db.close();
    delete ui;
}

void AutoDataBase::on_pushButton_ManufactFirm_clicked()
{
    QString nameTable = getNameTable(FIRMS);
    ManufactFirmsWindow *wnd = new ManufactFirmsWindow(db, nameTable, fieldOfTables.values(nameTable).at(0));
    wnd->show();
}

void AutoDataBase::on_pushButton_Models_clicked()
{
    QString nameTable = getNameTable(MODELS);
    ModelsCarsWindow *wnd = new ModelsCarsWindow(db, nameTable, fieldOfTables.values(nameTable).at(0));

    wnd->show();
}

void AutoDataBase::on_pushButton_Cars_clicked()
{
    QString nameTable = getNameTable(CARS);
    CarsWindow *wnd = new CarsWindow(db, nameTable, fieldOfTables.values(nameTable).at(0));
    wnd->show();
}

void AutoDataBase::on_pushButton_Owners_clicked()
{
    QString nameTable = getNameTable(OWNERS);
    OwnersWindow *wnd = new OwnersWindow(db, nameTable, fieldOfTables.values(nameTable).at(0));
    wnd->show();
}

QString AutoDataBase::getNameTable(NameTable name)
{
    switch(name){
    case FIRMS:
        return "Firms";
    case MODELS:
        return "Models";
    case CARS:
        return "Cars";
    case OWNERS:
        return "Owners";
    }
}

void AutoDataBase::initialize() // Указываем таблицы и поля. # в начале поля, означает сделать его целочисленным
{
    fieldOfTables.insert(getNameTable(FIRMS), QString("15;15;100").split(";"));
    fieldOfTables.insert(getNameTable(FIRMS), QString("Фирма;Страна;Страны производства").split(";"));
    fieldOfTables.insert(getNameTable(MODELS), QString("15;15;0;15;0;0").split(";"));
    fieldOfTables.insert(getNameTable(MODELS), QString("Модель;Фирма;Год;Кузов;Кол-во дверей;Мощность").split(";"));
    fieldOfTables.insert(getNameTable(CARS), QString("0;15;15;0").split(";"));
    fieldOfTables.insert(getNameTable(CARS), QString("id;Модель;Страна производства;Год").split(";"));
    fieldOfTables.insert(getNameTable(OWNERS), QString("0;15;15;15").split(";"));
    fieldOfTables.insert(getNameTable(OWNERS), QString("id;Фамилия;Имя;Отчество").split(";"));

}

void AutoDataBase::checkTablesInDB()
{
    QStringList strL = db.tables();
    QList<QString> keys =  fieldOfTables.keys();
    foreach(QString nameTable, keys)
    {
        if(!strL.contains(nameTable))
        {
            QList<QStringList> val = fieldOfTables.values(nameTable);
            createTableInDB(nameTable, val.at(0), val.at(1));
        }
    }
}

void AutoDataBase::createTableInDB(QString nameTable, QStringList namesColumn, QStringList sizeFields)
{
    if(namesColumn.count() != sizeFields.count())
    {
        qDebug("Ошибка создания таблицы: размеры списков не равны");
        return;
    }

    bool isFirstField = true;
    QSqlQuery query(db);
    QString queryTemplate = "CREATE TABLE " + nameTable + " ( ";
    for(int i = 0; i < namesColumn.count(); i++)
    {
        if(sizeFields.at(i) == "0")
        {
            queryTemplate += "'" + namesColumn.at(i) + "'";
            if(isFirstField)
                queryTemplate += " INTEGER PRIMARY KEY AUTOINCREMENT,";
            else
                queryTemplate += " INTEGER,";
        }
        else
            queryTemplate += "'" + namesColumn.at(i) + "'" + " VARCHAR(" + sizeFields.at(i) + "),";

        isFirstField = false;
    }
    queryTemplate.remove(queryTemplate.length() - 1, 1); // удалить последнюю запятую
    queryTemplate += ");";
    query.exec(queryTemplate);
}
