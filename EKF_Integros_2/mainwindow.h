#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDir>
#include <keyboard.h>
#include <login.h>
#include "default_database.h"
#include"dashboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void open_security_database();


    void close_security_database();

private:
    Ui::MainWindow *ui;
    Keyboard *pointer_to_keyboard_object = new Keyboard;
    Login *pointer_to_login_object = new Login;
    Default_Database *pointer_to_default_database = new Default_Database;
    Dashboard *pointer_to_dashboard_object = new Dashboard;
};

#endif // MAINWINDOW_H
