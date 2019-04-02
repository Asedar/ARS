#include "teaminfo.h"
#include "ui_teaminfo.h"

TeamInfo::TeamInfo(QString name, QString wins, QString ties, QString losses, QString smallPoints) :
    ui(new Ui::TeamInfo)
{
    ui->setupUi(this);
    ui->teamName->setText(name);
    ui->wins->setText(wins);
    ui->ties->setText(ties);
    ui->losses->setText(losses);
    ui->smallPoints->setText(smallPoints);
}

TeamInfo::~TeamInfo()
{
    delete ui;
}

void TeamInfo::on_ok_clicked()
{
    emit deleteScreen();
    close();
}
