#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include<QString>
#include<QtGlobal>
#include<QDebug>
#define KEYBOARD_DEBUG 1
struct
{
    QString loginNameUser;
    QString loginPassword;
}login_det;
namespace Ui {
class Keyboard;
}

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = 0);
    ~Keyboard();
signals:
    void send_login_user_name(QString userName);
    void send_login_password(QString password);
public slots:
    void show_NameSetterPage(QString str);

    void show_TimeSetterPage();
    void show_RangeSetterPage();
    void show_IPSetterPage();

    void keyPressed_keyboard();
    void numeric_keyboard();
    void timer_keyboard();
    void ip_keyboard();

    void keyboardHandler();
    void numerickeyboardHandler();
    void timerkeyboardHandler();
    void ipkeyboardHandler();

    void default_keyboard();
    void set_login_user_name(QString userName);
    void set_login_password(QString password);
    QString get_login_user_name();
    QString get_login_password();

private slots:
    void on_toolButton_Ok_nameSetterPage_7_clicked();
    void on_toolButton_shift_nameSetterPage_7_clicked();
private:
    Ui::Keyboard *ui;
    /*KeyBoard Parameters*/
        QString popup_outputText,outputText;
        QString outputHour,outputMin,outputSec,outputDigit,outputIp,outputIp2,outputIp3,outputIp4;
        bool alphanumeric_check,Save_Role_comment=0,special_char_flag=0,Save_User_comment=0,Secsetting_comment=0,
             settings_comment=0,Save_Reporttmpl_comment=0;
        bool reset_security_comment=0,security_status_comment=0,factory_reset_comment=0,audit_purge_comment=0,
             report_purge_comment=0,save_product_comment=0,delete_product_comment=0,delete_role_comment=0,
             delete_user_comment=0,delete_reporttmpl_comment=0,delete_reportclient_comment=0,
             delete_reportchild_comment=0;
        QString flag_for_emit;


};

#endif // KEYBOARD_H
