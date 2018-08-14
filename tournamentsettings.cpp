#include "tournamentsettings.h"
#include "ui_tournamentsettings.h"

TournamentSettings::TournamentSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TournamentSettings)
{
    ui->setupUi(this);
}

TournamentSettings::~TournamentSettings()
{
    delete ui;
}
