#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QStandardItemModel>
#include "team.h"
#include "match.h"
#include "teamaddingscreen.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QVector<Team *> teams;
    QVector<Match *> matches;
    QStandardItemModel teamList;
    QStandardItemModel matchList;
    TeamAddingScreen *s;

    void randomizeTeams();
    void matchTeams();
    void updateTeamList();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void addTeam();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_help_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
