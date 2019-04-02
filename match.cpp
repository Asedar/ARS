#include "match.h"

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

int Match::getTeam1ID() const
{
	return team1;
}

int Match::getTeam2ID() const
{
	return team2;
}

void Match::setTeam1Score(int score)
{
	team1Score = score;
}

void Match::setTeam2Score(int score)
{
	team2Score = score;
}

int Match::getTeam1Score() const
{
    return team1Score;
}

int Match::getTeam2Score() const
{
    return team2Score;
}

Match::Match(int ID, int Team1, int Team2, QString Team1Name, QString Team2Name)
    :id(ID), team1(Team1), team2(Team2), team1Name(Team1Name), team2Name(Team2Name)
{

}

