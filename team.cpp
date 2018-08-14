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

Team::Team(int ID, QString TeamName)
    :id(ID), teamName(TeamName)
{

}
