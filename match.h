#ifndef MATCH_H
#define MATCH_H

#include <QString>

class Match
{
private:
    int id;
    int team1;
    int team2;
    QString team1Name;
    QString team2Name;
    int team1Score = -1;
    int team2Score = -1;


public:
    Match(int ID, int Team1, int Team2, QString Team1Name, QString Team2Name);
    QString getTeam1Name() const;
    QString getTeam2Name() const;
    int getId() const;
	int getTeam1ID() const;
	int getTeam2ID() const;
	void setTeam1Score(int score);
	void setTeam2Score(int score);
	
    int getTeam1Score() const;
    int getTeam2Score() const;
};

#endif // MATCH_H
