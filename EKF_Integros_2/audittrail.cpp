#include "audittrail.h"
#include "ui_audittrail.h"

AuditTrail::AuditTrail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuditTrail)
{
    ui->setupUi(this);
}

AuditTrail::~AuditTrail()
{
    delete ui;
}
