#include "team.h"

QString Team::getTeamName() const
{
    return teamName;
}

int Team::getId() const
{
    return id;
}

void Team::setId(int value)
{
    id = value;
}

int Team::getScore() const
{
    return score;
}

void Team::addWin()
{
    wins++;
}

void Team::addTie()
{
    ties++;
}

void Team::addLoss()
{
    losses++;
}

int Team::getWins() const
{
    return wins;
}

int Team::getTies() const
{
    return ties;
}

int Team::getLosses() const
{
    return losses;
}

void Team::setSmallPoints(int value)
{
    smallPoints += value;
}

void Team::setScore(int value)
{
    score += value;
}

int Team::getSmallPoints() const
{
    return smallPoints;
}

Team::Team(int ID, QString TeamName)
    :id(ID), teamName(TeamName)
{

}
