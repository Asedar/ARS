#include "teamaddingscreen.h"
#include "ui_teamaddingscreen.h"

TeamAddingScreen::TeamAddingScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamAddingScreen)
{
    ui->setupUi(this);
}

TeamAddingScreen::~TeamAddingScreen()
{
    delete ui;
}

void TeamAddingScreen::on_cancel_clicked()
{
    emit deleteScreen();
    close();
}

void TeamAddingScreen::on_ok_clicked()
{
    Name = ui->teamName->text();
    ui->teamName->clear();
    emit newTeam();
}

QString TeamAddingScreen::getName() const
{
    return Name;
}
