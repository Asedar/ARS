#ifndef ADDSCORE_H
#define ADDSCORE_H

#include <QDialog>

namespace Ui {
class AddScore;
}

class AddScore : public QDialog
{
    Q_OBJECT

public:
    explicit AddScore(int id, QString t1, QString t2, QWidget *parent = nullptr);
    ~AddScore();

	int getTeam1Score();
	int getTeam2Score();
	int getMatchID();

signals:
    void newScore();
    void deleteScreen();

private slots:
    void on_cancel_clicked();

    void on_ok_clicked();

private:
    Ui::AddScore *ui;
	int score1;
	int score2;
	int matchID;
};

#endif // ADDSCORE_H
