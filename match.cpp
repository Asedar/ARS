#include "match.h"
#include "mainwindow.h"

QString Match::getTeam1Name() const
{
    return team1Name;
}

QString Match::getTeam2Name() const
{
    return team2Name;
}

int Match::getId() const
{
    return id;
}

Match::Match(int ID, int Team1, int Team2, QString Team1Name, QString Team2Name)
    :id(ID), team1(Team1), team2(Team2), team1Name(Team1Name), team2Name(Team2Name)
{

}
