#include "default_database.h"
extern QDir Appdir;

Default_Database::Default_Database()
{
    if(create_database_dir())
    {
#if DB_DEBUG
        qDebug()<<"Database directory is already present or created";

#endif
    }
    else
    {
#if DB_DEBUG
        qDebug()<<"directory is not created";

#endif
    }
    create_Flag_Database();
    read_value_from_flag_database();
    if(database_complete_flag.read_flag_from_Database == 0)
    {
//        Create_Product_Database();
//        Create_Report_Database();
        create_security_database();
    }
    else
    {
        qDebug()<<"database_complete_flag.read_flag_from_Database == 1 so Databases is already created";
    }

}
void Default_Database::connCloseFlag()
{
    QString connectionName=QSqlDatabase::database().connectionName();
#if DB_DEBUG

    qDebug()<<"connection name for flag"<<connectionName;
#endif

    FlagDb.removeDatabase(connectionName/*"dbproduct_data"*//*QSqlDatabase::defaultConnection*/);//2nd one give warning
    //to close database properly we have to give the proper file name,please see declaration part
    FlagDb.close();
}//end of void sqlite::connCloseProduct()
bool Default_Database::connOpenFlag()
{
    QString fileName = Appdir.absolutePath()+"/database/flag.db";
    FlagDb=QSqlDatabase::addDatabase("QSQLITE");
    FlagDb.setDatabaseName(fileName/*"/home/root/database/dbproduct_data.db"*/);

    if(!FlagDb.open()){
#if DB_DEBUG
        qDebug() << ("Failed to open Database for FlagDb");

#endif
        return false;
    }
    else{
#if DB_DEBUG
        qDebug() << "connection successed for FlagDb database";

#endif
        return true;
    }
}//end of bool sqlite::connOpenProduct()
void Default_Database::open_Flag_Database()
{
    if(connOpenFlag() == 0)
    {
        return;
    }
    else
    {
#if DB_DEBUG
        qDebug()<<" flag Database connected";

#endif
    }
}
void Default_Database::create_Flag_Database()
{
    open_Flag_Database();

#if DB_DEBUG
    qDebug()<<"start to creating Flag table";

#endif
    QString queryToExecuteToCreateFlagTable,sqlTableName;
    sqlTableName="Flag Details";
    queryToExecuteToCreateFlagTable="CREATE TABLE '""flagdetails""'("
                                    "databaseComplete INTEGER);";
    if(create_table(queryToExecuteToCreateFlagTable,sqlTableName))
    {
#if DB_DEBUG
        qDebug()<<" first time inserting database_complete_flag.successful_created_database_flag"<<database_complete_flag.successful_created_database_flag;

#endif
        update_calculate_value_into_flag_database();
    }
    else
    {
#if DB_DEBUG
        qDebug()<<"flag database is already present";

#endif
    }
#if DB_DEBUG
    qDebug()<<"end of creating flag table";

#endif

    connCloseFlag();
}
bool Default_Database::create_database_dir()
{
    QString  dirpath = Appdir.absolutePath()+"/database/";
    if (Appdir.exists(dirpath)){
#if DB_DEBUG
        qDebug() <<"Dir present";

#endif
        return true;
    }
    else
    {
        if(Appdir.mkdir("database"))
        {
#if DB_DEBUG
            qDebug() <<"Directory is created";

#endif
         return true;
        }
        else
        {
#if DB_DEBUG
            qDebug() <<"Directory not created";

#endif
            return false;
        }
    }
}


bool Default_Database::create_table(QString query,QString sqlTableName)
{
     QSqlQuery qry;
     qry.prepare(query);
    if(!(qry.exec()))
    {
#if DB_DEBUG
        qDebug()<<"error in creating "<< sqlTableName;

#endif
    return 0;
    }
    else
    {
#if DB_DEBUG
        qDebug()<<"successfully created "<< sqlTableName;

#endif
      return 1;
    }
}

void Default_Database::insert_value(QString query, QString sqlTableName)
{
    QSqlQuery qry;
   if(!(qry.exec(query)))
   {
#if DB_DEBUG
       qDebug()<<"error in inserting "<< sqlTableName;

#endif
   }
   else
   {
#if DB_DEBUG
       qDebug()<<"successfully inserted "<< sqlTableName;

#endif
   }
}

void Default_Database::update_calculate_value_into_flag_database()
{
    open_Flag_Database();
    QString q = "INSERT INTO flagdetails (databaseComplete)"
                " values(?)";
    QSqlQuery qry;
    qry.prepare(q);
    qry.addBindValue(database_complete_flag.successful_created_database_flag);
    if(qry.exec())
    {
#if DB_DEBUG
        qDebug()<<"value is inserted in flag details datbase"<<database_complete_flag.successful_created_database_flag;

#endif
    }
    else
    {
#if DB_DEBUG
        qDebug()<<"not inserted into flag details database";

#endif
    }
    connCloseFlag();
}

void Default_Database::read_value_from_flag_database()
{
    open_Flag_Database();
    QString q = "SELECT databaseComplete FROM flagdetails";
    QSqlQuery qry;
    qry.prepare(q);
    if(qry.exec())
    {
        while(qry.next())
        {
            database_complete_flag.read_flag_from_Database = qry.value(0).toBool();
#if DB_DEBUG
            qDebug()<<"database_complete_flag.read_flag_from_Database while reading from database"<<database_complete_flag.read_flag_from_Database;

#endif
        }
    }
    connCloseFlag();
}

