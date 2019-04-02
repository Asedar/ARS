#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QVector>

class Team
{
private:
    int id;
    QString teamName;
    int score = 0;
    int smallPoints = 0;
    int wins = 0;
    int ties = 0;
    int losses = 0;


public:
    Team(int ID, QString TeamName);
    QString getTeamName() const;
    int getId() const;
    void setId(int value);
    int getScore() const;
    void addWin();
    void addTie();
    void addLoss();
    int getWins() const;
    int getTies() const;
    int getLosses() const;
    void setSmallPoints(int value);
    void setScore(int value);
    int getSmallPoints() const;
};

#endif // TEAM_H
