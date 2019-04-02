#ifndef TEAMINFO_H
#define TEAMINFO_H

#include <QDialog>

namespace Ui {
class TeamInfo;
}

class TeamInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TeamInfo(QString name, QString wins, QString ties, QString losses, QString smallPoints);
    ~TeamInfo();

private slots:
    void on_ok_clicked();
signals:
    void deleteScreen();

private:
    Ui::TeamInfo *ui;
};

#endif // TEAMINFO_H
