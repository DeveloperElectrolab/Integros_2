#include "keyboard.h"
#include "ui_keyboard.h"
static quint8 space = 0;
quint16 shiftCounter=0;
bool sameUserName=0,alpha=0,numeric=0;
enum STACK_WIDGET_PAGE_SELECTION
{
    NAME_SETTER_PAGE= 0,
    TIME_SETTER_PAGE,
    RANGE_SETTER_PAGE,
    IP_SETTER_PAGE
};
Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);
/*************************************************************************/
    //this block is a constructor of keyboard class, whenever program start constructor is first one to execute,
    //so initialization has to be done here

    keyPressed_keyboard();
    numeric_keyboard();
    timer_keyboard();
    ip_keyboard();
/*************************************************************************/
}

Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::show_NameSetterPage(QString str)
{
#if KEYBOARD_DEBUG
    qDebug()<<"str"<<str;
    qDebug()<<"text_on_lineEdit_when_show_NameSetterPage_function_caller"<< ui->lineEdit_name_nameSetterPage_7->text();
#endif

    flag_for_emit=str;
    ui->lineEdit_name_nameSetterPage_7->clear();
    this->show();

    if(str == "username")
    {
        ui->label_SettingName_nameSettterPage_7->setText("Enter Login User Name") ;
    }
    else if(str == "password")
    {
        ui->label_SettingName_nameSettterPage_7->setText("Enter Login Password") ;

    }

    ui->stackedWidget->setCurrentIndex(NAME_SETTER_PAGE);
}
void Keyboard::show_TimeSetterPage()
{
     this->show();
    ui->stackedWidget->setCurrentIndex(TIME_SETTER_PAGE);
}
void Keyboard::show_RangeSetterPage()
{
     this->show();
    ui->stackedWidget->setCurrentIndex(RANGE_SETTER_PAGE);
}
void Keyboard::show_IPSetterPage()
{
     this->show();
    ui->stackedWidget->setCurrentIndex(IP_SETTER_PAGE);
}
void Keyboard::keyPressed_keyboard()
{
    connect ( ui->toolButton_Q_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_W_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_E_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_R_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_T_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_Y_nameSetterPAge_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_U_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_I_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_O_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_P_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );

    connect ( ui->toolButton_A_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_S_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_D_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_F_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_G_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_H_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_J_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_K_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_L_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );

    connect ( ui->toolButton_Z_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_X_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_C_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_V_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_B_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_N_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->toolButton_M_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );

    connect ( ui->toolButton_space_nameSetterPage_7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );

    outputText = "";
    ui->lineEdit_name_nameSetterPage_7->setFocus();
}//end of keyPressed_keyboard()

void Keyboard::numeric_keyboard()
{
    connect ( ui->toolButton_0_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_1_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_2_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_3_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_4_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_5_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_6_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_7_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_8_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_9_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );
    connect ( ui->toolButton_Decimal_rangeSetterPage_6, SIGNAL( clicked() ), this, SLOT( numerickeyboardHandler() ) );

    outputDigit = "";
    ui->lineEdit_Range_rangeSetterPage_6->setFocus();
}//end of numeric_keyboard()

void Keyboard::timer_keyboard()
{
    connect ( ui->toolButton_time_0_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_1_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_2_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_3_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_4_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_5_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_6_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_7_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_8_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );
    connect ( ui->toolButton_time_9_timeSetterPage_8, SIGNAL( clicked() ), this, SLOT( timerkeyboardHandler() ) );

    outputHour = "";
    outputMin = "";
    outputSec = "";
    //ui->lineEdit_hour->setFocus();
    //ui->lineEdit_minute->setFocus();
}//end of timer_keyboard

