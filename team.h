#ifndef TEAM_H
#define TEAM_H

#include <QVector>
#include <QString>


class Team
{
private:
    int id;
    QString teamName;
    int score = 0;
    int smallPoints = 0;
    QVector<int> results;


public:
    Team(int ID, QString TeamName);
    QString getTeamName() const;
    int getId() const;
    void setId(int value);
    int getScore() const;
};

#endif // TEAM_H
