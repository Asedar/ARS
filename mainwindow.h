#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStandardItemModel>
#include "team.h"
#include "match.h"
#include "addscore.h"
#include "teaminfo.h"
#include "addteam.h"
#include <memory>
#include <docgenerator.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void newTeam();
    void newScore();

private slots:
    void on_addTeam_triggered();

    void on_startTournament_triggered();

    void on_matchView_doubleClicked(const QModelIndex &index);

    void on_generateSchedule_triggered();

    void on_teamView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    AddTeam *a;
    AddScore *b;
    TeamInfo *c;
    QVector<Team *> teams;
    QVector<Match *> matches;
    QStandardItemModel teamList;
    QStandardItemModel matchList;

    void randomizeTeams();
    void matchTeams();
    void updateTeamList();
    void updateMatchList();
	int findTeamIndex(int ID);
};

#endif // MAINWINDOW_H