void Keyboard::ip_keyboard()
{
    connect ( ui->toolButton_ip_0_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_1_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_2_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_3_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_4_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_5_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_6_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_7_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_8_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );
    connect ( ui->toolButton_ip_9_ipAddressPage_9, SIGNAL( clicked() ), this, SLOT( ipkeyboardHandler() ) );

    outputIp  = "";
    outputIp2 = "";
    outputIp3 = "";
    outputIp4 = "";
    //ui->lineEdit_IP->setFocus();
}//end of ip_keyboard
void Keyboard::keyboardHandler()
{
#if KEYBOARD_DEBUG
    qDebug()<<"text_on_lineEdit_when_entering_keyboardHAndlre_slot"<< ui->lineEdit_name_nameSetterPage_7->text()<<endl
           <<"outputText_when_entering_keyboard_handler"<<outputText;
#endif
    QToolButton *button = (QToolButton *)sender();
    qDebug() << "pressed " << button->text();

    QString inputText = button->text();

    if(inputText == "Space")
    {
        if(alphanumeric_check)
        {
            space++;
        }
        outputText += " ";
    }
    else
    {
        if(alphanumeric_check)
        {
            if(((inputText >= 65) && (inputText <= 90) || (inputText >= 97) && (inputText <= 122)))
            {
                alpha = 1;
            }
            if((inputText >= 48) && (inputText <= 57))
            {
                numeric = 1;
            }
        }
        outputText += inputText;
    }
    qDebug() << "space" << space;
    ui->lineEdit_name_nameSetterPage_7->setText(outputText);
}//end of keyboardHandler()
void Keyboard::numerickeyboardHandler()
{
    QToolButton *button1 = (QToolButton *)sender();
    qDebug() << "Numeric Button pressed " << button1->text();

    QString inputDigit = button1->text();
    outputDigit += inputDigit;
    ui->lineEdit_Range_rangeSetterPage_6->setText(outputDigit);
}//end of numerickeyboardHandler()

void Keyboard::timerkeyboardHandler()
{
    QToolButton *button2 = (QToolButton *)sender();
   qDebug() << "pressed " << button2->text();

    if(ui->lineEdit_hour_timeSetterPage_8->hasFocus())
    {
        QString inputHour = button2->text();
        outputHour += inputHour;
        ui->lineEdit_hour_timeSetterPage_8->setText(outputHour);
    }
    else if(ui->lineEdit_minute_timeSetterPage_8->hasFocus())
    {
        QString inputMin = button2->text();
        outputMin += inputMin;
        ui->lineEdit_minute_timeSetterPage_8->setText(outputMin);
    }
    else if(ui->lineEdit_second_timeSetterPage_8->hasFocus())
    {
        QString inputSec = button2->text();
        outputSec += inputSec;
        ui->lineEdit_second_timeSetterPage_8->setText(outputSec);
    }
}//end of timerkeyboardHandler()

void Keyboard::ipkeyboardHandler()
{
    QToolButton *button3 = (QToolButton *)sender();
    ////qDebug() << "pressed " << button->text();

    if(ui->lineEdit_IP_1_ipAddressPage_9->hasFocus())
    {
        QString inputIp = button3->text();
        outputIp += inputIp;
        ui->lineEdit_IP_1_ipAddressPage_9->setText(outputIp);
    }
    else if(ui->lineEdit_IP_2_ipAddressPage_9->hasFocus())
    {
        QString inputIp2 = button3->text();
        outputIp2 += inputIp2;
        ui->lineEdit_IP_2_ipAddressPage_9->setText(outputIp2);
    }
    else if(ui->lineEdit_IP_3_ipAddressPage_9->hasFocus())
    {
        QString inputIp3 = button3->text();
        outputIp3 += inputIp3;
        ui->lineEdit_IP_3_ipAddressPage_9->setText(outputIp3);
    }
    else if(ui->lineEdit_IP_4_ipAddressPage_9->hasFocus())
    {
        QString inputIp4 = button3->text();
        outputIp4 += inputIp4;
        ui->lineEdit_IP_4_ipAddressPage_9->setText(outputIp4);
    }
}//end of ipkeyboardHandler()

