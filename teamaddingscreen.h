#ifndef TEAMADDINGSCREEN_H
#define TEAMADDINGSCREEN_H

#include <QDialog>
#include <QVector>
#include <QString>

namespace Ui {
class TeamAddingScreen;
}

class TeamAddingScreen : public QDialog
{
    Q_OBJECT

public:
    explicit TeamAddingScreen(QWidget *parent = 0);
    ~TeamAddingScreen();

    QString getName() const;

signals:
    void newTeam();
    void deleteScreen();

private slots:
    void on_cancel_clicked();

    void on_ok_clicked();

private:
    Ui::TeamAddingScreen *ui;

    QString Name;
};

#endif // TEAMADDINGSCREEN_H
