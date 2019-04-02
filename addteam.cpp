#include "addteam.h"
#include "ui_addteam.h"

AddTeam::AddTeam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTeam)
{
    ui->setupUi(this);
}

QString AddTeam::getName() const
{
    return Name;
}

AddTeam::~AddTeam()
{
    delete ui;
}

void AddTeam::on_confirm_clicked()
{
    if(!ui->teamName->text().isEmpty())
    {
        Name = ui->teamName->text();
        ui->teamName->clear();
        emit newTeam();
    }
}

void AddTeam::on_cancel_clicked()
{
    emit deleteScreen();
    close();
}