void Keyboard::default_keyboard()
{
    ui->toolButton_shift_nameSetterPage_7->setText("abc");

    ui->toolButton_Q_nameSetterPage_7->setText("Q");
    ui->toolButton_W_nameSetterPage_7->setText("W");
    ui->toolButton_E_nameSetterPage_7->setText("E");
    ui->toolButton_R_nameSetterPage_7->setText("R");
    ui->toolButton_T_nameSetterPage_7->setText("T");
    ui->toolButton_Y_nameSetterPAge_7->setText("Y");
    ui->toolButton_U_nameSetterPage_7->setText("U");
    ui->toolButton_I_nameSetterPage_7->setText("I");
    ui->toolButton_O_nameSetterPage_7->setText("O");
    ui->toolButton_P_nameSetterPage_7->setText("P");

    ui->toolButton_A_nameSetterPage_7->setText("A");
    ui->toolButton_S_nameSetterPage_7->setText("S");
    ui->toolButton_D_nameSetterPage_7->setText("D");
    ui->toolButton_F_nameSetterPage_7->setText("F");
    ui->toolButton_G_nameSetterPage_7->setText("G");
    ui->toolButton_H_nameSetterPage_7->setText("H");
    ui->toolButton_J_nameSetterPage_7->setText("J");
    ui->toolButton_K_nameSetterPage_7->setText("K");
    ui->toolButton_L_nameSetterPage_7->setText("L");

    ui->toolButton_Z_nameSetterPage_7->setText("Z");
    ui->toolButton_X_nameSetterPage_7->setText("X");
    ui->toolButton_C_nameSetterPage_7->setText("C");
    ui->toolButton_V_nameSetterPage_7->setText("V");
    ui->toolButton_B_nameSetterPage_7->setText("B");
    ui->toolButton_N_nameSetterPage_7->setText("N");
    ui->toolButton_M_nameSetterPage_7->setText("M");

    shiftCounter = 0;
}//end of default_keyboard()

void Keyboard::on_toolButton_Ok_nameSetterPage_7_clicked()
{
#if KEYBOARD_DEBUG
    qDebug()<<"text_on_lineEdit"<< ui->lineEdit_name_nameSetterPage_7->text();
#endif
    ui->lineEdit_name_nameSetterPage_7->blockSignals(true);
    if(flag_for_emit == "username")
    {
        if(ui->label_SettingName_nameSettterPage_7->text() == "Enter Login User Name")
        {
            //
            set_login_user_name(ui->lineEdit_name_nameSetterPage_7->text());
            emit send_login_user_name(get_login_user_name());
        }
    }
    else if (flag_for_emit == "password")
    {
        if(ui->label_SettingName_nameSettterPage_7->text() == "Enter Login Password")
        {
            // ui->lineEdit_name_nameSetterPage_7->blockSignals(true);
            set_login_password(ui->lineEdit_name_nameSetterPage_7->text());
            ui->lineEdit_name_nameSetterPage_7->setEchoMode(QLineEdit::Normal);
            emit send_login_password(get_login_password());
        }
    }

    outputText="";
    ui->lineEdit_name_nameSetterPage_7->blockSignals(false);
    ui->lineEdit_name_nameSetterPage_7->clear();
    this->hide();
}

