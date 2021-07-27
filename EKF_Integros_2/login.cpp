#include "login.h"
#include "ui_login.h"
#include "default_database.h"

#include<QSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include <QGraphicsBlurEffect>


enum STACK_WIDGET_PAGE_SELECTION
{
    LOGIN_PAGE= 0,

};
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_toolButton_loginUserName_loginPage_2_clicked()
{
    this->hide();
    emit userNameButtonPressed("username");
}
void  Login::show_userName_on_login_label(QString userName)
{
    ui->stackedWidget->setCurrentIndex(LOGIN_PAGE);

    this->show();
    ui->label_loginUserName_loginPage_2->setText(userName);
}

void Login::show_password_on_login_label(QString password)
{
    ui->stackedWidget->setCurrentIndex(LOGIN_PAGE);

    this->show();
    ui->label_loginPassword_loginPage_2->setText(password);
}

void Login::on_toolButton_loginPassword_loginPage_2_clicked()
{
    this->hide();
    emit PasswordButtonPressed("password");
}

void Login::on_toolButton_loginMain_loginPage_2_clicked()
{
    login_parameter.loginUserName=ui->label_loginUserName_loginPage_2->text();
    login_parameter.loginPassword=ui->label_loginPassword_loginPage_2->text();
#if LOGIN_DEBUG
    qDebug()<<"login_parameter.loginUserName"<<login_parameter.loginUserName<<endl
    <<"login_parameter.loginPassword"<<login_parameter.loginPassword;
#endif
    auto *db_object_in_login = new Default_Database;
    if(login_parameter.loginUserName == "" && login_parameter.loginPassword == "")
    {
        setGraphicsEffect(new QGraphicsBlurEffect);
        QMessageBox::warning(this,"User Name","Please Enter User Name and Password");
        if(QMessageBox::Yes)
             setGraphicsEffect({});
    }
    else if(login_parameter.loginUserName == "")
    {
        setGraphicsEffect(new QGraphicsBlurEffect);
        QMessageBox::warning(this,"User Name","Please Enter User Name");
        if(QMessageBox::Yes)
             setGraphicsEffect({});
    }
    else if(login_parameter.loginPassword == "")
    {
        setGraphicsEffect(new QGraphicsBlurEffect);
        QMessageBox::warning(this,"User Name","Please Enter password");
        if(QMessageBox::Yes)
             setGraphicsEffect({});
    }
    //emit open_security_database();
    db_object_in_login->open_Security_Database();
     QSqlQuery qry;
     QString executable,sqlTableName="userinfo";;
     executable="SELECT * FROM '"+sqlTableName+"' where UserName = '"+login_parameter.loginUserName+"'";
     qry.prepare(executable);
     if(qry.exec())
     {
#if LOGIN_DEBUG
         qDebug()<<"query_for_accessing_data_for_username_is_execute"<<login_parameter.loginUserName;
#endif
         while(qry.next())
         {
             quint8 q=0;
             login_parameter.loginUserName=qry.value(q++).toString();
             login_parameter.loginUserRole=qry.value(q++).toString();
             login_parameter.loginPassword=qry.value(q++).toString();
             q=0;
         }
     }
     else
     {
#if LOGIN_DEBUG
         qDebug()<<"query_for_accessing_data_for_username_is_not_execute"<<login_parameter.loginUserName<<endl
                ;
#endif
     }
#if LOGIN_DEBUG

    qDebug() <<"What_is_data_comming_from_security_database"<<endl
    <<"login_parameter.loginUserName"<<login_parameter.loginUserName<<endl
   <<"login_parameter.loginUserRole"<<login_parameter.loginUserRole<<endl
  <<"login_parameter.loginPassword"<<login_parameter.loginPassword;
#endif

    //emit close_security_database();
    db_object_in_login->connCloseSecurity();
    if(login_parameter.loginUserName == "ADMIN" && login_parameter.loginPassword == "ELAB" )
    {
#if LOGIN_DEBUG
        qDebug()<<"UserName_and_Password_is_correct";
#endif
        loginUserName=login_parameter.loginUserName;
        emit go_to_dash_board_page(loginUserName);
        this->hide();
    }
    delete db_object_in_login;

}
