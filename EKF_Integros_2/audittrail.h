#ifndef AUDITTRAIL_H
#define AUDITTRAIL_H

#include <QWidget>

namespace Ui {
class AuditTrail;
}

class AuditTrail : public QWidget
{
    Q_OBJECT

public:
    explicit AuditTrail(QWidget *parent = 0);
    ~AuditTrail();

private:
    Ui::AuditTrail *ui;
};

#endif // AUDITTRAIL_H