void Keyboard::set_login_password(QString password)
{
     login_det.loginPassword = password;
}
void Keyboard::set_login_user_name(QString userName)
{
    login_det.loginNameUser = userName;

}
QString Keyboard::get_login_user_name()
{
    return login_det.loginNameUser;
}
QString Keyboard::get_login_password()
{
     return login_det.loginPassword;
}
void Keyboard::on_toolButton_shift_nameSetterPage_7_clicked()
{
    shiftCounter++;
    if(shiftCounter == 1)
    {
        ui->toolButton_shift_nameSetterPage_7->setText("123");

        ui->toolButton_Q_nameSetterPage_7->setText("q");
        ui->toolButton_W_nameSetterPage_7->setText("w");
        ui->toolButton_E_nameSetterPage_7->setText("e");
        ui->toolButton_R_nameSetterPage_7->setText("r");
        ui->toolButton_T_nameSetterPage_7->setText("t");
        ui->toolButton_Y_nameSetterPAge_7->setText("y");
        ui->toolButton_U_nameSetterPage_7->setText("u");
        ui->toolButton_I_nameSetterPage_7->setText("i");
        ui->toolButton_O_nameSetterPage_7->setText("o");
        ui->toolButton_P_nameSetterPage_7->setText("p");

        ui->toolButton_A_nameSetterPage_7->setText("a");
        ui->toolButton_S_nameSetterPage_7->setText("s");
        ui->toolButton_D_nameSetterPage_7->setText("d");
        ui->toolButton_F_nameSetterPage_7->setText("f");
        ui->toolButton_G_nameSetterPage_7->setText("g");
        ui->toolButton_H_nameSetterPage_7->setText("h");
        ui->toolButton_J_nameSetterPage_7->setText("j");
        ui->toolButton_K_nameSetterPage_7->setText("k");
        ui->toolButton_L_nameSetterPage_7->setText("l");

        ui->toolButton_Z_nameSetterPage_7->setText("z");
        ui->toolButton_X_nameSetterPage_7->setText("x");
        ui->toolButton_C_nameSetterPage_7->setText("c");
        ui->toolButton_V_nameSetterPage_7->setText("v");
        ui->toolButton_B_nameSetterPage_7->setText("b");
        ui->toolButton_N_nameSetterPage_7->setText("n");
        ui->toolButton_M_nameSetterPage_7->setText("m");
    }
    else if(shiftCounter == 2)
    {
        ui->toolButton_shift_nameSetterPage_7->setText("ABC");

        ui->toolButton_Q_nameSetterPage_7->setText("1");
        ui->toolButton_W_nameSetterPage_7->setText("2");
        ui->toolButton_E_nameSetterPage_7->setText("3");
        ui->toolButton_R_nameSetterPage_7->setText("4");
        ui->toolButton_T_nameSetterPage_7->setText("5");
        ui->toolButton_Y_nameSetterPAge_7->setText("6");
        ui->toolButton_U_nameSetterPage_7->setText("7");
        ui->toolButton_I_nameSetterPage_7->setText("8");
        ui->toolButton_O_nameSetterPage_7->setText("9");
        ui->toolButton_P_nameSetterPage_7->setText("0");

        ui->toolButton_A_nameSetterPage_7->setText("-");
        ui->toolButton_S_nameSetterPage_7->setText("/");
        ui->toolButton_D_nameSetterPage_7->setText(":");
        ui->toolButton_F_nameSetterPage_7->setText(";");
        ui->toolButton_G_nameSetterPage_7->setText("(");
        ui->toolButton_H_nameSetterPage_7->setText(")");
        ui->toolButton_J_nameSetterPage_7->setText("#");
        ui->toolButton_K_nameSetterPage_7->setText("%");
        ui->toolButton_L_nameSetterPage_7->setText("_");

        ui->toolButton_Z_nameSetterPage_7->setText(".");
        ui->toolButton_X_nameSetterPage_7->setText(",");
        ui->toolButton_C_nameSetterPage_7->setText("?");
        ui->toolButton_V_nameSetterPage_7->setText("+");
        ui->toolButton_B_nameSetterPage_7->setText("*");
        ui->toolButton_N_nameSetterPage_7->setText("@");
        ui->toolButton_M_nameSetterPage_7->setText("!");
    }
    else
    {
        ui->toolButton_shift_nameSetterPage_7->setText("abc");

        ui->toolButton_Q_nameSetterPage_7->setText("Q");
        ui->toolButton_W_nameSetterPage_7->setText("W");
        ui->toolButton_E_nameSetterPage_7->setText("E");
        ui->toolButton_R_nameSetterPage_7->setText("R");
        ui->toolButton_T_nameSetterPage_7->setText("T");
        ui->toolButton_Y_nameSetterPAge_7->setText("Y");
        ui->toolButton_U_nameSetterPage_7->setText("U");
        ui->toolButton_I_nameSetterPage_7->setText("I");
        ui->toolButton_O_nameSetterPage_7->setText("O");
        ui->toolButton_P_nameSetterPage_7->setText("P");

        ui->toolButton_A_nameSetterPage_7->setText("A");
        ui->toolButton_S_nameSetterPage_7->setText("S");
        ui->toolButton_D_nameSetterPage_7->setText("D");
        ui->toolButton_F_nameSetterPage_7->setText("F");
        ui->toolButton_G_nameSetterPage_7->setText("G");
        ui->toolButton_H_nameSetterPage_7->setText("H");
        ui->toolButton_J_nameSetterPage_7->setText("J");
        ui->toolButton_K_nameSetterPage_7->setText("K");
        ui->toolButton_L_nameSetterPage_7->setText("L");

        ui->toolButton_Z_nameSetterPage_7->setText("Z");
        ui->toolButton_X_nameSetterPage_7->setText("X");
        ui->toolButton_C_nameSetterPage_7->setText("C");
        ui->toolButton_V_nameSetterPage_7->setText("V");
        ui->toolButton_B_nameSetterPage_7->setText("B");
        ui->toolButton_N_nameSetterPage_7->setText("N");
        ui->toolButton_M_nameSetterPage_7->setText("M");

        shiftCounter = 0;
    }
}//end of on_toolButton_shift_nameSetterPage_7_clicked()
