#include "addscore.h"
#include "ui_addscore.h"

AddScore::AddScore(int id, QString t1, QString t2, QWidget *parent) :
    QDialog(parent), matchID(id),
    ui(new Ui::AddScore)
{
    ui->setupUi(this);
	ui->t1Name->setText(t1);
	ui->t2Name->setText(t2);
}

AddScore::~AddScore()
{
    delete ui;
}

int AddScore::getTeam1Score()
{
	return score1;
}

int AddScore::getTeam2Score()
{
	return score2;
}

int AddScore::getMatchID()
{
	return matchID;
}

void AddScore::on_cancel_clicked()
{
    emit deleteScreen();
    close();
}

void AddScore::on_ok_clicked()
{
    score1 = ui->s1->value();
    score2 = ui->s2->value();
    emit newScore();
	emit deleteScreen();
	close();
}
