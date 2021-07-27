#ifndef DEFAULT_DATABASE_H
#define DEFAULT_DATABASE_H

#include <QtGlobal>
#include <QSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDebug>
#include <QDir>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

#define DB_DEBUG 1
struct {
    quint8 ProductDB_Complete : 1;
    quint8 SecurityDB_Complete : 1;

    quint8 ReportDB_Complete : 1;
    quint8 successful_created_database_flag :1;
    quint8 read_flag_from_Database :1;
}database_complete_flag;
struct
{
    quint8 isDataInto_userInfo_table_complete : 1;
}Security_flag;
class Default_Database
{
public:
    Default_Database();
    QSqlDatabase FlagDb=QSqlDatabase::database("dbFlag_data");
    QSqlDatabase SecurityDb=QSqlDatabase::database("dbSecurity_data");

public slots:
    bool create_table(QString query,QString sqlTableName);
    void insert_value(QString query,QString sqlTableName);

    void connCloseFlag();
    bool connOpenFlag();
    void open_Flag_Database();
    void create_Flag_Database();
    void update_calculate_value_into_flag_database();
    bool anding_all_db_flags();
    void read_value_from_flag_database();

    bool create_database_dir();
    void create_security_database();
    bool connOpenSecurity();
    void connCloseSecurity();
    void open_Security_Database();
    void set_default_security_database_data(const QString &sqlTableName,quint8 secCounter);


private:
 quint8 securityTableCreatedCounter=0;

};

#endif // DEFAULT_DATABASE_H
