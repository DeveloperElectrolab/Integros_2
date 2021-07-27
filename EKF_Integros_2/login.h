#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

#define LOGIN_DEBUG 1
namespace Ui {
class Login;
}
struct{
    QString loginUserName;
    QString loginPassword;
    QString loginUserRole;
    QString username_from_security_database;
    QString password_from_security_database;
}login_parameter;
class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

signals:
    void userNameButtonPressed(QString str);
    void PasswordButtonPressed(QString str);
    void go_to_dash_board_page(QString username);
    void open_security_database();
    void close_security_database();
public slots:
    void show_userName_on_login_label(QString userName);
    void show_password_on_login_label(QString password);
private slots:
    void on_toolButton_loginUserName_loginPage_2_clicked();

    void on_toolButton_loginPassword_loginPage_2_clicked();

    void on_toolButton_loginMain_loginPage_2_clicked();

private:
    Ui::Login *ui;
    QString loginUserName;

};

#endif // LOGIN_H