void Default_Database::create_security_database()
{
    open_Security_Database();
    QString createTable , sqlTableName;
    sqlTableName="userinfo";
            createTable="create table '"+sqlTableName+"'(UserName,UserRole,UserPassword)";
            if(create_table(createTable,sqlTableName))
            {
                securityTableCreatedCounter++;
            }
            Security_flag.isDataInto_userInfo_table_complete=1;
            set_default_security_database_data(sqlTableName,securityTableCreatedCounter);
            connCloseSecurity();
            /****************************************************************************/
            //below two line has to be writen for last db creation
            database_complete_flag.read_flag_from_Database=anding_all_db_flags();
            update_calculate_value_into_flag_database();
            /*****************************************************************************/
}
bool Default_Database::connOpenSecurity()
{
    QString fileName = Appdir.absolutePath()+"/database/security_data.db";
    SecurityDb=QSqlDatabase::addDatabase("QSQLITE");
    SecurityDb.setDatabaseName(fileName/*"/home/root/database/security_data.db"*/);

    if(!SecurityDb.open()){
#if DB_DEBUG

        qDebug() << ("Failed to open Database for Security");
#endif

        return false;
    }
    else{
#if DB_DEBUG

        qDebug() << "connection successed for product security";
#endif

        return true;
    }
}
void Default_Database::connCloseSecurity()
{
    QString connectionName=QSqlDatabase::database().connectionName();
#if DB_DEBUG
    qDebug()<<"connection name for profuct"<<connectionName;
#endif
    SecurityDb.removeDatabase(connectionName/*"dbproduct_data"*//*QSqlDatabase::defaultConnection*/);//2nd one give warning
    //to close database properly we have to give the proper file name,please see declaration part
    SecurityDb.close();
}

void Default_Database::open_Security_Database()
{
    if(connOpenSecurity() == 0)
    {
        return;
    }
    else
    {
#if DB_DEBUG
        qDebug()<<" Security Database connected";

#endif
    }
}//end of void sqlite::connCloseProduct()

void Default_Database::set_default_security_database_data(const QString& sqlTableName,quint8 secCounter)
{
#if DB_DEBUG
    qDebug()<<"sqlTableName_for_security_database"<<sqlTableName<<endl
           <<"counter"<<secCounter;
#endif
    QString InsertData;
    if(secCounter==1)
        InsertData="INSERT INTO '"+sqlTableName+"' (UserName,UserRole,UserPassword) VALUES('ADMIN','RAdmin','ELAB')";
    insert_value(InsertData,sqlTableName);
}
bool Default_Database::anding_all_db_flags()
{
#if DB_DEBUG
//    qDebug()<<"database_complete_flag.ProductDB_Complete" << database_complete_flag.ProductDB_Complete ;
//    qDebug()<<"product_Flags.isDataIntoDashboardTableComplete" <<product_Flags.isDataIntoDashboardTableComplete ;
//    qDebug()<<"product_Flags.isDataIntoProductTableComplete" <<product_Flags.isDataIntoProductTableComplete ;

//    qDebug()<<"database_complete_flag.ReportDb_Complete" << database_complete_flag.ReportDb_Complete ;
//    qDebug()<<"Report_flag.isDataInto_arm_A_report_Complete" << Report_flag.isDataInto_arm_A_report_Complete;
//    qDebug()<<"Report_flag.isDataInto_arm_B_report_Complete" << Report_flag.isDataInto_arm_B_report_Complete ;
//    qDebug()<<"Report_flag.isDataInto_arm_A_LogBook_Complete" << Report_flag.isDataInto_arm_A_LogBook_Complete ;

//    qDebug()<<"Report_flag.isDataInto_arm_B_LogBook_Complete" << Report_flag.isDataInto_arm_B_LogBook_Complete;
    qDebug()<<"Security_flag.isDataInto_userInfo_table_complete"<<Security_flag.isDataInto_userInfo_table_complete;
#endif


//    database_complete_flag.ProductDB_Complete =
//            product_Flags.isDataIntoDashboardTableComplete & product_Flags.isDataIntoProductTableComplete;

//    database_complete_flag.ReportDb_Complete=
//           Report_flag.isDataInto_arm_A_report_Complete & Report_flag.isDataInto_arm_B_report_Complete  &
//           Report_flag.isDataInto_arm_A_LogBook_Complete & Report_flag.isDataInto_arm_B_LogBook_Complete;

    database_complete_flag.SecurityDB_Complete=Security_flag.isDataInto_userInfo_table_complete;//each table has to be done anding

    database_complete_flag.successful_created_database_flag=database_complete_flag.SecurityDB_Complete;
           // database_complete_flag.ProductDB_Complete &  database_complete_flag.ReportDb_Complete;
#if DB_DEBUG
//    qDebug()<<"database_complete_flag.ProductDB_Complete" << database_complete_flag.ProductDB_Complete ;
//    qDebug()<<"product_Flags.isDataIntoDashboardTableComplete" <<product_Flags.isDataIntoDashboardTableComplete ;
//    qDebug()<<"product_Flags.isDataIntoProductTableComplete" <<product_Flags.isDataIntoProductTableComplete ;

//    qDebug()<<"database_complete_flag.ReportDb_Complete" << database_complete_flag.ReportDb_Complete ;
//    qDebug()<<"Report_flag.isDataInto_arm_A_report_Complete" << Report_flag.isDataInto_arm_A_report_Complete;
//    qDebug()<<"Report_flag.isDataInto_arm_B_report_Complete" << Report_flag.isDataInto_arm_B_report_Complete ;
//    qDebug()<<"Report_flag.isDataInto_arm_A_LogBook_Complete" << Report_flag.isDataInto_arm_A_LogBook_Complete ;

//    qDebug()<<"Report_flag.isDataInto_arm_B_LogBook_Complete" << Report_flag.isDataInto_arm_B_LogBook_Complete;


    qDebug()<<"result of anding" << database_complete_flag.successful_created_database_flag;
#endif

    return database_complete_flag.successful_created_database_flag;
}
