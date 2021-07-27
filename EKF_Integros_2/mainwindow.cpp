#include "mainwindow.h"
#include "ui_mainwindow.h"
QDir Appdir(qApp->applicationDirPath());

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();
//    pointer_to_keyboard_object->show();
//    pointer_to_keyboard_object->show_IPSetterPage();
  //  pointer_to_keyboard_object->show();
    pointer_to_login_object->show();
    connect(pointer_to_login_object,SIGNAL(userNameButtonPressed(QString)),pointer_to_keyboard_object,SLOT(show_NameSetterPage(QString)));
    connect(pointer_to_keyboard_object,SIGNAL(send_login_user_name(QString)),pointer_to_login_object,SLOT(show_userName_on_login_label(QString)));
    connect(pointer_to_login_object,SIGNAL(PasswordButtonPressed(QString)),pointer_to_keyboard_object,SLOT(show_NameSetterPage(QString)));
    connect(pointer_to_keyboard_object,SIGNAL(send_login_password(QString)),pointer_to_login_object,SLOT(show_password_on_login_label(QString)));
    connect(pointer_to_login_object,SIGNAL(go_to_dash_board_page(QString)),pointer_to_dashboard_object,SLOT(show_dashboard_page(QString)));
//    connect(pointer_to_login_object,SIGNAL(open_security_database()),this,SLOT(open_security_database()));
//    connect(pointer_to_login_object,SIGNAL(close_security_database()),this,SLOT(close_security_database()));
}//end of mainwiondow constructor

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_security_database()
{
    pointer_to_default_database->open_Security_Database();
}

void MainWindow::close_security_database()
{
    pointer_to_default_database->connCloseSecurity();
}
