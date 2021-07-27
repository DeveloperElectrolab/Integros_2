#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#define DASHBOARD_DEBUG 1
namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = 0);
    ~Dashboard();
public slots:
void show_dashboard_page(QString username);
private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
