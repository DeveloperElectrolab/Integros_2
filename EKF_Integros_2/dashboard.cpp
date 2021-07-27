#include "dashboard.h"
#include "ui_dashboard.h"
#include<QDebug>
Dashboard::Dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::show_dashboard_page(QString username)
{
    this->show();
#if DASHBOARD_DEBUG
    qDebug()<<"Im showing Dashboard Page"<<username;
#endif
}
