#ifndef TOURNAMENTSETTINGS_H
#define TOURNAMENTSETTINGS_H

#include <QDialog>

namespace Ui {
class TournamentSettings;
}

class TournamentSettings : public QDialog
{
    Q_OBJECT

public:
    explicit TournamentSettings(QWidget *parent = 0);
    ~TournamentSettings();

private:
    Ui::TournamentSettings *ui;
};

#endif // TOURNAMENTSETTINGS_H
