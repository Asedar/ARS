#ifndef ADDTEAM_H
#define ADDTEAM_H

#include <QDialog>
#include <QVector>
#include "team.h"

namespace Ui {
class AddTeam;
}

class AddTeam : public QDialog
{
    Q_OBJECT

public:
    explicit AddTeam(QWidget *parent = nullptr);
    QString getName() const;

    ~AddTeam();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

signals:
    void newTeam();
    void deleteScreen();

private:
    Ui::AddTeam *ui;
    QString Name;
};

#endif // ADDTEAM_H
